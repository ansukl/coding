#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

typedef std::map<std::string, std::vector<std::string>> VectorMap;

const std::string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";


std::vector<std::string> split(const std::string& s,
                               const char delimiter,
                               bool ignore_empty = false)
{
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

void store(VectorMap &network, const std::string id1, const std::string id2) {
    if (network.find(id1) == network.end())  {
        network[id1];
    }
    network[id1].push_back(id2);
}

void print(VectorMap network, std::string id1, int counter = 0) {
    for (int i = 0; i < counter; ++i) {
        std::cout << "..";
    }

    std::cout << id1 << std::endl;

    if (network.find(id1) != network.end()) {
        for (std::string &person : network[id1]) {
            print(network, person, counter + 1);
        }
    }
}

int count(VectorMap &network, const std::string id, int counter = 0) {
    if (network.find(id) != network.end()) {
        for (std::string &person : network[id]) {
            counter = count(network, person, ++counter);
        }
    } return counter;
}


int depth(VectorMap &network, const std::string id, int counter = 1, int max_depth = 0) {
    if (counter > max_depth) {
        max_depth = counter;
    }

    if (network.find(id) != network.end()) {
        for (std::string &person : network[id]) {
            max_depth = depth(network, person, counter + 1, max_depth);
        }
    } return max_depth;
}

int main()
{

    VectorMap network;

    while(true)
    {
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        // Allowing empty inputs
        if(parts.size() == 0)
        {
            continue;
        }

        std::string command = parts.at(0);

        if(command == "S" or command == "s")
        {
            if(parts.size() != 3)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);

            store(network, id1, id2);

        }
        else if(command == "P" or command == "p")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            print(network, id);

        }
        else if(command == "C" or command == "c")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            std::cout << count(network, id) << std::endl;

        }
        else if(command == "D" or command == "d")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            std::cout << depth(network, id) << std::endl;

        }
        else if(command == "Q" or command == "q")
        {
           return EXIT_SUCCESS;
        }
        else
        {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
