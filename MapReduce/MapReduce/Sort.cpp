#include "Sort.h"
#include <fstream>
#include <sstream>
#include <algorithm>

Sort::Sort(const std::string& inputFile, const std::string& outputFile)
    : inputFile(inputFile), outputFile(outputFile) {}

void Sort::sortAndAggregate() {
    std::vector<std::pair<std::string, int>> entries;
    std::string line;

    // Read entries from the intermediate file
    std::ifstream inFile(inputFile);
    while (getline(inFile, line)) {
        std::string word;
        int count;
        std::stringstream ss(line);
        ss.ignore(1, '(');           // Ignore the opening parenthesis
        getline(ss, word, ',');      // Get the word
        ss.ignore(2, ' ');           // Ignore the comma and space
        ss >> count;                 // Get the count
        ss.ignore(2, ')');           // Ignore the closing parenthesis
        entries.emplace_back(word, count);
    }
    inFile.close();

    // Sort entries by word
    std::sort(entries.begin(), entries.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
        });

    // Aggregate sorted data
    auto aggregated = aggregateData(entries);

    // Output to file
    std::ofstream outFile(outputFile);
    for (const auto& [word, counts] : aggregated) {
        outFile << "(" << word << ", [";
        for (size_t i = 0; i < counts.size(); ++i) {
            outFile << counts[i];
            if (i < counts.size() - 1) outFile << ", ";
        }
        outFile << "])\n";
    }
    outFile.close();
}

std::map<std::string, std::vector<int>> Sort::aggregateData(const std::vector<std::pair<std::string, int>>& data) {
    std::map<std::string, std::vector<int>> aggregated;
    for (const auto& entry : data) {
        aggregated[entry.first].push_back(entry.second);
    }
    return aggregated;
}
