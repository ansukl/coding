#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input_file_name = "";
    cout << "Input file: ";
    getline(cin, input_file_name);

    string output_file_name = "";
    cout << "Output file: ";
    getline(cin, output_file_name);

    ifstream file_object(input_file_name);
    if (not file_object) {
        cout << "Error! The file " << input_file_name << " cannot be opened." <<endl;
        return EXIT_FAILURE;
    } else {
        string row = "";
        vector<string> text = {};
        while (getline(file_object, row)) {
            text.push_back(row);

        } file_object.close();

        ofstream other_file(output_file_name);
        int num = 1;
        for(auto str : text) {
            other_file << num << " " << str <<endl;
            num ++;
        } other_file.close();
    }
}
