#ifndef REDUCE_H
#define REDUCE_H

#include <string>
#include <vector>
#include <map>

class Reduce {
public:
    void reduce(const std::string& key, const std::vector<int>& values);

private:
    void exportToFile(const std::string& key, int result);
};

#endif // REDUCE_H
