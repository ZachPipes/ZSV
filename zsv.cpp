#include "zsv.h"

#include <fstream>
#include <iostream>

ZSV::ZSV(const std::string& filepath, char delimiter)
: filepath(filepath), delimiter(delimiter) {}

void ZSV::read() {
    // Opens file stream for selected filename
    std::ifstream inputFile(filepath);

    // Checks if file stream is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file " << filepath << "!" << std::endl;
    }

    // Goes through the csv file line-by-line
    std::string line;
    int rowFlag = 0;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
        /// std::vector<std::vector<std::string>> data; ///
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

        if (!cell.empty()) {
            data[rowFlag].push_back(cell);
        }

        // Row flag
        rowFlag++;
    }

    inputFile.close();
}

void ZSV::print() const {
    // By row
    for (int i = 0; i < data.size(); i++) {
        // By col
        for (int j = 0; j < data[i].size(); j++) {
            if (j = data[i].size() - 1) {
                std::cout << data[i][j] << std::endl;
            } else {
                std::cout << data[i][j] << ",";
            }
        }
    }
}