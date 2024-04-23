#include "Map.h"
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iostream>

Map::Map(FileManagement* fileManager, size_t bufferSize)
    : fileManager(fileManager), bufferSize(bufferSize) {
    // Construct the full path for the output file and open it
    std::string fullPath = fileManager->getTempDirectory() + "\\temp_output.txt";
    outputFile.open(fullPath, std::ios::app);
    if (!outputFile) {
        std::cerr << "Error opening file: " << fullPath << std::endl;
    }
}

Map::~Map() {
    flushBuffer();  // Ensure all data is flushed at the end
    if (outputFile.is_open()) {
        outputFile.close();
    }
}

void Map::map(const std::string& fileName, const std::string& content) {
    std::istringstream stream(content);
    std::string word;
    while (stream >> word) {
        word.erase(std::remove_if(word.begin(), word.end(),
            [](unsigned char c) { return !std::isalpha(c); }), word.end());
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (!word.empty()) {
            exportToFile(fileName, word);
        }
    }
}

void Map::exportToFile(const std::string& fileName, const std::string& word) {
    // Buffer the output in the format (word, 1)
    buffer.push_back("(" + word + ", 1)");
    // Check if the buffer size exceeds the threshold
    if (buffer.size() >= bufferSize) {
        flushBuffer();
    }
}

void Map::flushBuffer() {
    for (const auto& entry : buffer) {
        outputFile << entry << std::endl;
    }
    buffer.clear();  // Clear
}
