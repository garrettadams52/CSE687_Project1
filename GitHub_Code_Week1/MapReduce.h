#ifndef MAPREDUCE_H
#define MAPREDUCE_H

#include <string>
#include <unordered_map>
#include <vector>

class FileManager {
public:
    static bool ReadFile(const std::string& file_path, std::vector<std::string>& data);
    static bool WriteFile(const std::string& file_path, const std::vector<std::string>& data);
    static bool CreateDirectory(const std::string& dir_path);
};

class Map {
public:
    void map(const std::string& input_file, const std::string& temp_dir);
};

class Reduce {
public:
    void reduce(const std::string& temp_file, const std::string& output_dir);
};

class Workflow {
private:
    Map mapper;
    Reduce reducer;

public:
    void execute(const std::string& input_dir, const std::string& output_dir, const std::string& temp_dir);
};

class Executive {
public:
    int run(int argc, char* argv[]);
};

#endif // MAPREDUCE_H
