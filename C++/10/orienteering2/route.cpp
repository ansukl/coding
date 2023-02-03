#include "route.hh"

#include <iostream>
#include <cmath>

Route::Route()
{

}

Route::~Route()
{
    RoutePoint *temp1 = first_;
    RoutePoint *temp2 = nullptr;

    // Poistetaan muistissa olevat tietorakenteet.
    while(temp1 != nullptr) {
        temp2 = temp1->next;
        delete temp1;
        temp1 = temp2;
    }
}

bool Route::connect_points(Point* from, Point* to)
{
    RoutePoint *point_to = new RoutePoint;
    point_to->point_ptr = to;

    // Jos reitillä ei ole aikaisempaa rastia, luodaan reitille myös aloitus-
    // rasti.
    if (first_ == nullptr) {
        RoutePoint *point_from = new RoutePoint;
        point_from->point_ptr = from;

        // Linkitetään rastit toisiinsa ja asetetaan first_ osoittamaan
        // ensimmäiseen rastiin.
        first_ = point_from;
        point_from->next = point_to;
        point_to->next = nullptr;

    } else {
        RoutePoint *point = find_point(from->name);

        // Jos reitiltä ei löydy annettua edeltävää rastia, poistetaan
        // kohderastille luotu RoutePoint-tietorakenne.
        if (point == nullptr) {
            delete point_to;
            return false;
        }

        // Jos edeltävä rasti on reitin viimeinen, lisätään kohderasti suoraan
        // sen perään.
        if (point->next == nullptr) {
            point->next = point_to;
            point_to->next = nullptr;
        }

        // Lisätään kohderasti kahden olemassa olevan rastin väliin.
        else {
            RoutePoint *temp = point->next;
            point->next = point_to;
            point_to->next = temp;
        }
    }

    return true;
}

void Route::print_route_points()
{
    RoutePoint *temp = first_;

    // Iteroidaan linkitetyt tietorakenteet läpi ja tulostetaan rastin nimi.
    while(temp != nullptr) {
        if (temp == first_) {
            std::cout << temp->point_ptr->name << std::endl;
            temp = temp->next;
        } else {
            std::cout << " -> " << temp->point_ptr->name << std::endl;
            temp = temp->next;
        }
    }
}

double Route::get_length()
{
    double length = 0;
    RoutePoint *temp = first_;

    // Iteroidaan linkitetty tietorakenne läpi ja lasketaan calculate_distance-
    // metodin avulla rastien välisten etäisyyksien summa.
    while(temp != nullptr) {
        if (temp->next != nullptr) {
            length += calculate_distance(temp, temp->next);
        }
        temp = temp->next;
    }

    return length;
}

Route::RoutePoint *Route::find_point(std::string &name) const
{
    RoutePoint *temp = first_;

    // Etsitään tietorakenteista annetun nimistä rastia.
    while(temp != nullptr) {
        if (temp->point_ptr->name == name) {
            return temp;
        } else {
            temp = temp->next;
        }
    }

    return nullptr;
}

double Route::calculate_distance(RoutePoint *first, RoutePoint *second) const
{
    // Lasketaan x- ja y-koordinaattien erotusten toinen potenssi.
    double x = pow(first->point_ptr->x - second->point_ptr->x, 2);
    double y = pow(first->point_ptr->y - second->point_ptr->y, 2);

    return sqrt(x + y);
}
