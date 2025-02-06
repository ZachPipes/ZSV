#include "library.h"

#include <fstream>
#include <iostream>

ZSV::ZSV(const std::string& filename, char delimiter)
: filename(filename), delimiter(delimiter) {}

void ZSV::read() {
    // Opens file stream for selected filename
    std::ifstream inputFile(filename);

    // Checks if file stream is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file " << filename << "!" << std::endl;
    }

    // Goes through the csv file line-by-line
    std::string line;
    while (std::getline(inputFile, line)) {
        //std::vector<std::vector<std::string>> data;

        for (int c = 0; c < line.size(); c++) {
            // Separates strings by the delimiter
            if (line[c] != delimiter) {
                data[][] =
            } else {

            }
        }
    }
}