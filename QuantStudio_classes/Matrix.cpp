#include "Matrix.h"

#include <ostream>
#include <stdexcept>

Matrix::Matrix(std::size_t rowCount, std::size_t columnCount)
    : _values(rowCount, std::vector<double>(columnCount, 0.0))
{
}

Matrix::Matrix(const std::vector<std::vector<double>>& values)
    : _values(values)
{
    validateRectangularShape();
}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> values)
{
    for (const auto& row : values)
    {
        _values.emplace_back(row);
    }

    validateRectangularShape();
}

std::size_t Matrix::rowCount() const noexcept
{
    return _values.size();
}

std::size_t Matrix::columnCount() const noexcept
{
    if (_values.empty())
    {
        return 0;
    }

    return _values.front().size();
}

double& Matrix::at(std::size_t rowIndex, std::size_t columnIndex)
{
    return _values.at(rowIndex).at(columnIndex);
}

double Matrix::at(std::size_t rowIndex, std::size_t columnIndex) const
{
    return _values.at(rowIndex).at(columnIndex);
}

Matrix Matrix::operator+(const Matrix& other) const
{
    if (rowCount() != other.rowCount() || columnCount() != other.columnCount())
    {
        throw std::invalid_argument("Matrix addition requires both matrices to have the same dimensions.");
    }

    Matrix result(rowCount(), columnCount());

    for (std::size_t rowIndex = 0; rowIndex < rowCount(); ++rowIndex)
    {
        for (std::size_t columnIndex = 0; columnIndex < columnCount(); ++columnIndex)
        {
            result.at(rowIndex, columnIndex) = at(rowIndex, columnIndex) + other.at(rowIndex, columnIndex);
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& other) const
{
    if (columnCount() != other.rowCount())
    {
        throw std::invalid_argument("Matrix multiplication requires the first matrix column count to match the second matrix row count.");
    }

    // The result starts with zeros so every partial product can be accumulated
    // directly into the correct output cell.
    Matrix result(rowCount(), other.columnCount());

    for (std::size_t rowIndex = 0; rowIndex < rowCount(); ++rowIndex)
    {
        for (std::size_t sharedIndex = 0; sharedIndex < columnCount(); ++sharedIndex)
        {
            for (std::size_t columnIndex = 0; columnIndex < other.columnCount(); ++columnIndex)
            {
                result.at(rowIndex, columnIndex) += at(rowIndex, sharedIndex) * other.at(sharedIndex, columnIndex);
            }
        }
    }

    return result;
}

void Matrix::validateRectangularShape() const
{
    if (_values.empty())
    {
        return;
    }

    const std::size_t expectedColumnCount = _values.front().size();

    for (const auto& row : _values)
    {
        if (row.size() != expectedColumnCount)
        {
            throw std::invalid_argument("Matrix rows must all contain the same number of columns.");
        }
    }
}

std::ostream& operator<<(std::ostream& output, const Matrix& matrix)
{
    if (matrix.rowCount() == 0 || matrix.columnCount() == 0)
    {
        output << "\n[ empty matrix ]\n";
        return output;
    }

    output << '\n';

    for (std::size_t rowIndex = 0; rowIndex < matrix.rowCount(); ++rowIndex)
    {
        output << "[ ";

        for (std::size_t columnIndex = 0; columnIndex < matrix.columnCount(); ++columnIndex)
        {
            output << matrix.at(rowIndex, columnIndex);

            if (columnIndex + 1 < matrix.columnCount())
            {
                output << ' ';
            }
        }

        output << " ]\n";
    }

    return output;
}
