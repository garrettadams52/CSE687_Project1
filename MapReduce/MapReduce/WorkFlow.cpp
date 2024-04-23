#include "Workflow.h"
#include "FileManagement.h"
#include "Map.h"
#include "Reduce.h"
#include "Sort.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

// Constructor for the Workflow class, initializing member variables with provided directory paths.
Workflow::Workflow(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir)
    : inputDirectory(inputDir), tempDirectory(tempDir), outputDirectory(outputDir) {}

// The run method that orchestrates the MapReduce workflow.
void Workflow::run() {
    // Create an instance of FileManager, which is responsible for file operations.
    FileManager fileManager;
    // Create an instance of the Map class, which will be responsible for the mapping phase.
    Map mapper;
    // Create an instance of the Reduce class, which will be responsible for the reduction phase.
    Reduce reducer;
    // Create an instance of the Sort class, which will handle the sorting of intermediate data.
    Sort sorter;

    // Iterate through each file in the input directory.
    for (const auto& entry : fs::directory_iterator(inputDirectory)) {
        // Check if the directory entry is a regular file and has a .txt extension.
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            // Open the text file for reading.
            std::ifstream inputFile(entry.path().string());
            std::string line;

            // Read the file line by line.
            while (std::getline(inputFile, line)) {
                // Call the map method for each line in the file to perform the mapping operation.
                // The file name is being used as the key, and the line content as the value.
                mapper.map(entry.path().filename().string(), line);
            }
        }
    }

    // Assuming the mapper writes the intermediate mapped data to "temp.txt" in the tempDirectory.
    // Here, we tell the Sort object to process the created intermediate data.
    sorter.processFile(tempDirectory + "\\temp.txt");

    // After sorting is complete, obtain the aggregated data.
    const auto& aggregatedData = sorter.getAggregatedData();

    // Iterate through the aggregated data.
    for (const auto& [key, values] : aggregatedData) {
        // Call the reduce method for each key and corresponding values to perform the reduction operation.
        // The reduce method will process this data and perform the final part of the MapReduce process.
        reducer.reduce(key, values);
    }

    // At this point, the data has been mapped, sorted, and reduced.
    // Your final reduced and processed data is ready for use or output.
}
