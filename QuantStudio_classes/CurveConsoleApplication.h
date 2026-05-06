#pragma once

#include <memory>
#include <vector>

class Curve;

/**
 * @brief Handles the curve-related console workflow between the main menu screens.
 */
class CurveConsoleApplication
{
public:
    /**
     * @brief Runs one curve selection and evaluation cycle.
     */
    void run() const;

private:
    /**
     * @brief Loads the input data according to the user's menu choice.
     * @param x Output vector of abscissae.
     * @param y Output vector of ordinates.
     */
    void loadSelectedData(std::vector<double>& x,
        std::vector<double>& y) const;

    /**
     * @brief Creates the curve chosen by the user.
     * @param x Input vector of abscissae.
     * @param y Input vector of ordinates.
     * @return Curve instance matching the user's selection.
     */
    std::unique_ptr<Curve> createSelectedCurve(const std::vector<double>& x,
        const std::vector<double>& y) const;

    /**
     * @brief Prints a sample table of curve values.
     * @param curve Curve to be evaluated.
     */
    void printCurveValues(const Curve& curve) const;

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

    const std::vector<double> _defaultX{ 0,1,2,3,4 };
    const std::vector<double> _defaultY{ 100,200,50,400,405 };
};
