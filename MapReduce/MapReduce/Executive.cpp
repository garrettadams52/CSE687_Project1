#include "Executive.h"

Executive::Executive(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir)
    : workflow(inputDir, tempDir, outputDir) {}

void Executive::run() {
    workflow.run();
}
