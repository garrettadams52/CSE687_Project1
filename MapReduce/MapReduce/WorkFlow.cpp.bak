#include "Workflow.h"
#include <iostream>
#include "Sort.h"
#include "Reduce.h"

Workflow::Workflow(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir)
    : inputDirectory(inputDir), tempDirectory(tempDir), outputDirectory(outputDir) {}

void Workflow::run() {
    size_t bufferSize = 1000;
    FileManagement fileManagement(inputDirectory, tempDirectory, outputDirectory);

    std::vector<std::string> filesToClear = { "temp_output.txt", "final_output.txt", "sorted_aggregated_output.txt" };
    fileManagement.clearFiles(tempDirectory, filesToClear);
    Map mapper(&fileManagement, bufferSize);
    Sort sorter(&fileManagement);
    Reduce reducer(&fileManagement);



    auto files = fileManagement.getAllFiles();
    if (files.empty()) {
        std::cerr << "No files found in the input directory: " << inputDirectory << std::endl;
        return;
    }

    for (const auto& file : files) {
        auto lines = fileManagement.readFile(file);
        for (const auto& line : lines) {
            mapper.map(file, line);  
        }
    }

    sorter.sortAndAggregate();
    reducer.reduce();

}
