#pragma once

#include "MatrixInputReader.h"

/**
 * @brief Handles the console workflow for matrix operations.
 */
class MatrixConsoleApplication
{
public:
    /**
     * @brief Runs one matrix operation cycle.
     */
    void run() const;

private:
    /**
     * @brief Reads the matrix operation menu and executes the selected branch.
     */
    void runSelectedOperation() const;

    /**
     * @brief Reads two compatible matrices and prints their sum.
     */
    void runAdditionWorkflow() const;

    /**
     * @brief Reads two compatible matrices and prints their product.
     */
    void runMultiplicationWorkflow() const;

    /**
     * @brief Reads a numeric menu choice and falls back to a default on invalid input.
     * @param defaultChoice Choice used when the input cannot be parsed.
     * @param invalidInputMessage Message printed when parsing fails.
     * @return Parsed choice or the provided default choice.
     */
    int readChoiceOrDefault(int defaultChoice,
        const char* invalidInputMessage) const;

    /**
     * @brief Clears the failed input state and discards the rest of the line.
     */
    void resetInputStream() const;

    MatrixInputReader _matrixInputReader;
};
