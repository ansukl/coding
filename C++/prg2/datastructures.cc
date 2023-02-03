// Datastructures.cc
//
// Student name: Anna Kleemola
// Student email: anna.kleemola@tuni.fi
// Student number: K431687

#include "datastructures.hh"
#include <random>
#include <cmath>

std::minstd_rand rand_engine; // Reasonably quick pseudo-random generator

template <typename Type>
Type random_in_range(Type start, Type end)
{
    auto range = end-start;
    ++range;

    auto num = std::uniform_int_distribution<unsigned long int>(0, range-1)(rand_engine);

    return static_cast<Type>(start+num);
}

// Modify the code below to implement the functionality of the class.
// Also remove comments from the parameter names when you implement
// an operation (Commenting out parameter name prevents compiler from
// warning about unused parameters on operations you haven't yet implemented.)

Datastructures::Datastructures()
{
    // Write any initialization you need here
}

Datastructures::~Datastructures()
{
    // Write any cleanup you need here
    for (auto &data : stations_) {
        delete data.second;
    }
    for (auto &data : regions_) {
        delete data.second;
    }
    for (auto &data : trains_) {
        delete data.second;
    }
}

unsigned int Datastructures::station_count()
{
    // Palauttaa asemien määrän.
    return stations_.size();
}

void Datastructures::clear_all()
{
    for (auto &data : stations_) {
        delete data.second;
    }
    for (auto &data : regions_) {
        delete data.second;
    }

    // Tyhjentää käytetyt tietorakenteet.
    stations_.clear();
    regions_.clear();

    stations_distance_.clear();
    station_names_.clear();
    station_coords_.clear();
}

std::vector<StationID> Datastructures::all_stations()
{
    // Iteroidaan map-tietorakenne läpi ja tallennetaan asemien ID:t vektoriin.
    std::vector<StationID> station_ids;
    for (auto &data : stations_) {
        station_ids.push_back(data.first);
    }
    return station_ids;
}


bool Datastructures::add_station(StationID id, const Name& name,
                                 Coord xy)
{

    // Tallennetaan uusi asema tietorakenteeseen ja palautetaan true, jos asemaa
    // ei ole vielä olemassa.
    if (stations_.find(id) == stations_.end()) {
        Station *stat_ptr = new Station();
        stat_ptr->station_name = name;
        stat_ptr->station_location = xy;
        stat_ptr->station_id = id;

        stations_[id] = stat_ptr;
        stat_ptr->station_region = nullptr;
        station_coords_[xy] = id;

        // Lisätään aseman nimi erilliseen mappiin.
        station_names_[name] = id;

        // Lasketaan aseman etäisyys origosta ja lisätään etäisyys structiin
        // ja etäisyys ja id erilliseen map-tietorakenteeseen.
        double distance = std::sqrt(std::pow(xy.x, 2) + std::pow(xy.y, 2));
        stat_ptr->station_distance = distance;
        stations_distance_[distance].push_back(stat_ptr);

        return true;
    } else {
        return false;
    }
}

Name Datastructures::get_station_name(StationID id)
{
    // Palauttaa aseman nimen, jos annettu ID löytyy tietorakenteesta.
    if (stations_.find(id) == stations_.end()) {
        return NO_NAME;
    } else {
        return stations_[id]->station_name;
    }
}

Coord Datastructures::get_station_coordinates(StationID id)
{
    // Palauttaa aseman koordinaatit, jos annettu ID löytyy tietorakenteesta.
    if (stations_.find(id) == stations_.end()) {
        return NO_COORD;
    } else {
        return stations_[id]->station_location;
    }
}

std::vector<StationID> Datastructures::stations_alphabetically()
{
    std::vector<StationID> sorted_ids;
    for (auto &data : station_names_) {
        sorted_ids.push_back(data.second);
    }
    return sorted_ids;
}

std::vector<StationID> Datastructures::stations_distance_increasing()
{

    std::vector<StationID> sorted_distance;
    for (auto it = stations_distance_.begin(); it != stations_distance_.end();
         ++it) {

        // Vertaillaan ja järjestetään sellaisten asemien y-koordinaatit, jotka
        // ovat saman etäisyyden päässä origosta.
        std::sort(it->second.begin(), it->second.end(), [](Station* a,
                  Station* b){return a->station_location.y <
                    b->station_location.y;});

        // Lisätään uuteen vektoriin järjestetyt asemat.
        for (auto iter = it->second.begin(); iter != it->second.end();
             ++iter) {
            sorted_distance.push_back((*iter)->station_id);
        }
    }
    return sorted_distance;
}

StationID Datastructures::find_station_with_coord(Coord xy)
{


    std::unordered_map<Coord, StationID, CoordHash>::iterator it;
    it = station_coords_.find(xy);

    // Palautetaan aseman koordinaatit, jos ne löydetään tietorakenteesta.
    if (it == station_coords_.end()) {
        return NO_STATION;
    } else {
        return it->second;
    }
}

bool Datastructures::change_station_coord(StationID id, Coord newcoord)
{
    if (stations_.find(id) == stations_.end()) {
        return false;
    }

    // Lasketaan uusi etäisyys origosta, iteroidaan läpi tietyllä etäisyydellä
    // olevat asemat sisältävä vektori ja poistetaan annettu asema.
    else {
        double distance = std::sqrt(std::pow(newcoord.x, 2) + std::pow(newcoord.y, 2));
        for (auto it = stations_distance_[stations_[id]->station_distance].begin();
             it != stations_distance_[stations_[id]->station_distance].end(); it++) {
            if ((*it)->station_id == id) {
                stations_distance_[stations_[id]->station_distance].erase(it);
                break;
            }
        }

        // Päivitetään uusi etäisyys kaikkiin relevantteihin tietorakenteisiin.
        stations_distance_[distance].push_back(stations_[id]);

        auto node = station_coords_.extract(stations_[id]->station_location);
        node.key() = newcoord;
        station_coords_.insert(std::move(node));

        stations_[id]->station_location = newcoord;
        stations_[id]->station_distance = distance;

        return true;
    }
}

bool Datastructures::add_departure(StationID stationid, TrainID trainid,
                                   Time time)
{
    // Lisätään asemalle lähtö tietyllä kellonajalla, jos sitä ei ole vielä
    // olemassa.
    if (stations_.find(stationid) == stations_.end()) {
        return false;
    }

    // Tarkistetaan, onko lähtöaika olemassa.
    if (stations_[stationid]->departures.find(time) ==
            stations_[stationid]->departures.end()) {
        stations_[stationid]->departures[time].push_back(trainid);
        return true;
    }

    // Tarkistetaan, onko lisättävällä junalla jo lähtö annettuna kellonaikana.
    else {
        for (auto it = stations_[stationid]->departures[time].begin();
             it != stations_[stationid]->departures[time].end(); ++it) {
            if ((*it) == trainid) {
                return false;
            }
        }
        stations_[stationid]->departures[time].push_back(trainid);
        return true;
    }
}

bool Datastructures::remove_departure(StationID stationid, TrainID trainid,
                                      Time time)
{
    // Poistetaan asemalta lähtö tietyllä kellonajalla, jos se on olemassa.
    if (stations_.find(stationid) == stations_.end()) {
        return false;
    }

    // Tarkistetaan, onko lähtöaika olemassa.
    if (stations_[stationid]->departures.find(time) ==
            stations_[stationid]->departures.end()) {
        return false;
    }

    // Poistetaan junan ID, jos se löytyy tietorakenteesta.
    if (stations_[stationid]->departures.find(time) !=
            stations_[stationid]->departures.end()) {
        for (auto it = stations_[stationid]->departures[time].begin();
             it != stations_[stationid]->departures[time].end(); ++it) {
            if ((*it) == trainid) {
                stations_[stationid]->departures[time].erase(it);
                return true;
            }
        }
    }
    return false;
}

std::vector<std::pair<Time, TrainID>> Datastructures::station_departures_after(
        StationID stationid, Time time)
{

    std::vector<std::pair<Time, TrainID>> deps_after;

    // Tarkistetaan, onko asemaa olemassa.
    if (stations_.find(stationid) == stations_.end()) {
        deps_after.push_back(std::make_pair(NO_TIME, NO_TRAIN));
        return deps_after;
    }

    // Luodaan iteraattori, joka löytää alarajan mapista.
    std::map<Time, std::vector<TrainID>>::iterator it_low;
    it_low = stations_[stationid]->departures.lower_bound(time);

    // Iteroidaan tietorakenne läpi ja tallennetaan alarajan kanssa saman-
    // arvoiset ja yläpuolella olevat arvot vektoriin.
    for (auto it = it_low; it != stations_[stationid]->departures.end(); ++it) {
        std::sort(it->second.begin(), it->second.end());
        for (auto &data : it->second) {
            deps_after.push_back(std::make_pair(it->first, data));
        }
    } return deps_after;
}

bool Datastructures::add_region(RegionID id, const Name &name,
                                std::vector<Coord> coords)
{

    // Tallennetaan uusi alue ja palautetaan true, jos sitä
    // ei ole vielä olemassa.
    if (regions_.find(id) == regions_.end()) {
        Region *reg_ptr = new Region();
        reg_ptr->region_name = name;
        reg_ptr->region_location = coords;
        reg_ptr->region_id = id;

        regions_[id] = reg_ptr;
        reg_ptr->parent_region = nullptr;


        return true;
    } else {
        return false;
    }
}

std::vector<RegionID> Datastructures::all_regions()
{
    // Iteroidaan map-tietorakenne läpi ja tallennetaan alueiden ID:t vektoriin.
    std::vector<RegionID> region_ids;
    for (auto &data : regions_) {
        region_ids.push_back(data.first);
    }
    return region_ids;
}

Name Datastructures::get_region_name(RegionID id)
{
    // Palauttaa alueen nimen, jos annettu ID löytyy tietorakenteesta.
    if (regions_.find(id) == regions_.end()) {
        return NO_NAME;
    } else {
        return regions_[id]->region_name;
    }
}

std::vector<Coord> Datastructures::get_region_coords(RegionID id)
{
    // Palauttaa alueen koordinaatit, jos annettu ID löytyy tietorakenteesta.
    if (regions_.find(id) == regions_.end()) {
        std::vector<Coord> not_found = {NO_COORD};
        return not_found;
    } else {
        return regions_[id]->region_location;
    }
}

bool Datastructures::add_subregion_to_region(RegionID id, RegionID parentid)
{
    // Lisätään alialue, jos molemmat alueet on jo olemassa ja ale ei kuulu
    // vielä toiseen alueeseen.
    if (regions_.find(parentid) == regions_.end() or regions_.find(id) ==
            regions_.end()) {
        return false;
    }
    else if (regions_[id]->parent_region != nullptr) {
        return false;
    }

    // Lisätään alialue parent-alueen tietorakenteeseen ja alialueeseen tieto
    // parent-alueesta.
    else {
        regions_[parentid]->subregions.insert(regions_[id]);
        regions_[id]->parent_region = regions_[parentid];
        return true;
    }
}
bool Datastructures::add_station_to_region(StationID id, RegionID parentid)
{
    // Lisätään asema, jos alue ja asema on jo olemassa ja asema ei kuulu
    // vielä toiseen alueeseen.
    if (regions_.find(parentid) == regions_.end() or stations_.find(id) ==
            stations_.end()) {
        return false;
    }
    else if (stations_[id]->station_region != nullptr) {
        return false;
    }

    // Lisätään asema alueen tietorakenteeseen ja asemaan tieto
    // alueesta.
    else {
        regions_[parentid]->region_stations.insert(stations_[id]);
        stations_[id]->station_region = regions_[parentid];
        return true;
    }

}

std::vector<RegionID> Datastructures::station_in_regions(StationID id)
{

    // Palautetaan kaikki alueet, joilla asema sijaitsee, jos asema on olemassa
    // ja se sijaitsee jollakin alueella.
    if (stations_.find(id) == stations_.end()) {
        std::vector<RegionID> not_found = {NO_REGION};
        return not_found;
    }
    else if (stations_[id]->station_region == nullptr) {
        std::vector<RegionID> no_region = {};
        return no_region;
    }

    // Lisätään kaikkien asemaan liittyvien child- ja parent-alueiden id:t
    // vektoriin siihen asti, että saavutetaan ylin parent-alue.
    else {
        std::vector<RegionID> regions;
        Region* region = stations_[id]->station_region;
        while (region != nullptr) {
            regions.push_back(region->region_id);
            region = region->parent_region;
        }
        return regions;
    }
}

std::vector<RegionID> Datastructures::all_subregions_of_region(RegionID /*id*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("all_subregions_of_region()");
}

std::vector<StationID> Datastructures::stations_closest_to(Coord /*xy*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("stations_closest_to()");
}

bool Datastructures::remove_station(StationID /*id*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("remove_station()");
}

RegionID Datastructures::common_parent_of_regions(RegionID /*id1*/, RegionID /*id2*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("common_parent_of_regions()");
}

bool Datastructures::add_train(TrainID trainid, std::vector<std::pair<StationID, Time> > stationtimes)
{

    for (auto &data : stationtimes) {
        if (stations_.find(data.first) == stations_.end()) {
            return false;
        }
    }

    // Tallennetaan uusi juna tietorakenteeseen ja palautetaan true, jos junaa
    // ei ole vielä olemassa.
    if (trains_.find(trainid) == trains_.end()) {
        Train *train_ptr = new Train();
        train_ptr->train_id = trainid;
        train_ptr->train_stations = stationtimes;

        trains_[trainid] = train_ptr;

        for (unsigned long int i = 0; i < stationtimes.size(); i++) {
            train_ptr->stations_route.push_back(stationtimes[i].first);
            stations_[stationtimes[i].first]->trains_through_station.push_back(trainid);

            // Linkataan seuraava asema nykyiseen asemaan.
            if (i != stationtimes.size()-1) {
                stations_[stationtimes[i].first]->linked_stations.push_back(stations_[stationtimes[i+1].first]);
            }
        }
        return true;
    } else {
        return false;
    }
}

std::vector<StationID> Datastructures::next_stations_from(StationID id)
{

    if (stations_.find(id) == stations_.end()) {
        std::vector<StationID> not_found = {NO_STATION};
        return not_found;
    }

    std::vector<StationID> next_stations;

    for (auto &station : stations_[id]->linked_stations) {
        next_stations.push_back(station->station_id);
    }

    return next_stations;
}

std::vector<StationID> Datastructures::train_stations_from(StationID stationid, TrainID trainid)
{
    if (stations_.find(stationid) == stations_.end() or trains_.find(trainid) == trains_.end()) {
        std::vector<StationID> not_found = {NO_STATION};
        return not_found;
    }

    // Tarkistetaan, meneekö juna aseman läpi.
    bool train_found = false;
    for (auto &data : stations_[stationid]->trains_through_station) {
        if  (data == trainid) {
            train_found = true;
        }
    }

    if (!train_found or trains_[trainid]->stations_route.back() == stationid) {
        std::vector<StationID> not_found = {NO_STATION};
        return not_found;
    }

    std::vector<StationID> stations_from;

    std::vector<StationID>::iterator it = std::find(trains_[trainid]->stations_route.begin(),
                                                    trains_[trainid]->stations_route.end(), stationid);

    // Kasvatetaan iteraattoria, jotta ei lisätä nykyistä asemaa vektoriin.
    it++;

    while (it != trains_[trainid]->stations_route.end()) {
        stations_from.push_back(*it);
        it++;
    }
    return stations_from;
}

void Datastructures::clear_trains()
{
    for (auto &data : trains_) {
        delete data.second;
    }

    for (auto &station : stations_) {
        station.second->linked_stations.clear();
        station.second->trains_through_station.clear();
    }

    trains_.clear();

}

bool Datastructures::recursive_function(std::vector<StationID> &path, std::vector<StationID> visited, Station* station_ptr, StationID destination) {

    // Tarkistetaan, onko nykyinen asema tavoiteasema.
    if (station_ptr->station_id == destination) {
        return true;
    }

    // Lisätään vektoriin nykyinen asema.
    visited.push_back(station_ptr->station_id);

    // Käydään rekursiivisesti läpi kaikki asemat, joissa ei ole vielä käyty.
    for (auto &ptr : station_ptr->linked_stations) {

        // Skipataan asema, jolla on jo käyty.
        if (std::find(visited.begin(), visited.end(), ptr->station_id) != visited.end()) {
            continue;
        }

        if (recursive_function(path, visited, ptr, destination)) {
            path.push_back(ptr->station_id);
            return true;
        }
    }
    return false;
}

std::vector<std::pair<StationID, Distance>> Datastructures::route_any(StationID fromid, StationID toid)
{

    // Tarkistetaan, onko asemia ja junaa olemassa.
    if (stations_.find(fromid) == stations_.end() or stations_.find(toid) == stations_.end()) {
        std::vector<std::pair<StationID, Distance>> not_found = {std::make_pair(NO_STATION, NO_DISTANCE)};
        return not_found;
    }

    if (!stations_[fromid]->trains_through_station.size()) {
        std::vector<std::pair<StationID, Distance>> not_found = {std::make_pair(NO_STATION, NO_DISTANCE)};
        return not_found;
    }

    std::vector<std::pair<StationID, Distance>> anyroute;
    std::vector<StationID> stations_path;
    std::vector<StationID> visited;

    Station* station_ptr = stations_[fromid];

    // Lisätään vektoriin lähtöasema ja etäisyydeksi 0.
    anyroute.push_back(std::make_pair(fromid, 0));
    int total_distance = 0;

    if (!recursive_function(stations_path, visited, station_ptr, toid)) {
        return {};
    }

    Coord prev_coord = stations_[fromid]->station_location;

    // Käydään vektori läpi käänteisessä järjestyksessä, koska rekursiivinen funktio
    // palauttaa asemat väärin päin.
    for (std::vector<StationID>::reverse_iterator i = stations_path.rbegin(); i != stations_path.rend(); i++) {
        double d = std::sqrt(
            std::pow(prev_coord.x - stations_[*i]->station_location.x, 2) +
            std::pow(prev_coord.y - stations_[*i]->station_location.y, 2)
        );

        total_distance += std::floor(d);

        anyroute.push_back(std::make_pair(*i, total_distance));

        // Tallennetaan muuttujaan aina edellisen aseman koordinaatit.
        prev_coord = stations_[*i]->station_location;
    }

    return anyroute;
}

std::vector<std::pair<StationID, Distance>> Datastructures::route_least_stations(StationID /*fromid*/, StationID /*toid*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("route_least_stations()");
}

std::vector<StationID> Datastructures::route_with_cycle(StationID /*fromid*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("route_with_cycle()");
}

std::vector<std::pair<StationID, Distance>> Datastructures::route_shortest_distance(StationID /*fromid*/, StationID /*toid*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("route_shortest_distance()");
}

std::vector<std::pair<StationID, Time>> Datastructures::route_earliest_arrival(StationID /*fromid*/, StationID /*toid*/, Time /*starttime*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("route_earliest_arrival()");
}
