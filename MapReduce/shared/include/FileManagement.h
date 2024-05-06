#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include "IFileManagement.h"
#include <string>
#include <filesystem>
#include <vector>

class FileManagement : public IFileManagement {
public:
    FileManagement(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir);

    std::vector<std::string> getAllFiles() const override;
    std::vector<std::string> readFile(const std::string& filePath) const override;
    void clearFiles(const std::string& dirPath, const std::vector<std::string>& fileNames) override;
    void writeFile(const std::string& filePath, const std::string& content, bool append = true) override;
    void createEmptyFile(const std::string& filePath) override;

    std::string getTempDirectory() const override;
    std::string getOutputDirectory() const override;

private:
    std::string inputDirectory;
    std::string tempDirectory;
    std::string outputDirectory;
};

#endif // FILEMANAGEMENT_H
