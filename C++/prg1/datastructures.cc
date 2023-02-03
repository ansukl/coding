// Datastructures.cc
//
// Student name: Anna Kleemola
// Student email: anna.kleemola@tuni.fi
// Student number: K431687

#include "datastructures.hh"

#include <random>

#include <cmath>

#include <iostream>

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
