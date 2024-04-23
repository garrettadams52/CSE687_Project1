#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <string>
#include <vector>

class FileManagement {
public:
    FileManagement(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir);

    std::vector<std::string> getAllFiles() const;
    std::vector<std::string> readFile(const std::string& filePath) const;
    void clearFiles(const std::string& dirPath, const std::vector<std::string>& fileNames);
    void writeFile(const std::string& filePath, const std::string& content, bool append = true);
    void createEmptyFile(const std::string& filePath);


    // Getter for temporary directory
    std::string getTempDirectory() const;
    std::string getOutputDirectory() const;



private:
    std::string inputDirectory;
    std::string tempDirectory;
    std::string outputDirectory;
};

#endif // FILEMANAGEMENT_H
