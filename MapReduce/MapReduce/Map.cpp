#include "Map.h"
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>

void Map::map(const std::string& filename, const std::string& line) {
    auto words = tokenize(line);
    exportToFile(filename, words);
}

std::vector<std::string> Map::tokenize(const std::string& line) {
    std::vector<std::string> tokens;
    std::istringstream iss(line);
    std::string token;
    while (iss >> token) {
        token.erase(std::remove_if(token.begin(), token.end(), [](unsigned char c) { return std::ispunct(c); }), token.end());
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
        tokens.push_back(token);
    }
    return tokens;
}

void Map::exportToFile(const std::string& key, const std::vector<std::string>& data) {
    std::ofstream outFile(key + "\\temp.txt", std::ios::app);
    for (const auto& word : data) {
        outFile << word << " 1\n";
    }
}
