#pragma once

#include <fstream>
#include <string>

//This class validates that an input file, output file, and temporary directory exist for a given read/write operation set.
//Though it is intended for use within a project which counts token frequency in written texts, it could easily be incorporated into
//any program which reads from one file and writes to another.

class Validate {
public:
	//Constructor which accepts and initializes file path names for an input file, output file, and
	//temporary directory 
	Validate(std::string inputFilePath, std::string outputFilePath, std::string tempDirPath);
	//Class destructor
	~Validate();
	//Checks if input file exists. Throws an exception if no file exists at the path name location
	void validateInputFile();
	//Creates a new output file at the path name location and with the specified name
	void createOutputFile();
	//Creates a new temporary directory at the path name location and with the specified name
	void createTempDir();

private:
	//Stores file path for input file
	std::string inputFilePath;
	//Stores file path for output file
	std::string outputFilePath;
	//Stores file path for temporary directory
	std::string tempDirPath;
};