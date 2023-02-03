#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int number = 0;
    int first = 0;
    int second = 0;

    cout << "Enter a positive number: ";
    cin >> number;

    if (number <= 0) {
        cout << "Only positive numbers accepted" << endl;
        return 0;
    }

    first = sqrt(number);

    while (number % first != 0) {
        first++;
    }

    second = number / first;

    if (first < second) {
        cout << number << " = " << first << " * " << second << endl;
    } else {
        cout << number << " = " << second << " * " << first << endl;
    }

    return 0;
}
