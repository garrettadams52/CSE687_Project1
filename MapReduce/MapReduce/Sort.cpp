#include "Sort.h"
#include <fstream>
#include <sstream>
#include <algorithm>

 program-with-documentation
//This class performs the second portion of the word token counting process. It aggreates all of the instances of each word
//into an n-tuple containing that word as its first member, followed all occurrences of the word, each occurrence represented by a "1".
//It also sorts these n-tuples alphabetically.

//Class constructor which points fileManager to the address of the argument of the same name
Sort::Sort(FileManagement* fileManager)
    : fileManager(fileManager) {}

//Aggregates all occurrences of each word in the temporary into the an n-tuple with the given word as the first member
//and sorts all words in alphabetical order

Sort::Sort(FileManagement* fileManager)
    : fileManager(fileManager) {}

main
void Sort::sortAndAggregate() {
    std::string inputPath = fileManager->getTempDirectory() + "/temp_output.txt";
    std::string outputPath = fileManager->getTempDirectory() + "/sorted_aggregated_output.txt";

    std::vector<std::pair<std::string, int>> entries;
    std::vector<std::string> lines = fileManager->readFile(inputPath);

    for (const std::string& line : lines) {
        std::string word;
        int count;
        std::stringstream ss(line);
        ss.ignore(1, '(');
        getline(ss, word, ',');
        ss.ignore(2, ' ');
        ss >> count;
        ss.ignore(2, ')');
        entries.emplace_back(word, count);
    }

    std::sort(entries.begin(), entries.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
        });

    std::map<std::string, std::vector<int>> aggregated = aggregateData(entries);

    std::stringstream outputContent;
    for (const auto& [word, counts] : aggregated) {
        outputContent << "(" << word << ", [";
        for (size_t i = 0; i < counts.size(); ++i) {
            outputContent << counts[i];
            if (i < counts.size() - 1) outputContent << ", ";
        }
        outputContent << "])\n";
    }

    fileManager->writeFile(outputPath, outputContent.str(), false); 
}

 program-with-documentation
//Pushes aggregated n-tuples into a vector and returns the vector to a caller. Helper function to sortAndAggregate.

main
std::map<std::string, std::vector<int>> Sort::aggregateData(const std::vector<std::pair<std::string, int>>& data) {
    std::map<std::string, std::vector<int>> aggregated;
    for (const auto& entry : data) {
        aggregated[entry.first].push_back(entry.second);
    }
    return aggregated;
}