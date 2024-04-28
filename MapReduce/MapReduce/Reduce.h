#ifndef REDUCE_H
#define REDUCE_H

#include <string>
#include <vector>
#include <map>
#include "FileManagement.h"

//This class performs the final portion of the word token counting process. It iterates through the n-tuples for each word, summing the
//"1"s that denote each occurrence of the word into a single number representing the total occurrences of that word, and also removes
//the original tuples denoting individual word tokens. Finally, it writes the modified results to an output file in the directory 
//specified by the user.

class Reduce {
public:
    explicit Reduce(FileManagement* fileManager);
    void reduce();
private:
    FileManagement* fileManager;
    std::string outputPath;  
    void exportResult(const std::string& key, int result);
};

#endif // REDUCE_H
