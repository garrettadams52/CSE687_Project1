#include "Workflow.h"
#include "FileManagement.h"
#include "Map.h"
#include "Reduce.h"
#include "Sort.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

Workflow::Workflow(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir)
    : inputDirectory(inputDir), tempDirectory(tempDir), outputDirectory(outputDir) {}

void Workflow::run() {
    FileManagement fileManager(outputDirectory);  
    Map mapper;
    Reduce reducer;
    Sort sorter;

  
    for (const auto& entry : fs::directory_iterator(inputDirectory)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::vector<std::string> lines = fileManager.readFile(entry.path().string());
            for (const auto& line : lines) {
                mapper.map(tempDirectory, line);
            }
        }
    }


    sorter.processFile(tempDirectory + "\\temp.txt"); 

    const auto& aggregatedData = sorter.getAggregatedData();
    for (const auto& [key, values] : aggregatedData) {
        reducer.reduce(key, values);
    }



}
