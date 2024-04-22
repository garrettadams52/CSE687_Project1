#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <string>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

class FileManagement {
public:
    // Constructor with the root directory
    explicit FileManagement(const std::string& rootDir);

    // Create a file with content
    void createFile(const std::string& filePath, const std::string& content);

    // Read a file into a vector of strings, each string a line
    std::vector<std::string> readFile(const std::string& filePath);

    // List all files in a directory matching a specific extension
    std::vector<std::string> listFiles(const std::string& dirPath, const std::string& ext);

    // Check if a file or directory exists
    bool exists(const std::string& path);

    // Create a directory if it doesn't exist
    void ensureDirectory(const std::string& path);
};

#endif // FILEMANAGEMENT_H
