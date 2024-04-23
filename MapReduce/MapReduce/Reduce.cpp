#include "Reduce.h"
#include <fstream>
#include <iostream>
#include <sstream>

Reduce::Reduce(const std::string& inputFile, const std::string& outputDir)
    : inputFile(inputFile), outputDir(outputDir) {}


void Reduce::reduce() {
    std::ifstream inFile(inputFile);
    std::string line;

    while (getline(inFile, line)) {
        std::string key;
        std::vector<int> values;
        std::istringstream iss(line);
        char discard;

        iss >> discard; // Discard '('
        getline(iss, key, ','); // Read key
        key.erase(std::remove_if(key.begin(), key.end(), ::isspace), key.end()); // Remove spaces

        // Check for empty keys, which may indicate parsing issues
        if (key.empty()) {
            std::cerr << "Found an empty key in line: " << line << std::endl;
            continue;
        }

        // Parse the vector of integers
        iss >> discard; // Discard '['
        int num;
        while (iss >> num) {
            values.push_back(num);
            iss >> discard; // Discard ',' or ']'
        }

        int sum = 0;
        for (int value : values) {
            sum += value;
        }
        exportResult(key, sum);
    }
}

void Reduce::exportResult(const std::string& key, int result) {
    std::ofstream outFile(outputDir + "/reduced_output.txt", std::ios::app);
    outFile << "(" << key << ", " << result << ")" << std::endl;
    outFile.close();
}

void Reduce::markSuccess() {
    std::ofstream successFile(outputDir + "/SUCCESS");
    successFile.close();
}
