/*
Map:
i) map - unique, sorted
ii) unordered map - unique
iii) multimap - not unique, sorted
*/

// Frequency counter

#include <iostream>
#include <map>
#include <sstream>

int main () {
    std::string str; 
    std::getline(std::cin, str);

    std::map<std::string, int> map;
    std::string word;
    std::stringstream ss(str);

    while (ss >> word) {
        map[word]++;
    }

    for (auto pair : map) {
        std::cout << pair.first << " : " << pair.second << "\n";
    }

    return 0;
}
