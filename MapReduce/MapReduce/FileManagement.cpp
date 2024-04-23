#include "FileManagement.h"
#include <iostream>

FileManager::FileManager(std::size_t bufferSize)
    : bufferSize(bufferSize) {}

FileManager::~FileManager() {}

std::string FileManager::readLine(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
        return "";
    }

    if (std::getline(file, line)) {
        return line;
    }
    file.close();

    return "";
}

void FileManager::writeBufferToFile(const std::string& data, const std::string& filePath) {
    buffer.push_back(data);

    if (buffer.size() >= bufferSize) {
        flushBuffer(filePath);
    }
}

void FileManager::flushBuffer(const std::string& filePath, bool append) {
    std::ofstream file(filePath, append ? std::ios::app : std::ios::out);

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
        return;
    }

    for (const auto& line : buffer) {
        file << line << std::endl;
    }

    buffer.clear();
    file.close();
}
