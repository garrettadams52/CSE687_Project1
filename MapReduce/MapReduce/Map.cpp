#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to process words: remove punctuation and convert to lowercase
string processWord(string word) {
    word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c); }), word.end());
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

class Map {
private:
    ofstream outFile;
    string tempDirectory;

public:
    Map(const string& tempDir) : tempDirectory(tempDir) { // Ensure tempDirectory is initialized with tempDir
        string tempFilePath = tempDirectory + "\\temp_results.txt"; // Now tempDirectory has the correct value
        outFile.open(tempFilePath);
        if (!outFile.is_open()) {
            throw runtime_error("Failed to open temporary file: " + tempFilePath);
        }
    }

    ~Map() {
        if (outFile.is_open()) {
            outFile.close(); // Ensure the file is closed at the end
        }
    }

    void map(const string& value) {
        stringstream ss(value);
        string word;
        while (ss >> word) {
            word = processWord(word);
            if (!word.empty()) {
                // Write each processed word followed by "1" in the desired format
                outFile << "(" << word << ", 1)\n";
            }
        }
    }
};


int main() {
    string inputFilePath, tempDir;

    cout << "Enter the path to the input file:\n";
    getline(cin, inputFilePath);
    cout << "Enter the directory to store temporary files:\n";
    getline(cin, tempDir);

    Map mapper(tempDir);

    ifstream inFile(inputFilePath);
    if (!inFile.is_open()) {
        cerr << "Could not open file: " << inputFilePath << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        mapper.map(line);
    }

    cout << "Processing completed. Check the temporary files in " << tempDir << endl;

    return 0;
}
