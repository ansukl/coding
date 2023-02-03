/* Suunnistus
 *
 * Tiedoston nimi: route.hh
 *
 * Kuvaus:
 * Tiedostossa on määriteltynä Route-luokka, jonka pohjalta luodaan jokaiselle
 * reitille olio. Sisältää myös Point-tietorakenteen, johon tallennetaan
 * rastin tiedot.
 *
 * Ohjelman kirjoittaja
 * Nimi: Anna Kleemola
 * Opiskelijanumero: K431687
 *
 * */

#ifndef ROUTE_HH
#define ROUTE_HH

#include <string>

// Tietorakenne, johon on tallennettu rastin tiedot.
struct Point {
    std::string name;
    int x;
    int y;
    int z;
    char marker;
};


class Route
{
public:

    Route();
    ~Route();

    // Yhdistää kaksi rastia toisiinsa. Funktio saa parametreina kaksi Point-
    // tietorakennetta ja palauttaa totuusarvon yhdistämisen onnistumisen
    // perusteella.
    bool connect_points(Point *from, Point *to);

    // Tulostaa kaikki kyseisellä reitillä olevat rastit järjestyksessä.
    // Funktio ei tarvitse parametreja eikä palauta mitään.
    void print_route_points();

    // Laskee ja palauttaa kyseisen reitin kokonaispituuden.
    // Funktio ei tarvitse parametreja ja palauttaa reitin pituuden desimaali-
    // lukuna.
    double get_length();

private:

    // Tietorakenne, jolla rastit linkitetään toisiinsa reitin sisällä.
    struct RoutePoint {
        Point *point_ptr;
        RoutePoint *next;
    };

    RoutePoint *first_ = nullptr;

    // Etsii, onko rastia olemassa kyseisellä reitillä. Funktio saa parametrina
    // rastin nimen ja palauttaa joko osoittimen RoutePoint-tietorakenteeseen
    // tai nullptr-osoittimen, jos rastia ei ole olemassa.
    RoutePoint *find_point(std::string &name) const;

    // Laskee etäisyyden kahden rastin välillä. Funktio saa parametreina kaksi
    // RoutePoint-tietorakennetta ja palauttaa niiden välisen etäisyyden
    // desimaalilukuna.
    double calculate_distance(RoutePoint *first, RoutePoint *second) const;
};

#endif // ROUTE_HH
