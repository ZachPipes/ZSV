#include "zsv.h"

#include <fstream>
#include <iostream>

ZSV::ZSV(const std::string& filepath, const char delimiter)
: filepath(filepath), delimiter(delimiter) {}

void ZSV::read() {
    // Opens file stream for selected filename
    std::ifstream inputFile(filepath);

    // Checks if file stream is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file " << filepath << "!" << std::endl;
    }

    std::string line;
    // Obtains the headers
    if (std::getline(inputFile, line)) {
        std::string cell;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != delimiter) {
                cell += line[i];
            } else {
                headers[cell] = i;
                cell.clear();
            }
        }
    }

    // Goes through the csv file line-by-line
    int rowFlag = 0;
    while (std::getline(inputFile, line)) {
        // Adds row
        if (data.size() <= rowFlag) {
            data.push_back(std::vector<std::string>());
        }

        std::string cell;
        // Runs through each character in the line
        for (int i = 0; i < line.size(); i++) {
            // Separates strings by the delimiter
            if (line[i] != delimiter) {
                cell += line[i];
            } else {
                data[rowFlag].push_back(cell);
                cell.clear();
            }
        }

        // If the cell is not empty, add the cell
        if (!cell.empty()) {
            data[rowFlag].push_back(cell);
        }

        // Row flag
        rowFlag++;
    }

    inputFile.close();
}

void ZSV::write() const {
    // Opens file stream for selected filename
    std::ofstream outputFile(filepath);

    // Checks if file stream is open
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file " << filepath << "!" << std::endl;
    }

    // Writes headers to a csv file
    for (const std::pair<const std::string, int>& header : headers) {
        outputFile << header.first;
        if (headers.end()->second != header.second) {
            outputFile << ", ";
        } else {
            outputFile << std::endl;
        }
    }

    // Moves to the next line
    outputFile << std::endl;

    // Writes data to a csv file
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            outputFile << data[i][j];
            if (j != data[i].size() - 1) {
                outputFile << delimiter;
            }
        }
        // Moves to the next line
        outputFile << std::endl;
    }

    outputFile.close();
}

void ZSV::print() const {
    // Prints headers
    for (const std::pair<const std::string, int>& header : headers) {
        std::cout << header.first;
        if (headers.end()->second != header.second) {
            std::cout << ", ";
        } else {
            std::cout << std::endl;
        }
    }

    // Prints data
    for (int i = 0; i < data.size(); i++) { // By row
        for (int j = 0; j < data[i].size(); j++) { // By col
            std::cout << data[i][j];
            if (j == data[i].size() - 1) {
                std::cout << std::endl;
            } else {
                std::cout << ",";
            }
        }
    }
}

/// Getters and setters ///
void ZSV::setFilepath(const std::string& newFilepath) {
    filepath = newFilepath;
}
void ZSV::setDelimiter(const char newDelimiter) {
    delimiter = newDelimiter;
}
void ZSV::setHeaders(const std::unordered_map<std::string, int>& newHeaders) {
    headers = newHeaders;
}
void ZSV::setCell(const int row, const int y, const std::string& cell) {
    data[row][y] = cell;
}

std::string ZSV::getFilepath() const {
    return filepath;
}
char ZSV::getDelimiter() const {
    return delimiter;
}
std::unordered_map<std::string, int> ZSV::getHeaders() const {
    return headers;
}
std::string ZSV::getCell(const int row, const int col) const {
    return data[row][col];
}

/// UNFINISHED ///
/*std::vector<std::string> ZSV::getCol(const std::string& col) const {
    std::vector<std::string> col;
    // By row
    for (int row = 0; row < data.size(); row++) {
        // By col
        for (int j = 0; j < data[row].size(); j++) {}
    }

    return col;
}*/