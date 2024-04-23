#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <fstream>

class FileManager {
private:   
    std::vector<std::string> buffer;
    std::size_t bufferSize;

    void flushBuffer(const std::string& filePath, bool append = false);

public:
    FileManager(std::size_t bufferSize = 1024);
    ~FileManager();

    std::string readLine(const std::string& filePath);
    void writeBufferToFile(const std::string& data, const std::string& filePath);
};

#endif // FILEMANAGER_H
