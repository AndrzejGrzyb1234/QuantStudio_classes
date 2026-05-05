#ifndef CSVREADER_H
#define CSVREADER_H

#include <vector>
#include <string>

/**
 * @brief Utility class for loading paired numerical data from a CSV file.
 */
class CsvReader {
public:
    /**
     * @brief Loads two-column numerical data from a CSV file.
     * @param filename Name of the CSV file to be read.
     * @param x Output vector of abscissae.
     * @param y Output vector of ordinates.
     */
    static void load(const std::string& filename,
        std::vector<double>& x,
        std::vector<double>& y);
};

#endif
