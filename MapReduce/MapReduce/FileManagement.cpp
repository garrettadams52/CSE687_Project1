#include "FileManagement.h"
#include <iostream>
#include <fstream>
#include <filesystem>

// Define the std::filesystem namespace alias as fs.
namespace fs = std::filesystem;

// Reads all the lines from the specified file and returns them.
std::vector<std::string> FileManagement::readFileLines(const std::string& filePath) const {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream fileStream(filePath);

    if (fileStream.is_open()) {
        while (std::getline(fileStream, line)) {
            lines.push_back(line);
        }
        fileStream.close();
    }
    else {
        // Error handling if the file can't be opened.
        std::cerr << "Unable to open file: " << filePath << std::endl;
        // Possibly throw an exception or handle the error as per your project requirements.
    }

    return lines;
}

// Writes a vector of strings to the file, each on a new line.
void FileManagement::writeFileLines(const std::string& filePath, const std::vector<std::string>& lines) const {
    std::ofstream fileStream(filePath);

    if (fileStream.is_open()) {
        for (const auto& line : lines) {
            fileStream << line << "\n";
        }
        fileStream.close();
    }
    else {
        // Error handling if the file can't be opened for writing.
        std::cerr << "Unable to open file for writing: " << filePath << std::endl;
        // Possibly throw an exception or handle the error as per your project requirements.
    }
}

// Lists all files within the specified directory.
std::vector<std::string> FileManagement::listFilesInDirectory(const std::string& directoryPath) const {
    std::vector<std::string> fileList;

    try {
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            if (entry.is_regular_file()) {
                fileList.push_back(entry.path().string());
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        // Error handling if the directory can't be read.
        std::cerr << "Error accessing the directory: " << e.what() << std::endl;
        // Possibly throw an exception or handle the error as per your project requirements.
    }

    return fileList;
}
