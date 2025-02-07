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

    std::string line;
    // Obtains the headers
    if (std::getline(inputFile, line)) {
        std::string cell;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != delimiter) {
                cell += line[i];
            } else {
                headers.push_back(cell);
                cell.clear();
            }
        }

        // If the cell is not empty, add the cell
        if (!cell.empty()) {
            headers.push_back(cell);
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

void ZSV::write() {

}

void ZSV::print() const {
    // Prints headers
    for (int i = 0; i < headers.size(); i++) {
        std::cout << headers[i];
        if (i == headers.size() - 1) {
            std::cout << std::endl;
        } else {
            std::cout <<",";
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