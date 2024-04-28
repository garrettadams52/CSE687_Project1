#include "Reduce.h"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

Reduce::Reduce(FileManagement* fileManager)
    : fileManager(fileManager) {
    outputPath = fileManager->getOutputDirectory() + "/final_output.txt";
}

void Reduce::reduce() {
    std::string inputPath = fileManager->getTempDirectory() + "/sorted_aggregated_output.txt";
    std::vector<std::string> lines = fileManager->readFile(inputPath);

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

void Reduce::exportResult(const std::string& key, int result) {
    std::string resultLine = "(" + key + ", " + std::to_string(result) + ")\n";
    fileManager->writeFile(outputPath, resultLine);
}
