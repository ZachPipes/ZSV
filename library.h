#ifndef ZSV_LIBRARY_H
#define ZSV_LIBRARY_H

#include <string>
#include <vector>

class ZSV {
    std::string filename;
    char delimiter{};
    std::vector<std::vector<std::string>> data;

public:
    explicit ZSV(const std::string& filename, char delimiter=',');
    void read();
};

#endif //ZSV_LIBRARY_H