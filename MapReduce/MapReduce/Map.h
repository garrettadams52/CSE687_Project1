#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

class Map {
public:
    void map(const std::string& filename, const std::string& line);

private:
    std::vector<std::string> tokenize(const std::string& line);
    void exportToFile(const std::string& key, const std::vector<std::string>& data);
};

#endif // MAP_H
