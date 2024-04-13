
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "Validate.h"


//This class validates that an input file, output file, and temporary directory exist for a given read/write operation set.
//Though it is intended for use within a project which counts token frequency in written texts, it could easily be incorporated into
//any program which reads from one file and writes to another.


//Constructor which accepts and initializes file path names for an input file, output file, and
//temporary directory 
Validate::Validate(std::string inputFilePath, std::string outputFilePath, std::string tempDirPath) {

	//Uses this pointer to assign inputFilePath data member to value of argument with the same name
	this->inputFilePath = inputFilePath;
	//Uses this pointer to assign outputFilePath data member to value of argument with the same name
	this->outputFilePath = outputFilePath;
	//Uses this pointer to assign tempDirPath data member to value of argument with the same name
	this->tempDirPath = tempDirPath;

	//Calls validateInputFile to determine if input file exists
	validateInputFile();
	//Calls createOutputFile to generate an output file
	createOutputFile();
	//Calls createTemDir to generate a temporary directory
	createTempDir();
}

//Class destructor
Validate::~Validate() {

	//Sets each data member to the value of an empty string 
	inputFilePath = "";
	outputFilePath = "";
	tempDirPath = "";

}

//Checks if input file exists. Throws an exception if no file exists at the path name location.
void Validate::validateInputFile() {

	//Declares new ifstream variable inputFile and associates it with specified input file
	std::ifstream inputFile(inputFilePath);

	//Attempts to connect inputFile to an input given the full path name
	inputFile.open(inputFilePath);

	//If open failed, throws exception informing the user that the "input file does not exist
	//at the specified location"
	if (!(inputFile.is_open())) {
		throw std::invalid_argument("Error: input file does not exist at the specified location\n");
	}
	else {
		//If open succeeded, prints message informing user of this
		std::cout << "Input file opened successfully\n";
		//Closes output file so that function does not interfere with Map class's
		//attempt to open the same file.
		inputFile.close();
	}

}


//Creates a new output file at the path name location and with the specified name
void Validate::createOutputFile() {

	//Declares new ofstream variable outputFile and associates it with the location 
	//specified by outputFilePath
	std::ofstream outputFile(outputFilePath);
	//Prints message informing user that new output file was created
	std::cout << "Output file created successfully\n";
	//Closes output file so that function does not interfere with Map class's
	//attempt to open the same file.
	outputFile.close();
	
}

//Creates a new temporary directory at the path name location and with the specified name
void Validate::createTempDir() {

	//Declares new ofstream variable tempDir and associates it with the location 
	//specified by tempDirPath
	std::ofstream tempDir(tempDirPath);
	//Prints message informing user that new temporary directory was created
	std::cout << "Temporary directory created successfully\n";
	//Closes temporary directory so that function does not interfere with Map class's
	//attempt to open the same file.
	tempDir.close();
}