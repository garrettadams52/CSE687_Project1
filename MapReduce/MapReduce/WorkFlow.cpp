#include "Workflow.h"
#include <iostream>
#include "Sort.h"
#include "Reduce.h"

 program-with-documentation
//This class manages the execution of the program that counts word instances in a directory of text files. To do this,
//it instantiates members of the FileManagement, Map, Sort, and Reduce classes, and then calls their member functions
//to carry out the tasks of the program.

//Constructor which initializes file paths of input, temporary, and output directories
Workflow::Workflow(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir)
    : inputDirectory(inputDir), tempDirectory(tempDir), outputDirectory(outputDir) {}

//Instantiates members of the other classes in the program and makes calls to functions in these classes
//to execute the program
void Workflow::run() {
    //Ensures that buffer will have a constant size
    size_t bufferSize = 1000;
    //Declares FileManagement object fileManagement and passes it the paths for the input, temporary, 
    //and output directories
    FileManagement fileManagement(inputDirectory, tempDirectory, outputDirectory);
    //Initializes a string vector with the names of the temporary directory and two output files
    std::vector<std::string> filesToClear = { "temp_output.txt", "final_output.txt", "sorted_aggregated_output.txt" };
    //Calls clearFiles member function of fileManagement to remove files with names listed above
    //if they aready exist at the path locations specified by the user
    fileManagement.clearFiles(tempDirectory, filesToClear);
    //Declares Map object mapper and passes fileManagement by pointer and bufferSize by value
    Map mapper(&fileManagement, bufferSize);
    //Declares Sort object sorter and passes fileManagement by pointer
    Sort sorter(&fileManagement);
    //Declares Reduce object Reducer and passes fileManagement by pointer
    Reduce reducer(&fileManagement);


    //Extracts individual files from the input directory via FileManagement member function getAllFiles
    auto files = fileManagement.getAllFiles();
    //If there are no files in the specified input directory, prints error message informing the user of
    //this fact

Workflow::Workflow(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir)
    : inputDirectory(inputDir), tempDirectory(tempDir), outputDirectory(outputDir) {}

void Workflow::run() {
    size_t bufferSize = 1000;
    FileManagement fileManagement(inputDirectory, tempDirectory, outputDirectory);

    std::vector<std::string> filesToClear = { "temp_output.txt", "final_output.txt", "sorted_aggregated_output.txt" };
    fileManagement.clearFiles(tempDirectory, filesToClear);
    Map mapper(&fileManagement, bufferSize);
    Sort sorter(&fileManagement);
    Reduce reducer(&fileManagement);



    auto files = fileManagement.getAllFiles();
 main
    if (files.empty()) {
        std::cerr << "No files found in the input directory: " << inputDirectory << std::endl;
        return;
    }
 program-with-documentation
    //Iterates through every file in the input directory
    for (const auto& file : files) {
        //Initializes lines to value of next file in the directory using FileManagement member
        //function readFile
        auto lines = fileManagement.readFile(file);
        //Iterates through ever line in the file "lines
        for (const auto& line : lines) {
            //Calls Map member function map (note lowercase name) and passes it a line of text from
            //the file to count and modify the word tokens in that line


    for (const auto& file : files) {
        auto lines = fileManagement.readFile(file);
        for (const auto& line : lines) {
 main
            mapper.map(file, line);  
        }
    }

program-with-documentation
    //Once every word token from every line and file has been counted and placed in a tuple,
    //calls Sort member function sortAndAggregate to sort the words alphabetically and place each word
    //in an n-tuple representing each occurrence of that word with a "1"
    sorter.sortAndAggregate();
    //Calls Reduce member function reduce (note lowercase name) to transform the n-tuples created by sortAndAggregate
    //into tuples containing a word and the number of its occurrences in all the files of the input directory

    sorter.sortAndAggregate();
 main
    reducer.reduce();

}
