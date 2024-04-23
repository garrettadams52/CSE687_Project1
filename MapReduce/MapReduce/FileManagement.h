#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <string>
#include <vector>

class FileManagement {
public:
    FileManagement(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir);

    std::vector<std::string> getAllFiles() const;
    std::vector<std::string> readFile(const std::string& filePath) const;
    void writeToTemp(const std::string& fileName, const std::string& content) const;
    void writeToOutput(const std::string& fileName, const std::string& content) const;
    bool checkDirectory(const std::string& dir) const;
    void clearDirectory(const std::string& dirPath);


    // Getter for temporary directory
    std::string getTempDirectory() const;

private:
    std::string inputDirectory;
    std::string tempDirectory;
    std::string outputDirectory;
};

#endif // FILEMANAGEMENT_H
