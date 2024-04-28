#include "Executive.h"
#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>


namespace fs = std::filesystem;


int main() {
    std::string inputLine;
    std::string inputDirectory, tempDirectory, outputDirectory;

    std::cout << "Enter the input file path, temporary directory, and output directory separated by spaces.\n";
    std::cout << "Example: C:\\Path\\To\\InputFiles C:\\Path\\To\\Temp C:\\Path\\To\\Output\n";
    std::getline(std::cin, inputLine);

    std::istringstream iss(inputLine);
    if (!(iss >> inputDirectory >> tempDirectory >> outputDirectory)) {
        std::cerr << "Error: You must enter exactly three paths separated by spaces." << std::endl;
        return 1;
    }


    if (!fs::exists(inputDirectory) || !fs::is_directory(inputDirectory)) {
        std::cerr << "Error: The specified input directory does not exist or is not accessible: \"" << inputDirectory << "\"\n";
        return 1;
    }

    Executive exec(inputDirectory, tempDirectory, outputDirectory);

    exec.run();

    return 0;
}
