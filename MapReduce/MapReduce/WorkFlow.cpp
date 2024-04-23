#include "Workflow.h"
#include <iostream>
#include "Sort.h"
#include "Reduce.h"

// Constructor initializes the directories used throughout the workflow
Workflow::Workflow(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir)
    : inputDirectory(inputDir), tempDirectory(tempDir), outputDirectory(outputDir) {}

// Main execution function for the workflow
void Workflow::run() {
    std::cout << "Workflow running..." << std::endl;

    FileManagement fileManagement(inputDirectory, tempDirectory, outputDirectory);


    //fileManagement.clearDirectory(tempDirectory);
    //fileManagement.clearDirectory(outputDirectory);

    // Initialize file management and retrieve list of files
    auto files = fileManagement.getAllFiles();
    if (files.empty()) {
        std::cerr << "No files found in the input directory: " << inputDirectory << std::endl;
        return;
    }

    // Initialize the map processor with the file management for directory handling
    Map mapper(&fileManagement);

    // Process each file
    for (const auto& file : files) {
        auto lines = fileManagement.readFile(file);
        for (const auto& line : lines) {
            mapper.map(file, line);  
        }
    }


    // After mapping is done
    Sort sorter(tempDirectory + "/temp_output.txt", tempDirectory + "/sorted_aggregated_output.txt");
    sorter.sortAndAggregate();

    Reduce reducer(tempDirectory + "/sorted_aggregated_output.txt", outputDirectory);
    reducer.reduce();

}
