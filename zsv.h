#ifndef ZSV_LIBRARY_H
#define ZSV_LIBRARY_H

#include <string>
#include <vector>

class ZSV {
    // Filepath
    std::string filepath;
    char delimiter{};
    std::vector<std::vector<std::string>> data;

public:
    explicit ZSV(const std::string& filepath, char delimiter=',');
    void read();
    void print() const;
};

#endif //ZSV_LIBRARY_H