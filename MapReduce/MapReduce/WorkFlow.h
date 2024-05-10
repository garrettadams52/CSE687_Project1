#ifndef WORKFLOW_H
#define WORKFLOW_H

#include <string>
#include "FileManagement.h"
#include "Map.h"

class Workflow {
public:
    Workflow(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir);
    void run();

private:
    std::string inputDirectory;
    std::string tempDirectory;
    std::string outputDirectory;
};

#endif // WORKFLOW_H
