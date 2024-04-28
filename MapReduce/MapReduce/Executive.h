#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Workflow.h"
#include <string>

 program-with-documentation
//This class exists at the highest level of the program's architecture. It uses the Workflow and FileManagement classes
//to run the word token count program, then creates a dummy program to inform the user of whether the program's execution
//succeeded or failed


class Executive {
public:
    //Class constructor which initializes WorkFlow object workflow and FileManagement object fileManagement,
    //passing each of them the file path names for input, temporary, and output directories

class Executive {
public:
 main
    Executive(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir);
    void run();

private:
program-with-documentation
    //Worflow object used to run the program
    Workflow workflow;
    //FileManagment class used to ensure that files are successfully created and properly accessed
    FileManagement fileManagement;
    //Creates a file to mark the successful execution of the program, then prints a message informing the
    //user of its creation. Helper function to Executive::run.

    Workflow workflow;
    FileManagement fileManagement;
 main
    void markSuccess();
};

#endif // EXECUTIVE_H