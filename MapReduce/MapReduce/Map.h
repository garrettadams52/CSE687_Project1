#ifndef MAP_H
#define MAP_H

#include <string>
#include <fstream>

std::string processWord(std::string word);

class Map {
private:
    std::ofstream outFile;
    std::string tempDirectory;

public:
    Map(const std::string& tempDir);
    ~Map();
    void map(const std::string& value);
};

#endif 
