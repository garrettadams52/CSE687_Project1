#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <string>
#include <vector>

class FileManagement {
public:
    // Constructor and Destructor
    FileManagement();
    ~FileManagement();

    // Methods
    std::vector<std::string> readFileLines(const std::string& filePath);
    void writeFileLines(const std::string& filePath, const std::vector<std::string>& lines);
    std::vector<std::string> listFilesInDirectory(const std::string& directoryPath);
};

#endif // FILEMANAGEMENT_H
