#include "Sort.h"
#include <fstream>
#include <sstream>
#include <iostream>

Sort::Sort() {}

void Sort::processFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        processLine(line);
    }
}

void Sort::processLine(const std::string& line) {
    std::istringstream iss(line);
    std::string word;
    int count;
    if (iss >> word >> count) {
        aggregatedData[word].push_back(count);
    }
    else {
        std::cerr << "Failed to parse line: " << line << std::endl;
    }
}

const std::map<std::string, std::vector<int>>& Sort::getAggregatedData() const {
    return aggregatedData;
}