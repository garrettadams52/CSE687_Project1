// Reduce.h in ReduceLibrary DLL project
#pragma once

#ifdef REDUCELIBRARY_EXPORTS
#define REDUCE_API __declspec(dllexport)
#else
#define REDUCE_API __declspec(dllimport)
#endif

#include "IFileManagement.h"
#include <string>

class REDUCE_API Reduce {
public:
    Reduce(IFileManagement* fileManager);

    void reduce();
    void exportResult(const std::string& key, int result);

private:
    IFileManagement* fileManager;
    std::string outputPath;
};
