#include "Sorter.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>

std::map<std::string, int> countOccurrences(const std::string& filePath) {
    std::map<std::string, int> wordCounts;
    std::ifstream file(filePath);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filePath << std::endl;
        return wordCounts;  
    }

    while (std::getline(file, line)) {
        std::string word = line.substr(2, line.find(',', 2) - 3);  
        ++wordCounts[word]; 
    }

    file.close();
    return wordCounts;
}


void writeFormattedOccurrences(const std::string& filePath, const std::map<std::string, int>& wordCounts) {
    std::ofstream outFile(filePath, std::ofstream::trunc); 

    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for writing: " << filePath << std::endl;
        return;
    }

    for (const auto& pair : wordCounts) {
        if (!pair.first.empty()) {
            outFile << "(\"" << pair.first << "\", [";
            for (int i = 0; i < pair.second; ++i) {
                outFile << "1";
                if (i < pair.second - 1) {
                    outFile << ", ";
                }
            }
            outFile << "])\n";
        }
    }
}

void Sorter::sortAndPrepare(const std::string& filePath) {
    auto wordCounts = countOccurrences(filePath);
    writeFormattedOccurrences(filePath, wordCounts);
}
