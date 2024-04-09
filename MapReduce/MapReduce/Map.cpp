#include "Map.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iostream>

std::string processWord(std::string word) {
    word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c); }), word.end());
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

Map::Map(const std::string& tempDir) : tempDirectory(tempDir) {
    std::string tempFilePath = tempDirectory + "\\temp_results.txt";
    outFile.open(tempFilePath);
    if (!outFile.is_open()) {
        throw std::runtime_error("Failed to open temporary file: " + tempFilePath);
    }
}

Map::~Map() {
    if (outFile.is_open()) {
        outFile.close();
    }
}

void Map::map(const std::string& value) {
    std::stringstream ss(value);
    std::string word;
    while (ss >> word) {
        word = processWord(word);
        if (!word.empty()) {
            outFile << "(" << word << ", 1)\n";
        }
    }
}


