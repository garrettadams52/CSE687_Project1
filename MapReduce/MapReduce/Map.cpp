#include "FileManagement.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

// Function declarations
string processWord(string word);

class Map {
private:
    string tempFilePath;
    FileManagement fileMgr; // Instance of FileManagement to handle file operations
    vector<string> tempResults; // Buffer to store temporary results

public:
    Map(const string& tempDir) : tempFilePath(tempDir + "/temp_results.txt") {
        // Do not open a file here; defer file operations to the FileManagement class
    }

    ~Map() {
        fileMgr.writeFileLines(tempFilePath, tempResults); // Write buffered results to temporary file
    }

    void map(const string& value) {
        stringstream ss(value);
        string word;
        while (ss >> word) {
            word = processWord(word);
            if (!word.empty()) {
                tempResults.push_back("(" + word + ", 1)"); // Use a buffer instead of writing to file immediately
            }
        }
    }
};

// Function implementations
string processWord(string word) {
    word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c); }), word.end());
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

// The main function can remain the same as it is in your original implementation
