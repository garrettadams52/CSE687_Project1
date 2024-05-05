#include "pch.h"
#include "framework.h"
#include "MapLibrary.h"
#include <iostream>

// Implementation of Map class methods
Map::Map(FileManagement* fileManager, size_t bufferSize)
    : fileManager(fileManager), bufferSize(bufferSize), outputFile() {
    // Constructor implementation
}

Map::~Map() {
    flushBuffer();
    if (outputFile.is_open()) {
        outputFile.close();
    }
}

void Map::map(const std::string& fileName, const std::string& content) {
    // Implementation of map
}

void Map::flushBuffer() {
    for (const auto& line : buffer) {
        outputFile << line << std::endl;
    }
    buffer.clear();
}

void Map::exportToFile(const std::string& fileName, const std::string& word) {
    if (!outputFile.is_open()) {
        outputFile.open(fileName, std::ios::out | std::ios::app);
        if (!outputFile) {
            std::cerr << "Failed to open file: " << fileName << std::endl;
            return; 
        }
    }
    outputFile << word << std::endl;
    if (outputFile.fail()) {
        std::cerr << "Failed to write to file: " << fileName << std::endl;
    }
}


// DLL interface functions
extern "C" {

    MAPLIBRARY_API void* CreateMap(FileManagement* fileManager, size_t bufferSize) {
        return new Map(fileManager, bufferSize);
    }

    MAPLIBRARY_API void DeleteMap(void* map) {
        delete static_cast<Map*>(map);
    }

    MAPLIBRARY_API void MapAddContent(void* map, const char* fileName, const char* content) {
        static_cast<Map*>(map)->map(std::string(fileName), std::string(content));
    }

    MAPLIBRARY_API void MapFlushBuffer(void* map) {
        static_cast<Map*>(map)->flushBuffer();
    }

    MAPLIBRARY_API void MapExportToFile(void* map, const char* fileName, const char* word) {
        static_cast<Map*>(map)->exportToFile(std::string(fileName), std::string(word));
    }

}
