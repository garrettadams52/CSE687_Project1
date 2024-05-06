#ifndef WORD_COUNT_MAPPER_H
#define WORD_COUNT_MAPPER_H

#include "IFileManagement.h"
#include "BaseMapper.h"  
#include <vector>
#include <fstream>
#include <string>

#ifdef MAPLIBRARY_EXPORTS
#define MAPLIBRARY_API __declspec(dllexport)
#else
#define MAPLIBRARY_API __declspec(dllimport)
#endif

class MAPLIBRARY_API WordCountMapper : public BaseMapper {
    IFileManagement* fileManager;
    std::ofstream outputFile;
    std::vector<std::string> buffer;
    size_t bufferSize;

public:
    WordCountMapper(IFileManagement* fileManager, size_t bufferSize);
    ~WordCountMapper();

    void map(const std::string& fileName, const std::string& content) override; 
    void exportToFile(const std::string& word);  
    void flushBuffer();
};

#endif 



