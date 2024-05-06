// IMapReduce.h
#pragma once
#include <string>

class IMapReduce {
public:
    virtual void execute(const std::string& input, std::string& output) = 0;
    virtual ~IMapReduce() {}
};

