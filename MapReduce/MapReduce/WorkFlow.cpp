#include "Workflow.h"
#include "Sort.h"
#include "Reduce.h"
#include <iostream>

Workflow::Workflow(const std::string& inputDir, const std::string& tempDir, const std::string& outputDir)
    : inputDirectory(inputDir), 
    tempDirectory(tempDir), 
    outputDirectory(outputDir), 
    fileManagement(inputDir, tempDir, outputDir),
    hMapDll(nullptr), 
    mapInstance(nullptr) {
    
    const wchar_t* libName = L"MapLibrary";  // Make sure this matches the DLL file name
    hMapDll = LoadLibraryEx(libName, NULL, LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
    if (hMapDll != NULL) {
        std::cout << "DLL loaded successfully." << std::endl;
        CreateMap = (funcCreateMap)GetProcAddress(hMapDll, "CreateMap");
        DeleteMap = (funcDeleteMap)GetProcAddress(hMapDll, "DeleteMap");
        MapAddContent = (funcMapAddContent)GetProcAddress(hMapDll, "MapAddContent");
        MapFlushBuffer = (funcMapFlushBuffer)GetProcAddress(hMapDll, "MapFlushBuffer");

        if (CreateMap && DeleteMap && MapAddContent && MapFlushBuffer) {
            fileManagement = FileManagement(inputDir, tempDir, outputDir);
            mapInstance = CreateMap(&fileManagement, 1000);
        }
        else {
            std::cerr << "Failed to load function pointers from DLL." << std::endl;
        }
    }
    else {
        std::cerr << "Failed to load DLL." << std::endl;
    }
}

Workflow::~Workflow() {
    if (mapInstance && DeleteMap) {
        DeleteMap(mapInstance);
    }
    if (hMapDll) {
        FreeLibrary(hMapDll);
    }
}

void Workflow::run() {
    std::cout << "Workflow started." << std::endl;

    // Clear temporary and output files before starting the process
    std::vector<std::string> filesToClear = { "temp_output.txt", "final_output.txt", "sorted_aggregated_output.txt" };
    fileManagement.clearFiles(tempDirectory, filesToClear);

    // Instantiate the map, sort, and reduce components
    if (!mapInstance && CreateMap) {
        mapInstance = CreateMap(&fileManagement, 1000);
    }

    Sort sorter(&fileManagement);  
    Reduce reducer(&fileManagement);  

    // Process files
    auto files = fileManagement.getAllFiles();
    if (files.empty()) {
        std::cerr << "No files found in the input directory: " << inputDirectory << std::endl;
        return;
    }

    for (const auto& file : files) {
        std::cout << "Processing file: " << file << std::endl;
        auto lines = fileManagement.readFile(file);
        for (const auto& line : lines) {
            if (MapAddContent && mapInstance) {
                MapAddContent(mapInstance, file, line);
            }
        }
    }

    // Ensure all mapped data is flushed
    if (MapFlushBuffer && mapInstance) {
        MapFlushBuffer(mapInstance);
    } 

    // Sorting and aggregation
    sorter.sortAndAggregate();

    // Reducing
    reducer.reduce();

    std::cout << "Workflow completed." << std::endl;
}

