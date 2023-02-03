#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string input_file_name = "";
    cout << "Input file: ";
    getline(cin, input_file_name);

    ifstream file_object(input_file_name);
    if (not file_object) {
        cout << "Error! The file " << input_file_name << " cannot be opened." <<endl;
        return EXIT_FAILURE;
    } else {
        cout << "Final scores: " <<endl;

        string row = "";
        map<string, int> points;

        while (getline(file_object, row)) {
            vector<string> splitted =  {};
            string part = "";
            string::size_type i = 0;

            while (i < row.length()) {
                char c = row.at(i);

                if (c != ':') {
                    part += c;
                } else {
                    splitted.push_back(part);
                    part = "";
                }
               i++;
            }
            splitted.push_back(part);
            int num = stoi(splitted.back());

            if (points.find(splitted.front()) == points.end()) {
                points.insert({splitted.front(), num});
            } else {
                points.at(splitted.front()) += num;
            }
        } for (auto &info_pair : points) {
            cout << info_pair.first << ": " << info_pair.second << endl;
        }
    } return EXIT_SUCCESS;
}

