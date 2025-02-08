#ifndef ZSV_LIBRARY_H
#define ZSV_LIBRARY_H

#include <string>
#include <vector>
#include <unordered_map>

class ZSV {
    // Path to the file
    std::string filepath;

    // Character such as ',' that defines limits between cells
    char delimiter{};

    // Headers for all columns
    std::unordered_map<std::string, int> headers;

    // Table of strings, all data for each csv file
    std::vector<std::vector<std::string>> data;

public:
    // Creates an instance of a ZSV object with the specified filepath and delimiter
    explicit ZSV(const std::string& filepath, char delimiter=',');

    // Reads a csv file
    void read();

    // Writes a csv file
    void write() const;

    // Prints out a csv file
    void print() const;

    /// Getters and setters ///
    void setFilepath(const std::string& newFilepath);
    void setDelimiter(char newDelimiter);
    void setHeaders(const std::unordered_map<std::string, int>& newHeaders);
    void setCell(int row, int y, const std::string& cell);

    [[nodiscard]] std::string getFilepath() const;
    [[nodiscard]] char getDelimiter() const;
    [[nodiscard]] std::unordered_map<std::string, int> getHeaders() const;
    [[nodiscard]] std::string getCell(int row, int col) const;
    //[[nodiscard]] std::vector<std::string> ZSV::getCol(const std::string& col) const;
};

#endif //ZSV_LIBRARY_H