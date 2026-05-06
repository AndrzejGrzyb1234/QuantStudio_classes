#pragma once

#include <cstddef>
#include <string>

#include "Matrix.h"

/**
 * @brief Reads matrix dimensions and values from the console.
 */
class MatrixInputReader
{
public:
    /**
     * @brief Reads a matrix with user-defined row and column counts.
     * @param matrixName Name shown in prompts, for example "A" or "B".
     * @return Matrix filled with user-provided values.
     */
    Matrix readMatrix(const char* matrixName) const;

    /**
     * @brief Reads a matrix with fixed dimensions required by an operation.
     * @param matrixName Name shown in prompts, for example "A" or "B".
     * @param rowCount Required number of rows.
     * @param columnCount Required number of columns.
     * @return Matrix filled with user-provided values.
     */
    Matrix readMatrix(const char* matrixName,
        std::size_t rowCount,
        std::size_t columnCount) const;

    /**
     * @brief Reads a matrix whose row count is fixed but column count is user-defined.
     * @param matrixName Name shown in prompts, for example "A" or "B".
     * @param rowCount Required number of rows.
     * @return Matrix filled with user-provided values.
     */
    Matrix readMatrixWithRequiredRowCount(const char* matrixName,
        std::size_t rowCount) const;

private:
    /**
     * @brief Reads a positive matrix dimension from the console.
     * @param prompt Message shown before the user enters the value.
     * @return Positive dimension value.
     */
    std::size_t readPositiveSize(const std::string& prompt) const;

    /**
     * @brief Reads a numeric matrix element from the console.
     * @param prompt Message shown before the user enters the value.
     * @return Entered matrix element.
     */
    double readNumber(const std::string& prompt) const;

    /**
     * @brief Fills every element of the provided matrix with console input.
     * @param matrix Matrix that will receive the entered values.
     * @param matrixName Name shown in prompts.
     */
    void populateMatrixValues(Matrix& matrix, const char* matrixName) const;

    /**
     * @brief Clears the failed input state and discards the rest of the line.
     */
    void resetInputStream() const;
};
