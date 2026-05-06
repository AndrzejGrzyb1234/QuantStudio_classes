#pragma once

#include <cstddef>
#include <initializer_list>
#include <iosfwd>
#include <vector>

/**
 * @brief Represents a mathematical matrix and its basic arithmetic operations.
 */
class Matrix
{
public:
    /**
     * @brief Creates an empty matrix.
     */
    Matrix() = default;

    /**
     * @brief Creates a matrix with the requested dimensions filled with zeros.
     * @param rowCount Number of rows.
     * @param columnCount Number of columns.
     */
    Matrix(std::size_t rowCount, std::size_t columnCount);

    /**
     * @brief Creates a matrix from a nested vector representation.
     * @param values Rectangular matrix data.
     */
    Matrix(const std::vector<std::vector<double>>& values);

    /**
     * @brief Creates a matrix from brace-initialized rows.
     * @param values Rectangular matrix data.
     */
    Matrix(std::initializer_list<std::initializer_list<double>> values);

    /**
     * @brief Returns the number of matrix rows.
     */
    std::size_t rowCount() const noexcept;

    /**
     * @brief Returns the number of matrix columns.
     */
    std::size_t columnCount() const noexcept;

    /**
     * @brief Returns a mutable reference to the selected matrix element.
     * @param rowIndex Zero-based row index.
     * @param columnIndex Zero-based column index.
     */
    double& at(std::size_t rowIndex, std::size_t columnIndex);

    /**
     * @brief Returns the selected matrix element.
     * @param rowIndex Zero-based row index.
     * @param columnIndex Zero-based column index.
     */
    double at(std::size_t rowIndex, std::size_t columnIndex) const;

    /**
     * @brief Adds two matrices of the same shape.
     * @param other Matrix added to the current matrix.
     * @return Sum of both matrices.
     */
    Matrix operator+(const Matrix& other) const;

    /**
     * @brief Multiplies two dimension-compatible matrices.
     * @param other Matrix multiplied by the current matrix.
     * @return Product of both matrices.
     */
    Matrix operator*(const Matrix& other) const;

private:
    /**
     * @brief Verifies that all rows contain the same number of columns.
     */
    void validateRectangularShape() const;

    std::vector<std::vector<double>> _values;
};

/**
 * @brief Prints the matrix in a row-by-row console format.
 * @param output Target output stream.
 * @param matrix Matrix to be printed.
 * @return The same output stream to support operator chaining.
 */
std::ostream& operator<<(std::ostream& output, const Matrix& matrix);
