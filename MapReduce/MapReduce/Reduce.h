#ifndef REDUCE_H
#define REDUCE_H

#include <string>
#include <map>

class Reduce {
public:
    Reduce(const std::string& outputDir);
    void reduce(const std::string& intermediateFilePath);

private:
    std::string outputDirectory;
    void exportResults(const std::map<std::string, int>& wordCounts);
};

#endif