#include "MapReduce.h"
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>

namespace fs = boost::filesystem;

bool FileManager::ReadFile(const std::string& file_path, std::vector<std::string>& data) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        BOOST_LOG_TRIVIAL(error) << "Failed to open file: " << file_path;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        data.push_back(line);
    }

    file.close();
    return true;
}

bool FileManager::WriteFile(const std::string& file_path, const std::vector<std::string>& data) {
    std::ofstream file(file_path);
    if (!file.is_open()) {
        BOOST_LOG_TRIVIAL(error) << "Failed to open file for writing: " << file_path;
        return false;
    }

    for (const auto& line : data) {
        file << line << std::endl;
    }

    file.close();
    return true;
}

bool FileManager::CreateDirectory(const std::string& dir_path) {
    if (!fs::exists(dir_path)) {
        if (!fs::create_directories(dir_path)) {
            BOOST_LOG_TRIVIAL(error) << "Failed to create directory: " << dir_path;
            return false;
        }
    }
    return true;
}
