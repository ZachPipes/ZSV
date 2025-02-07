#ifndef ZSV_LIBRARY_H
#define ZSV_LIBRARY_H

#include <string>
#include <vector>

class ZSV {
    // Path to the file
    std::string filepath;

    // Character such as ',' that defines limits between cells
    char delimiter{};

    // Headers for all columns
    std::vector<std::string> headers;

    // Table of strings, all data for each csv file
    std::vector<std::vector<std::string>> data;

public:
    // Creates an instance of a ZSV object with the specified filepath and delimiter
    explicit ZSV(const std::string& filepath, char delimiter=',');

    // Reads a csv file
    void read();

    // Writes a csv file
    void write(std::vector<std::string> headers, const std::vector<std::vector<std::string>>& data);

    // Prints out a csv file
    void print() const;
};

#endif //ZSV_LIBRARY_H