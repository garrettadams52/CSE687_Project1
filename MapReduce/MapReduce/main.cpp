#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include "Reduce.h"
#include "Sorter.h"

int main() {
    std::string inputFilePath, tempDir, outputDir;

    std::cout << "Enter the path to the input file:\n";
    std::getline(std::cin, inputFilePath);
    std::cout << "Enter the directory to store temporary files:\n";
    std::getline(std::cin, tempDir);
    std::cout << "Enter the directory to store the output file:\n";
    std::getline(std::cin, outputDir);

    //Map phase
    Map mapper(tempDir);

    std::ifstream inFile(inputFilePath);
    if (!inFile.is_open()) {
        std::cerr << "Could not open file: " << inputFilePath << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        mapper.map(line);
    }
    inFile.close(); 

    std::cout << "Mapping completed. Intermediate results are in " << tempDir << std::endl;

    std::string tempFilePath = tempDir + "/temp_results.txt";

    Sorter::sortAndPrepare(tempFilePath);

    // Reduce phase
    Reduce reducer(outputDir);
    std::string intermediateFilePath = tempDir + "/temp_results.txt"; 
    reducer.reduce(intermediateFilePath);

    std::cout << "Reducing completed. Final results are in " << outputDir << std::endl;

    return 0;
}