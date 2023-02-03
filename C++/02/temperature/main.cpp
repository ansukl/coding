#include <iostream>

using namespace std;

int main()
{
    int temp = 0;
    double c2f = 0;
    double f2c = 0;

    cout << "Enter a temperature: ";
    cin >> temp;

    c2f = temp * 1.8 + 32;
    f2c = (temp - 32) / 1.8;
    cout << temp << " degrees Celsius is " << c2f << " degrees Fahrenheit" << endl;
    cout << temp << " degrees Fahrenheit is " << f2c << " degrees Celsius" << endl;

    return 0;
}
