#include "MatrixInputReader.h"

#include <iostream>
#include <limits>
#include <string>

Matrix MatrixInputReader::readMatrix(const char* matrixName) const
{
    const std::size_t rowCount = readPositiveSize(
        "Enter the number of rows for Matrix " + std::string(matrixName) + ": ");
    const std::size_t columnCount = readPositiveSize(
        "Enter the number of columns for Matrix " + std::string(matrixName) + ": ");

    Matrix matrix(rowCount, columnCount);
    populateMatrixValues(matrix, matrixName);
    return matrix;
}

Matrix MatrixInputReader::readMatrix(const char* matrixName,
    std::size_t rowCount,
    std::size_t columnCount) const
{
    std::cout << "Matrix " << matrixName << " must have "
        << rowCount << " rows and " << columnCount
        << " columns for this operation.\n\n";

    Matrix matrix(rowCount, columnCount);
    populateMatrixValues(matrix, matrixName);
    return matrix;
}

Matrix MatrixInputReader::readMatrixWithRequiredRowCount(const char* matrixName,
    std::size_t rowCount) const
{
    std::cout << "Matrix " << matrixName << " must have "
        << rowCount << " rows for this multiplication.\n\n";

    const std::size_t columnCount = readPositiveSize(
        "Enter the number of columns for Matrix " + std::string(matrixName) + ": ");

    Matrix matrix(rowCount, columnCount);
    populateMatrixValues(matrix, matrixName);
    return matrix;
}

std::size_t MatrixInputReader::readPositiveSize(const std::string& prompt) const
{
    while (true)
    {
        std::cout << prompt;

        long long value = 0;

        // "Invalid input" means the stream could not parse an integer at all.
        // "Invalid choice" means the parsed number is not a valid dimension.
        if (!(std::cin >> value))
        {
            resetInputStream();
            std::cout << "\nInvalid input. Please enter a positive integer.\n\n";
            continue;
        }

        std::cout << '\n';

        if (value <= 0)
        {
            std::cout << "Invalid choice. Please enter a positive integer.\n\n";
            continue;
        }

        return static_cast<std::size_t>(value);
    }
}

double MatrixInputReader::readNumber(const std::string& prompt) const
{
    while (true)
    {
        std::cout << prompt;

        double value = 0.0;

        // Matrix elements accept any numeric value, so only parsing failures
        // need to be rejected here.
        if (!(std::cin >> value))
        {
            resetInputStream();
            std::cout << "\nInvalid input. Please enter a numeric value.\n\n";
            continue;
        }

        return value;
    }
}

void MatrixInputReader::populateMatrixValues(Matrix& matrix, const char* matrixName) const
{
    std::cout << "Enter the values for Matrix " << matrixName << ":\n";

    for (std::size_t rowIndex = 0; rowIndex < matrix.rowCount(); ++rowIndex)
    {
        for (std::size_t columnIndex = 0; columnIndex < matrix.columnCount(); ++columnIndex)
        {
            matrix.at(rowIndex, columnIndex) = readNumber(
                "Value [" + std::to_string(rowIndex + 1) + "][" + std::to_string(columnIndex + 1) + "]: ");
        }
    }

    std::cout << "\n";
}

void MatrixInputReader::resetInputStream() const
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
