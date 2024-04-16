// Include necessary headers
#include "MapReduce.h" // Custom header, potentially for a MapReduce implementation
#include <fstream>     // Standard file I/O header
#include <boost/filesystem.hpp>  // Header from Boost library for filesystem operations
#include <boost/log/trivial.hpp> // Header from Boost library for logging

// Define a namespace alias for boost::filesystem for easier and clearer usage
namespace fs = boost::filesystem;

// Defines a function to read content from a file into a vector of strings
bool FileManager::ReadFile(const std::string& file_path, std::vector<std::string>& data) {
    std::ifstream file(file_path); // Open the file specified by file_path for reading
    if (!file.is_open()) { // Check if the file was successfully opened
        BOOST_LOG_TRIVIAL(error) << "Failed to open file: " << file_path; // Log an error message if file opening fails
        return false; // Return false to indicate failure
    }

    std::string line;
    while (std::getline(file, line)) { // Read the file line by line
        data.push_back(line); // Add each line to the vector 'data'
    }

    file.close(); // Close the file after reading is complete
    return true; // Return true to indicate successful file reading
}

// Defines a function to write data from a vector of strings to a file
bool FileManager::WriteFile(const std::string& file_path, const std::vector<std::string>& data) {
    std::ofstream file(file_path); // Open the file specified by file_path for writing
    if (!file.is_open()) { // Check if the file was successfully opened
        BOOST_LOG_TRIVIAL(error) << "Failed to open file for writing: " << file_path; // Log an error message if file opening fails
        return false; // Return false to indicate failure
    }

    for (const auto& line : data) { // Loop through each element in the vector 'data'
        file << line << std::endl; // Write each line to the file followed by a newline
    }

    file.close(); // Close the file after writing is complete
    return true; // Return true to indicate successful file writing
}

// Defines a function to create a directory
bool FileManager::CreateDirectory(const std::string& dir_path) {
    if (!fs::exists(dir_path)) { // Check if the directory already exists
        if (!fs::create_directories(dir_path)) { // Attempt to create the directory if it doesn't exist
            BOOST_LOG_TRIVIAL(error) << "Failed to create directory: " << dir_path; // Log an error message if directory creation fails
            return false; // Return false to indicate failure
        }
    }
    return true; // Return true to indicate that the directory either exists or was created successfully
}
