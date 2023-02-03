#include <iostream>

using namespace std;

unsigned long int factorial(int n)
{
    unsigned long int factorial = 1;

    for(int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    return factorial;
}

unsigned long int probability(int total_balls, int drawn_balls)
{
    unsigned long int upper = factorial(total_balls);
    unsigned long int lower1 = factorial(total_balls - drawn_balls);
    unsigned long int lower2 = factorial(drawn_balls);

    return (upper/(lower1*lower2));
}

int main()
{
    int total_balls = 0;
    int drawn_balls = 0;


    cout << "Enter the total number of lottery balls: ";
    cin >> total_balls;

    cout << "Enter the number of drawn balls: ";
    cin >> drawn_balls;

    if (total_balls < 0 or drawn_balls < 0) {
        cout << "The number of balls must be a positive number." << endl;
    } else if (drawn_balls > total_balls) {
        cout << "The maximum number of drawn balls is the total amount of balls." << endl;
    } else {
        unsigned long int prob = probability(total_balls, drawn_balls);

        cout << "The probability of guessing all " << drawn_balls << " balls correctly is 1/" << prob << endl;
    }


    return 0;
}
