#include "CsvReader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

void CsvReader::load(const std::string& filename,
    std::vector<double>& x,
    std::vector<double>& y)
{
    std::ifstream file(filename);
    std::string line;
    size_t lineNumber = 0;

    if (!file.is_open())
        throw std::runtime_error("Unable to open the CSV file: " + filename);

    x.clear();
    y.clear();

    while (std::getline(file, line))
    {
        ++lineNumber;

        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string xs, ys;

        // Interpret each non-empty row as a single x,y pair.
        if (!std::getline(ss, xs, ',') || !std::getline(ss, ys))
            throw std::runtime_error("Invalid CSV row format at line " + std::to_string(lineNumber) + " in file: " + filename);

        x.push_back(std::stod(xs));
        y.push_back(std::stod(ys));
    }

    if (x.empty())
        throw std::runtime_error("The CSV file does not contain any data: " + filename);
}
