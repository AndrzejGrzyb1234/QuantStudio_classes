#include "MatrixConsoleApplication.h"

#include <iostream>
#include <limits>

#include "Matrix.h"

void MatrixConsoleApplication::run() const
{
    runSelectedOperation();
}

void MatrixConsoleApplication::runSelectedOperation() const
{
    std::cout << "Select the matrix operation:\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Multiplication\n";
    std::cout << "Choice: ";

    const int operationChoice = readChoiceOrDefault(
        1,
        "Invalid input. Matrix addition will be used by default.");

    switch (operationChoice)
    {
    case 1:
        runAdditionWorkflow();
        break;
    case 2:
        runMultiplicationWorkflow();
        break;
    default:
        std::cout << "Invalid choice. Matrix addition will be used by default.\n\n";
        runAdditionWorkflow();
        break;
    }
}

void MatrixConsoleApplication::runAdditionWorkflow() const
{
    std::cout << "You selected matrix addition.\n\n";

    const Matrix matrixA = _matrixInputReader.readMatrix("A");
    const Matrix matrixB = _matrixInputReader.readMatrix(
        "B",
        matrixA.rowCount(),
        matrixA.columnCount());
    const Matrix result = matrixA + matrixB;

    std::cout << "This is A" << matrixA;
    std::cout << "This is B" << matrixB;
    std::cout << "This is A + B" << result << '\n';
}

void MatrixConsoleApplication::runMultiplicationWorkflow() const
{
    std::cout << "You selected matrix multiplication.\n\n";

    const Matrix matrixA = _matrixInputReader.readMatrix("A");
    const Matrix matrixB = _matrixInputReader.readMatrixWithRequiredRowCount(
        "B",
        matrixA.columnCount());
    const Matrix result = matrixA * matrixB;

    std::cout << "This is A" << matrixA;
    std::cout << "This is B" << matrixB;
    std::cout << "This is A * B" << result << '\n';
}

int MatrixConsoleApplication::readChoiceOrDefault(int defaultChoice,
    const char* invalidInputMessage) const
{
    int choice = 0;

    // "Invalid input" means std::cin could not parse a number at all, for
    // example when the user enters text instead of a numeric menu option.
    // "Invalid choice" is handled later, when the parsed number is outside the
    // supported menu range.
    if (!(std::cin >> choice))
    {
        resetInputStream();
        std::cout << invalidInputMessage << "\n\n";
        return defaultChoice;
    }

    std::cout << '\n';
    return choice;
}

void MatrixConsoleApplication::resetInputStream() const
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
