#ifndef REDUCE_H
#define REDUCE_H

#include <string>
#include <vector>
#include <map>

class Reduce {
public:
    Reduce(const std::string& inputFile, const std::string& outputDir);
    void reduce();
private:
    std::string inputFile;
    std::string outputDir;
    void exportResult(const std::string& key, int result);
    void markSuccess();
};

#endif // REDUCE_H
