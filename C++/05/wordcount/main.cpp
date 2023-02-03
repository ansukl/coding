#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

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
        map<string, set<int>> row_counter;
        string row = "";
        int row_number = 1;
        map<string, set<int>>::iterator iter;
        set<int>::iterator set_iter;
        string set_nums;

        while (getline(file_object, row)) {
            string part = "";
            string::size_type i = 0;

            while (i < row.length()) {
                char c = row.at(i);

                if (c != ' ') {
                    part += c;
                } else {
                    row_counter[part].insert(row_number);
                    part = "";
                }
               i++;
            }
            row_counter[part].insert(row_number);
            row_number ++;
      }
        iter = row_counter.begin();
        while (iter != row_counter.end()) {
            set_nums.clear();
            for (set_iter = iter->second.begin(); set_iter != iter->second.end(); ++set_iter) {
                if (set_iter == iter->second.begin()) {
                    set_nums += to_string(*set_iter);
                } else {
                    set_nums += ", " + to_string(*set_iter);
                }
            }
            cout << iter->first << " " << iter->second.size() << ": " << set_nums << endl;
            ++iter;
        }
        file_object.close();

    } return EXIT_SUCCESS;
}
