#include "Map.h"
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iostream>

Map::Map(FileManagement* fileManager, size_t bufferSize)
    : fileManager(fileManager), bufferSize(bufferSize) {
    std::string fullPath = fileManager->getTempDirectory() + "\\temp_output.txt";
    outputFile.open(fullPath, std::ios::app);
    if (!outputFile) {
        std::cerr << "Error opening file: " << fullPath << std::endl;

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
    flushBuffer();  
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
    if (outFile.is_open()) {
        outFile.close();
    }
}



