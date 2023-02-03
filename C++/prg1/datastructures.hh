// Datastructures.hh
//
// Student name: Anna Kleemola
// Student email: anna.kleemola@tuni.fi
// Student number: K431687

#ifndef DATASTRUCTURES_HH
#define DATASTRUCTURES_HH

#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <limits>
#include <functional>
#include <exception>
#include <map>
#include <unordered_map>
#include <unordered_set>

// Types for IDs
using StationID = std::string;
using TrainID = std::string;
using RegionID = unsigned long long int;
using Name = std::string;
using Time = unsigned short int;

// Return values for cases where required thing was not found
StationID const NO_STATION = "---";
TrainID const NO_TRAIN = "---";
RegionID const NO_REGION = -1;
Name const NO_NAME = "!NO_NAME!";
Time const NO_TIME = 9999;

// Return value for cases where integer values were not found
int const NO_VALUE = std::numeric_limits<int>::min();


// Type for a coordinate (x, y)
struct Coord
{
    int x = NO_VALUE;
    int y = NO_VALUE;
};

// Example: Defining == and hash function for Coord so that it can be used
// as key for std::unordered_map/set, if needed
inline bool operator==(Coord c1, Coord c2) { return c1.x == c2.x && c1.y == c2.y; }
inline bool operator!=(Coord c1, Coord c2) { return !(c1==c2); } // Not strictly necessary

struct CoordHash
{
    std::size_t operator()(Coord xy) const
    {
        auto hasher = std::hash<int>();
        auto xhash = hasher(xy.x);
        auto yhash = hasher(xy.y);
        // Combine hash values (magic!)
        return xhash ^ (yhash + 0x9e3779b9 + (xhash << 6) + (xhash >> 2));
    }
};


// Example: Defining < for Coord so that it can be used
// as key for std::map/set
inline bool operator<(Coord c1, Coord c2)
{
    if (c1.y < c2.y) { return true; }
    else if (c2.y < c1.y) { return false; }
    else { return c1.x < c2.x; }
}

// Return value for cases where coordinates were not found
Coord const NO_COORD = {NO_VALUE, NO_VALUE};

// Type for a distance (in metres)
using Distance = int;

// Return value for cases where Distance is unknown
Distance const NO_DISTANCE = NO_VALUE;

// This exception class is there just so that the user interface can notify
// about operations which are not (yet) implemented
class NotImplemented : public std::exception
{
public:
    NotImplemented() : msg_{} {}
    explicit NotImplemented(std::string const& msg) : msg_{msg + " not implemented"} {}

    virtual const char* what() const noexcept override
    {
        return msg_.c_str();
    }
private:
    std::string msg_;
};


// This is the class you are supposed to implement

class Datastructures
{
public:
    Datastructures();
    ~Datastructures();

    // Estimate of performance: O(1)
    // Short rationale for estimate: Metodi .size() on vakioaikainen.
    unsigned int station_count();

    // Estimate of performance: O(n)
    // Short rationale for estimate: Metodi .clear() on lineaarinen ja for-loopit
    // käyvät koko tietorakenteen läpi, joten tehokkuus on aina n.
    void clear_all();

    // Estimate of performance: O(n)
    // Short rationale for estimate: Tietorakenne käydään läpi for-loopilla
    // kokonaan, joten tehokkuus on aina n.
    std::vector<StationID> all_stations();

    // Estimate of performance: O(n)
    // Short rationale for estimate: Pahimmassa tapauksessa .find()-metodi joutuu
    // käymään koko tietorakenteen läpi, jolloin tehokkuus on lineaarinen.
    bool add_station(StationID id, Name const& name, Coord xy);

    // Estimate of performance: O(n)
    // Short rationale for estimate: Pahimmassa tapauksessa .find()-metodi joutuu
    // käymään koko tietorakenteen läpi, jolloin tehokkuus on lineaarinen.
    Name get_station_name(StationID id);

    // Estimate of performance: O(n)
    // Short rationale for estimate: Pahimmassa tapauksessa .find()-metodi joutuu
    // käymään koko tietorakenteen läpi, jolloin tehokkuus on lineaarinen.
    Coord get_station_coordinates(StationID id);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance: O(n)
    // Short rationale for estimate: Tietorakenne käydään läpi for-loopilla
    // kokonaan, joten tehokkuus on aina n.
    std::vector<StationID> stations_alphabetically();

    // Estimate of performance: O(n log n)
    // Short rationale for estimate: Pahimmassa tapauksessa kaikki asemat ovat
    // samalla etäisyydellä ja huonoimmassa mahdollisessa järjestyksessä, jolloin
    // std::sort käy läpi kaikki asemat ja tehokkuus on n log n.
    std::vector<StationID> stations_distance_increasing();

    // Estimate of performance: O(n)
    // Short rationale for estimate: Pahimmassa tapauksessa .find()-metodi joutuu
    // käymään koko tietorakenteen läpi, jolloin tehokkuus on lineaarinen.
    StationID find_station_with_coord(Coord xy);

    // Estimate of performance: O(n)
    // Short rationale for estimate: Pahimmassa tapauksessa asemaa ei ole olemassa
    // tai asema löytyy viimeisenä, jolloin tehokkuus on lineaarinen.
    bool change_station_coord(StationID id, Coord newcoord);

    // Estimate of performance: O(n)
    // Short rationale for estimate: Pahimmassa tapauksessa .find()-metodi joutuu
    // käymään koko tietorakenteen läpi, jolloin tehokkuus on lineaarinen.
    bool add_departure(StationID stationid, TrainID trainid, Time time);

    // Estimate of performance: O(n)
    // Short rationale for estimate: Pahimmassa tapauksessa .find()-metodi joutuu
    // käymään koko tietorakenteen läpi, jolloin tehokkuus on lineaarinen.
    bool remove_departure(StationID stationid, TrainID trainid, Time time);

    // Estimate of performance: O(n log n)
    // Short rationale for estimate: Pahimmassa tapauksessa kaikki lähdöt ovat
    // samaan aikaan ja huonoimmassa mahdollisessa järjestyksessä, jolloin
    // std::sort käy läpi kaikki lähdöt ja tehokkuus on n log n.
    std::vector<std::pair<Time, TrainID>> station_departures_after(StationID stationid, Time time);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance: O(n)
    // Short rationale for estimate: Pahimmassa tapauksessa .find()-metodi joutuu
    // käymään koko tietorakenteen läpi, jolloin tehokkuus on lineaarinen.
    bool add_region(RegionID id, Name const& name, std::vector<Coord> coords);

    // Estimate of performance: O(n)
    // Short rationale for estimate: Tietorakenne käydään läpi for-loopilla
    // kokonaan, joten tehokkuus on aina n.
    std::vector<RegionID> all_regions();

    // Estimate of performance: O(n)
    // Short rationale for estimate: Pahimmassa tapauksessa .find()-metodi joutuu
    // käymään koko tietorakenteen läpi, jolloin tehokkuus on lineaarinen.
    Name get_region_name(RegionID id);

    // Estimate of performance: O(n)
    // Short rationale for estimate: Pahimmassa tapauksessa .find()-metodi joutuu
    // käymään koko tietorakenteen läpi, jolloin tehokkuus on lineaarinen.
    std::vector<Coord> get_region_coords(RegionID id);

    // Estimate of performance: O(n)
    // Short rationale for estimate: Pahimmassa tapauksessa .find()-metodi joutuu
    // käymään koko tietorakenteen läpi, jolloin tehokkuus on lineaarinen.
    bool add_subregion_to_region(RegionID id, RegionID parentid);

    // Estimate of performance: O(n)
    // Short rationale for estimate: Pahimmassa tapauksessa .find()-metodi joutuu
    // käymään koko tietorakenteen läpi, jolloin tehokkuus on lineaarinen.
    bool add_station_to_region(StationID id, RegionID parentid);

    // Estimate of performance: O(n)
    // Short rationale for estimate: Pahimmassa tapauksessa .find()-metodi tai
    // while-loop joutuu käymään koko tietorakenteen läpi, jolloin tehokkuus on
    // lineaarinen.
    std::vector<RegionID> station_in_regions(StationID id);

    // Non-compulsory operations

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<RegionID> all_subregions_of_region(RegionID id);

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<StationID> stations_closest_to(Coord xy);

    // Estimate of performance:
    // Short rationale for estimate:
    bool remove_station(StationID id);

    // Estimate of performance:
    // Short rationale for estimate:
    RegionID common_parent_of_regions(RegionID id1, RegionID id2);

private:
    // Add stuff needed for your class implementation here

    struct Region;

    // Tietorakenne, johon on tallennettu aseman tiedot.
    struct Station {
        StationID station_id;
        Name station_name;
        Coord station_location;
        double station_distance;

        std::map<Time, std::vector<TrainID>> departures;
        Region* station_region;
    };

    // Tietorakenne, johon on tallennettu alueen tiedot.
    struct Region {
        RegionID region_id;
        Name region_name;
        std::vector<Coord> region_location;

        std::unordered_set<Region*> subregions;
        Region* parent_region;

        std::unordered_set<Station*> region_stations;
    };

    typedef std::unordered_map<StationID, Station*> Stations;
    typedef std::unordered_map<RegionID, Region*> Regions;

    std::map<double, std::vector<Station*>> stations_distance_;
    std::unordered_map<Coord, StationID, CoordHash> station_coords_;

    Stations stations_;
    Regions regions_;
    std::map<Name, StationID> station_names_;

};

#endif // DATASTRUCTURES_HH
