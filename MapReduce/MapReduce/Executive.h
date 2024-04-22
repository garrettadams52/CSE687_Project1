#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Workflow.h"
#include <string>

class Executive {
public:
    Executive(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir);
    void run();

private:
    Workflow workflow;
};

#endif // EXECUTIVE_H