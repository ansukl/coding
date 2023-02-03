#include "orienteeringmap.hh"

#include <string>
#include <iostream>
#include <iomanip>

OrienteeringMap::OrienteeringMap()
{

}

OrienteeringMap::~OrienteeringMap()
{
    // Poistetaan muistissa olevat tietorakenteet ja oliot.
    for (auto &data : routes_) {
        delete data.second;
    }

    for (auto &data : points_) {
        delete data.second;
    }
}

void OrienteeringMap::set_map_size(int width, int height)
{
    width_ = width;
    height_ = height;
}

void OrienteeringMap::add_point(std::string name, int x, int y, int height,
                                char marker)
{
    // Tallennetaan uusi rasti tietorakenteeseen, jos sitä ei ole vielä
    // olemassa.
    if (points_.find(name) == points_.end()) {
        Point *point_ptr = new Point();
        point_ptr->name = name;
        point_ptr->x = x;
        point_ptr->y = y;
        point_ptr->z = height;
        point_ptr->marker = marker;

        points_[name] = point_ptr;
    }
}

bool OrienteeringMap::connect_route(std::string from, std::string to,
                                    std::string route_name)
{
    // Jos jompi kumpi annetuista rasteista ei löydy tietorakenteesta,
    // palautetaan false.
    if ((points_.find(from) == points_.end())
        || (points_.find(to) == points_.end())) {
        return false;
    }

    Point *from_point = points_.at(from);
    Point *to_point = points_.at(to);

    Route *route_ptr = nullptr;

    // Jos reittiä ei ole olemassa, luodaan uusi reittiolio. Muuten käytetään
    // tietorakenteesta löytynyttä reittioliota.
    if (routes_.find(route_name) == routes_.end()) {
        route_ptr = new Route();
        routes_[route_name] = route_ptr;
    } else {
        route_ptr = routes_.at(route_name);
    }

    return route_ptr->connect_points(from_point, to_point);
}

void OrienteeringMap::print_map() const
{
    int x = 0;
    int y = 1;

    // Tulostetaan kartan ensimmäinen rivi.
    while (x <= width_) {
        if (x == 0) {
            std::cout << " ";
        } else if (x > 9) {
            std::cout << " " << x;
        } else {
            std::cout << "  " << x;
        }
        x++;
    }

    std::cout << std::endl;

    // Tulostetaan kartta rivi kerrallaan.
    while (y <= height_) {
        if (y < 10) {
            std::cout  << " " << y;

            x = 0;
            while (x <= width_) {
                if (x > 0) {

                    // Tarkistetaan find_coordinates-metodilla, pitääkö
                    // tulostaa piste vai rastin tunnus.
                    find_coordinates(x, y);
                }
                x++;
            }
            std::cout << std::endl;

        }

        // Muotoillaan kartan tulostus oikein, kun rivinumero on kaksi-
        // numeroinen.
        else if (y >= 10) {
            std::cout << y;

            x = 0;
            while (x <= width_) {
                if (x > 0) {
                    find_coordinates(x, y);
                }
                x++;
            }
            std::cout << std::endl;
        }
        y++;
    }
}

void OrienteeringMap::print_routes() const
{
    std::cout << "Routes:" << std::endl;

    // Iteroidaan tietorakenne läpi ja tulostetaan reittien nimet.
    for (auto &data : routes_) {
        std::cout << " - " << data.first << std::endl;
    }
}

void OrienteeringMap::print_points() const
{
    std::cout << "Points:" << std::endl;

    // Iteroidaan tietorakenne läpi ja tulostetaan rastien nimet.
    for (auto &data : points_) {
        std::cout << " - " << data.first << " : " << data.second->marker
                  << std::endl;
    }
}

void OrienteeringMap::print_route(const std::string &name) const
{
    // Jos reitti löytyy tietorakenteesta, tulostetaan reitin rastien nimet.
    if (routes_.find(name) == routes_.end()) {
        std::cout << "Error: Route named " << name << " can't be found"
                  << std::endl;
    } else {
        routes_.at(name)->print_route_points();
    }
}

void OrienteeringMap::route_length(const std::string &name) const
{
    // Jos reitti löytyy tietorakenteesta, tulostetaan reitin kokonaispituus.
    if (routes_.find(name) == routes_.end()) {
        std::cout << "Error: Route named " << name << " can't be found"
                  << std::endl;
    } else {
        double length = routes_.at(name)->get_length();

        std::cout << std::setprecision(2) << "Route " << name
                  << " length was " << length << std::endl;
    }
}

void OrienteeringMap::greatest_rise(const std::string &point_name) const
{
    // Jätetään toteuttamattoman metodin parametri huomiotta.
    (void)point_name;
}

void OrienteeringMap::find_coordinates(int x, int y) const
{
    // Iteroidaan rastit läpi ja tarkistetaan, onko nykyisessä koordinaatissa
    // rastia.
    for (auto &data : points_) {
        if (data.second->x == x && data.second->y == y) {
            std::cout << "  " << data.second->marker;
            return;
        }
    }

    std::cout << "  .";
}
