// MapLibrary.h
#pragma once

#ifdef MAPLIBRARY_EXPORTS
#define MAPLIBRARY_API __declspec(dllexport)
#else
#define MAPLIBRARY_API __declspec(dllimport)
#endif

#include "FileManagement.h"
#include <string>
#include <fstream>
#include <vector>

// Declare the Map class
class Map {
public:
    Map(FileManagement* fileManager, size_t bufferSize = 1000);
    ~Map();
    void map(const std::string& fileName, const std::string& content);
    void flushBuffer();  // Manually flush the buffer
    void exportToFile(const std::string& fileName, const std::string& word);

private:
    FileManagement* fileManager;
    std::ofstream outputFile;
    size_t bufferSize;
    std::vector<std::string> buffer;  // Use a vector to buffer the output
};

extern "C" {
    MAPLIBRARY_API void* CreateMap(FileManagement* fileManager, size_t bufferSize = 1000);
    MAPLIBRARY_API void DeleteMap(void* map);
    MAPLIBRARY_API void MapAddContent(void* map, const char* fileName, const char* content);
    MAPLIBRARY_API void MapFlushBuffer(void* map);
    MAPLIBRARY_API void MapExportToFile(void* map, const char* fileName, const char* word);
}
