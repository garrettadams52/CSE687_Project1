#include "FileManagement.h"
#include <fstream>
#include <iostream>

FileManagement::FileManagement(const std::string& rootDir) {
    ensureDirectory(rootDir);
}

void FileManagement::createFile(const std::string& filePath, const std::string& content) {
    std::ofstream outFile(filePath);
    if (outFile.is_open()) {
        outFile << content;
    }
    else {
        std::cerr << "Failed to open file for writing: " << filePath << std::endl;
    }
}

std::vector<std::string> FileManagement::readFile(const std::string& filePath) {
    std::vector<std::string> lines;
    std::ifstream inFile(filePath);
    std::string line;
    while (getline(inFile, line)) {
        lines.push_back(line);
    }
    return lines;
}

std::vector<std::string> FileManagement::listFiles(const std::string& dirPath, const std::string& ext) {
    std::vector<std::string> files;
    for (const auto& entry : fs::directory_iterator(dirPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ext) {
            files.push_back(entry.path().string());
        }
    }
    return files;
}

bool FileManagement::exists(const std::string& path) {
    return fs::exists(path);
}

void FileManagement::ensureDirectory(const std::string& path) {
    if (!fs::exists(path)) {
        fs::create_directories(path);
    }
}
