#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a number: ";
    int luku = 0;
    cin >> luku;
    int kuutio = luku*luku*luku;

    if (luku == 0) {
        cout << "The cube of " << luku << " is " << luku << "." << endl;
        return 0;
    }


    if (kuutio < 0) {
        cout << "Error! The cube of " << luku << " is not " << kuutio << "." << endl;
    } else if (kuutio % luku != 0) {
        cout << "Error! The cube of " << luku << " is not " << kuutio << "." << endl;
    } else {
        cout << "The cube of " << luku << " is " << kuutio << "." << endl;
    }
    return 0;
}
