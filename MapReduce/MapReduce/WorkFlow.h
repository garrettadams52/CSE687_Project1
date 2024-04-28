#ifndef WORKFLOW_H
#define WORKFLOW_H

#include <string>
#include "FileManagement.h"
#include "Map.h"

//This class manages the execution of the program that counts word instances in a directory of text files. To do this,
//it instantiates members of the FileManagement, Map, Sort, and Reduce classes, and then calls their member functions
//to carry out the tasks of the program.

class Workflow {
public:
    //Constructor which initializes file paths of input, temporary, and output directories
    Workflow(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir);
    //Instantiates members of the other classes in the program and makes calls to functions in these classes
    //to execute the program
    void run();

private:
    //Stores the full file path of the input directory
    std::string inputDirectory;
    //Stores the partial file path of the temporary directory
    std::string tempDirectory;
    //Stores the partial file name of the output directory
    std::string outputDirectory;
};

#endif // WORKFLOW_H
