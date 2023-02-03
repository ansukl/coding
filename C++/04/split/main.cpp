#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> split(std::string line, char separator,bool empty = false)
{
    std::vector<std::string> splitted = {};
    std::string::size_type i = 0;
    std::string part = "";
    while (i < line.length()) {
        char c = line.at(i);

        if (c != separator) {
            part += c;
        } else if (c == separator) {
            if (!empty) {
                if ((c == separator && i == 0)) {
                    splitted.push_back("");
                } else if (c == separator && c == line.at(i-1)) {
                    splitted.push_back("");
                 } else {
                    splitted.push_back(part);
                    part = "";
                }
            } else {
                if (part != "") {
                    splitted.push_back(part);
                }
                part = "";
            }
        }
       i++;
    }
    if (part != "") {
        splitted.push_back(part);
    } else if (line.at(i-1) == separator && !empty) {
        splitted.push_back("");
    }
    return splitted;
}

int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
