#include "Map.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iostream>

Map::Map(FileManagement* fileManager, size_t bufferSize)
    : fileManager(fileManager), bufferSize(bufferSize) {
    std::string fullPath = fileManager->getTempDirectory() + "\\temp_output.txt";
    outputFile.open(fullPath, std::ios::app);
    if (!outputFile) {
        std::cerr << "Error opening file: " << fullPath << std::endl;
    }
}

//Class destructor which flushes the input buffer and closes the temporary directory
Map::~Map() {
    if (outFile.is_open()) {
        outFile.close();
    }
}

void Map::map(const std::string& fileName, const std::string& content) {
    std::istringstream stream(content);
    std::string word;
    while (stream >> word) {
        word.erase(std::remove_if(word.begin(), word.end(),
            [](unsigned char c) { return !std::isalpha(c); }), word.end());
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        //Sends word to member function exporToFile to place it inside a tuple
        if (!word.empty()) {
            outFile << "(" << word << ", 1)\n";
        }
    }
}

void Map::exportToFile(const std::string& fileName, const std::string& word) {
    buffer.push_back("(" + word + ", 1)");
    if (buffer.size() >= bufferSize) {
        flushBuffer();
    }
}

void Map::flushBuffer() {
    for (const auto& entry : buffer) {
        outputFile << entry << std::endl;
    }
    buffer.clear();  
}
