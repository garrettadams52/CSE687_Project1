#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <string>
#include <filesystem>
#include <vector>

//This class performs tasks related to the creation, duplication, and deletion of files used by other classes in the program,
//and ensuring that the actions performed on these files were successful.

class FileManagement {
public:
    //Class constructor which initializes data members with the file path names for the input, temporary, and output directories
    FileManagement(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir);
    //Extracts files from the input directory and pushes them onto a vector for use by a Map class object
    std::vector<std::string> getAllFiles() const;
    //Initializes an ifstream with the name filePath, copies the contents of the file at that location into a local variable
    //and returns the duplicate to a caller
    std::vector<std::string> readFile(const std::string& filePath) const;
    void clearFiles(const std::string& dirPath, const std::vector<std::string>& fileNames);
    void writeFile(const std::string& filePath, const std::string& content, bool append = true);
    void createEmptyFile(const std::string& filePath);


    //Returns the file path for the temporary directory to a caller
    std::string getTempDirectory() const;
    //Returns the file path for the output directory to a caller
    std::string getOutputDirectory() const;



private:
    //Full file path of the input directory
    std::string inputDirectory;
    //File path specifying the location of the temporary directory
    std::string tempDirectory;
    //File path specifying the location of the output directory
    std::string outputDirectory;
};

#endif // FILEMANAGEMENT_H
