#ifndef SORTER_H
#define SORTER_H

#include <string>
#include <vector>
#include <map>

class Sort {
public:
    // Constructor
    Sort();

    // Loads data and performs sorting and aggregation from a specified file
    void processFile(const std::string& filename);

    // Retrieves the sorted and aggregated data
    const std::map<std::string, std::vector<int>>& getAggregatedData() const;

private:
    std::map<std::string, std::vector<int>> aggregatedData;

    // Utility function to parse and aggregate data from a line
    void processLine(const std::string& line);
};

#endif // SORTER_H
