#include <iostream>
#include <cctype>

const int CHAR_COUNT = 26;

using namespace std;

bool is_lower(string str)
{
    for (unsigned long long i = 0; i < str.length(); ++i) {
        if (!islower(str.at(i))) {
            return false;
        }
    } return true;
}

bool all_chars(string s)
{
    string check_str = "";
    for (int i = 0; i < CHAR_COUNT; ++i) {
        bool found = false;

        for (char kirjain = 'a'; kirjain <= 'z'; ++kirjain) {
            if (s.at(i) == kirjain) {
                if (check_str.find(kirjain) == string::npos) {
                    found = true;
                    check_str += kirjain;
                    break;
                } else {
                    return false;
                }
            }
        }
        if (!found) {
            return false;
        }
    }
    if (check_str.length() == CHAR_COUNT) {
        return true;
    } else {
        return false;
    }
}

void encrypting(string key, string msg)
{
    string encrypted_msg = "";
    for (unsigned long long i = 0; i < msg.length(); ++i) {
        int merkin_ascii_arvo = static_cast< int >(msg.at(i));
        merkin_ascii_arvo -= 97;
        encrypted_msg += key.at(merkin_ascii_arvo);
    }
    cout << "Encrypted text: " << encrypted_msg << endl;
}

int main()
{
    string key = "";
    string msg = "";
    string::size_type key_length = 0;

    cout << "Enter the encryption key: ";
    cin >> key;

    key_length = key.length();

    if (key_length != CHAR_COUNT) {
        cout << "Error! The encryption key must contain 26 characters." << endl;
        return EXIT_FAILURE;
    } else if (!is_lower(key)) {
        cout << "Error! The encryption key must contain only lower case characters." << endl;
        return EXIT_FAILURE;
    }else if (!all_chars(key)) {
        cout << "Error! The encryption key must contain all alphabets a-z." << endl;
        return EXIT_FAILURE;
    }

    cout << "Enter the text to be encrypted: ";
    cin >> msg;

    if (!is_lower(msg)) {
        cout << "Error! The text to be encrypted must contain only lower case characters." << endl;
        return EXIT_FAILURE;
    }

    encrypting(key, msg);

    return 0;
}
