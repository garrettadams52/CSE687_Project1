#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>
#include <fstream>
#include <boost/filesystem.hpp>  // Boost library for filesystem operations
#include <boost/log/trivial.hpp> // Boost library for logging

// Define a namespace alias for boost::filesystem for easier and clearer usage
namespace fs = boost::filesystem;

// FileManager class handles reading and writing files and managing directories
class FileManager {
public:
    // Reads content from a file into a vector of strings
    bool ReadFile(const std::string& file_path, std::vector<std::string>& data);

    // Writes data from a vector of strings to a file
    bool WriteFile(const std::string& file_path, const std::vector<std::string>& data);

    // Creates a directory at the specified path
    bool CreateDirectory(const std::string& dir_path);
};

#endif // FILE_MANAGER_H
