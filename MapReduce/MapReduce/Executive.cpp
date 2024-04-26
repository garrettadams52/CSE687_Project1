#include "Executive.h"
#include <iostream>

Executive::Executive(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir)
    : workflow(inputDir, tempDir, outputDir), fileManagement(inputDir, tempDir, outputDir) {}

void Executive::run() {
    workflow.run();
    markSuccess();
}

void Executive::markSuccess() {
    std::string successFilePath = fileManagement.getOutputDirectory() + "/SUCCESS";
    std::ofstream successFile(successFilePath);
    if (successFile) {
        successFile.close();
        std::cout << "SUCCESS file created." << std::endl;
    }
    else {
        std::cerr << "Failed to create SUCCESS file." << std::endl;
    }
}

