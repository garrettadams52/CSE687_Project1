#ifndef BASE_MAPPER_H
#define BASE_MAPPER_H

#ifdef MAPLIBRARY_EXPORTS
#define MAPLIBRARY_API __declspec(dllexport)
#else
#define MAPLIBRARY_API __declspec(dllimport)
#endif

#include <string>
#include <IFileManagement.h>  

class MAPLIBRARY_API BaseMapper {  
public:
    virtual void map(const std::string& fileName, const std::string& content) = 0;
    virtual ~BaseMapper() {}
};

#endif // BASE_MAPPER_H
