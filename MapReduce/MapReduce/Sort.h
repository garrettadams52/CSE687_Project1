#ifndef SORT_H
#define SORT_H

#include <string>
#include <vector>
#include <map>
#include "FileManagement.h"

 program-with-documentation
//This class performs the second portion of the word token counting process. It aggreates all of the instances of each word
//into an n-tuple containing that word as its first member, followed all occurrences of the word, each occurrence represented by a "1".
//It also sorts these n-tuples alphabetically.


class Sort {
public:
    //Class constructor which points fileManager to the address of the argument of the same name
    explicit Sort(FileManagement* fileManager);
    //Aggregates all occurrences of each word in the temporary into the an n-tuple with the given word as the first member
    //and sorts all words in alphabetical order
    void sortAndAggregate();

private:
    //Pointer to externally allocted FileManagement object
    FileManagement* fileManager;
    //Pushes aggregated n-tuples into a vector and returns the vector to a caller. Helper function to sortAndAggregate.


class Sort {
public:
    explicit Sort(FileManagement* fileManager);
    void sortAndAggregate();

private:
    FileManagement* fileManager;
main
    std::map<std::string, std::vector<int>> aggregateData(const std::vector<std::pair<std::string, int>>& data);
};

#endif // SORT_H
