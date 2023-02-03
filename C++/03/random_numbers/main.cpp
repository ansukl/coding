#include <iostream>
#include <random>
#include <string>

using namespace std;

void produce_random_numbers(unsigned int lower, unsigned int upper, default_random_engine& gen)
{
    uniform_int_distribution<int> distr(lower, upper);
    std::cout << "\nYour drawn random number is " << distr(gen) << std::endl;
}

int main()
{
    unsigned int lower_bound, upper_bound, seed_value;
    cout << "Enter a lower bound: ";
    cin >> lower_bound;
    cout << "Enter an upper bound: ";
    cin >> upper_bound;

    if(lower_bound >= upper_bound)
    {
        cout << "The upper bound must be strictly greater than the lower bound"
             << endl;
        return EXIT_FAILURE;
    }

    cout << "Enter a seed value: ";
    cin >> seed_value;

    default_random_engine gen(seed_value);
    produce_random_numbers(lower_bound, upper_bound, gen);

    string key = "";
    cout << "Press q to quit or any other key to continue: ";
    cin >> key;

    while (key != "q") {
        produce_random_numbers(lower_bound, upper_bound, gen);
        cout << "Press q to quit or any other key to continue: ";
        cin >> key;
    }

    return EXIT_SUCCESS;
}
