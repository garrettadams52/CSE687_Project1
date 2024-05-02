#ifndef WORKFLOW_H
#define WORKFLOW_H

#include "FileManagement.h"
#include "MapLibrary.h"
#include <string>
#include <windows.h>

class Workflow {
public:
    Workflow(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir);
    ~Workflow();
    void run();

private:
    FileManagement fileManagement;  // Declare fileManagement here
    std::string inputDirectory;
    std::string tempDirectory;
    std::string outputDirectory;
    HINSTANCE hMapDll;
    void* mapInstance;  // This will hold the object returned by CreateMap

    typedef void* (*funcCreateMap)(FileManagement*, size_t);
    typedef void (*funcDeleteMap)(void*);
    typedef void (*funcMapAddContent)(void*, const std::string&, const std::string&);
    typedef void (*funcMapFlushBuffer)(void*);

    funcCreateMap CreateMap;
    funcDeleteMap DeleteMap;
    funcMapAddContent MapAddContent;
    funcMapFlushBuffer MapFlushBuffer;
};

#endif // WORKFLOW_H
