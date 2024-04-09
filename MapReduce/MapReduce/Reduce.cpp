#include "Reduce.h"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

Reduce::Reduce(const std::string& outputDir) : outputDirectory(outputDir) {}

void Reduce::reduce(const std::string& intermediateFilePath) {
    std::ifstream inFile(intermediateFilePath);
    std::map<std::string, int> wordCounts;
    std::string line;

    if (!inFile.is_open()) {
        std::cerr << "Could not open intermediate file: " << intermediateFilePath << std::endl;
        return;
    }

    while (getline(inFile, line)) {
        size_t startPos = line.find('\"') + 1; 
        size_t endPos = line.find('\"', startPos); 

        if (startPos == std::string::npos || endPos == std::string::npos) {
            continue; 
        }

        std::string word = line.substr(startPos, endPos - startPos);

        int count = 0;
        size_t pos = endPos;
        while ((pos = line.find("1", pos + 1)) != std::string::npos) {
            count++;
        }

        wordCounts[word] += count; 
    }

    inFile.close();

    // Export the results
    exportResults(wordCounts);
}


void Reduce::exportResults(const std::map<std::string, int>& wordCounts) {
    std::ofstream outFile(outputDirectory + "/final_results.txt");
    if (!outFile.is_open()) {
        std::cerr << "Failed to open output file in directory: " << outputDirectory << std::endl;
        return;
    }

    for (const auto& pair : wordCounts) {
        outFile << pair.first << ": " << pair.second << std::endl; 
    }
}
