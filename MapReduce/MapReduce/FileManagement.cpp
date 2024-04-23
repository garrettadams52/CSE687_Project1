#include "FileManagement.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

FileManagement::FileManagement(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir)
    : inputDirectory(inputDir), tempDirectory(tempDir), outputDirectory(outputDir) {}

std::vector<std::string> FileManagement::getAllFiles() const {
    std::vector<std::string> files;
    for (const auto& entry : fs::directory_iterator(inputDirectory)) {
        if (entry.is_regular_file()) {
            files.push_back(entry.path().string());
        }
    }
    return files;
}

std::vector<std::string> FileManagement::readFile(const std::string& filePath) const {
    std::ifstream file(filePath);
    if (!file) {
        //std::cerr << "Failed to open file: " << filePath << std::endl;
        return {};
    }

    std::vector<std::string> lines;
    std::string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
            //std::cout << "Line read: '" << line.substr(0, std::min(line.size(), size_t(50))) << "...'" << std::endl;
        }
    }

    if (lines.empty()) {
        //std::cout << "No lines read from file: " << filePath << std::endl;
    }
    else {
        //std::cout << "Read " << lines.size() << " lines from file: " << filePath << std::endl;
    }

    file.close();
    return lines;
}

void FileManagement::writeToTemp(const std::string& fileName, const std::string& content) const {
    std::ofstream file(tempDirectory + "/" + fileName, std::ios::app);
    file << content << std::endl;
    file.close();
}

void FileManagement::writeToOutput(const std::string& fileName, const std::string& content) const {
    std::ofstream file(outputDirectory + "/" + fileName);
    file << content;
    file.close();
}

bool FileManagement::checkDirectory(const std::string& dir) const {
    return fs::exists(dir) && fs::is_directory(dir);
}

std::string FileManagement::getTempDirectory() const {
    return tempDirectory;
}


//This needs fixed
void FileManagement::clearDirectory(const std::string& dirPath) {
    try {
        // Check if the directory exists and is not empty
        if (fs::exists(dirPath) && fs::is_directory(dirPath) && !fs::is_empty(dirPath)) {
            // Remove all contents of the directory
            for (const auto& entry : fs::directory_iterator(dirPath)) {
                fs::remove_all(entry);
            }
            std::cout << "Cleared directory: " << dirPath << std::endl;
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Error clearing directory " << dirPath << ": " << e.what() << std::endl;
    }
}
