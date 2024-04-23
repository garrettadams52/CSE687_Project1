#ifndef SORT_H
#define SORT_H

#include <string>
#include <vector>
#include <map>

class Sort {
public:
    Sort(const std::string& inputFile, const std::string& outputFile);
    void sortAndAggregate();

private:
    std::string inputFile;
    std::string outputFile;
    std::map<std::string, std::vector<int>> aggregateData(const std::vector<std::pair<std::string, int>>& data);
};

#endif // SORT_H
