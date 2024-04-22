#include "Reduce.h"
#include <fstream>
#include <numeric>  

void Reduce::reduce(const std::string& key, const std::vector<int>& values) {
    int sum = std::accumulate(values.begin(), values.end(), 0);
    exportToFile(key, sum);
}

void Reduce::exportToFile(const std::string& key, int result) {
    std::ofstream outFile("output/" + key, std::ios::app);
    outFile << key << " " << result << "\n";
    if (outFile) {
        std::ofstream successFile("output/SUCCESS");
    }
}
