#include <cstdlib>
#include <iostream>
#include <vector>


void read_integers(std::vector< int >& ints, int count)
{
    int new_integer = 0;
    for(int i = 0; i < count; ++i)
    {
        std::cin >> new_integer;
        ints.push_back(new_integer);
    }
}

bool same_values(const std::vector<int>& ints)
{
    bool same = true;
    int last = ints.back();
    for ( int vektorin_alkio : ints ) {
        if (vektorin_alkio != last) {
            same = false;
            break;
        }
    } return same;
}

bool is_ordered_non_strict_ascending(const std::vector<int>& ints)
{
    bool asc = true;
    int first = ints.front();
    for ( int vektorin_alkio : ints ) {
        if (vektorin_alkio < first) {
            asc = false;
            break;
        }
    } return asc;
}

bool is_arithmetic_series(const std::vector<int>& ints)
{
    bool arth = true;
    int first = ints.front();
    int sub = ints.at(1) - first;
    for ( unsigned long long i = 2; i < ints.size(); ++i ) {
        if (ints.at(i) - first != sub * (int)i) {
           arth = false;
           break;
        }
    } return arth;
}

bool is_geometric_series(const std::vector<int>& ints)
{
    if (ints.at(0) == 0 && ints.at(1) == 0) {
        return false;
    }

    bool geo = true;
    int ratio = ints.at(1) / ints.at(0);
    int prev = ints.at(1);
    for ( unsigned long long i = 2; i < ints.size(); ++i ) {
        if (ints.at(i) / prev != ratio) {
           geo = false;
           break;
        } prev = ints.at(i);
    } return geo;
}


int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);

    if(same_values(integers))
        std::cout << "All the integers are the same" << std::endl;
    else
        std::cout << "All the integers are not the same" << std::endl;

    if(is_ordered_non_strict_ascending(integers))
        std::cout << "The integers are in a non-strict ascending order" << std::endl;
    else
        std::cout << "The integers are not in a non-strict ascending order" << std::endl;

    if(is_arithmetic_series(integers))
        std::cout << "The integers form an arithmetic series" << std::endl;
    else
        std::cout << "The integers do not form an arithmetic series" << std::endl;

    if(is_geometric_series(integers))
        std::cout << "The integers form a geometric series" << std::endl;
    else
        std::cout << "The integers do not form a geometric series" << std::endl;

    return EXIT_SUCCESS;
}
