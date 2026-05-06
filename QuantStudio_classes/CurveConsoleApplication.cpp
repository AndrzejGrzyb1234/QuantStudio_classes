#include "CurveConsoleApplication.h"

#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "CsvReader.h"
#include "Curve.h"
#include "LinearCurve.h"
#include "LogLinearCurve.h"
#include "PiecewiseConstant.h"

void CurveConsoleApplication::run() const
{
    std::vector<double> x;
    std::vector<double> y;

    loadSelectedData(x, y);
    std::unique_ptr<Curve> curve = createSelectedCurve(x, y);
    printCurveValues(*curve);
}

void CurveConsoleApplication::loadSelectedData(std::vector<double>& x,
    std::vector<double>& y) const
{
    std::cout << "Select the data source:\n";
    std::cout << "1. Built-in sample data\n";
    std::cout << "2. CSV file (data.csv)\n";
    std::cout << "Choice: ";

    const int dataSourceChoice = readChoiceOrDefault(
        1,
        "Invalid input. Built-in sample data will be used by default.");

    switch (dataSourceChoice)
    {
    case 1:
        x = _defaultX;
        y = _defaultY;
        break;
    case 2:
        CsvReader::load("data.csv", x, y);
        break;
    default:
        std::cout << "Invalid choice. Built-in sample data will be used by default.\n";
        x = _defaultX;
        y = _defaultY;
        break;
    }
}

std::unique_ptr<Curve> CurveConsoleApplication::createSelectedCurve(
    const std::vector<double>& x,
    const std::vector<double>& y) const
{
    std::cout << "Select the interpolation scheme:\n";
    std::cout << "1. Linear\n";
    std::cout << "2. Piecewise constant\n";
    std::cout << "3. Log-linear\n";
    std::cout << "Choice: ";

    const int curveChoice = readChoiceOrDefault(
        1,
        "Invalid input. Linear interpolation will be used by default.");

    switch (curveChoice)
    {
    case 1:
        return std::make_unique<LinearCurve>(x, y);
    case 2:
        return std::make_unique<PiecewiseConstant>(x, y);
    case 3:
        return std::make_unique<LogLinearCurve>(x, y);
    default:
        std::cout << "Invalid choice. Linear interpolation will be used by default.\n";
        return std::make_unique<LinearCurve>(x, y);
    }
}

void CurveConsoleApplication::printCurveValues(const Curve& curve) const
{
    std::cout << "x     y\n";

    for (double xp = 0; xp <= 3.5; xp += 0.5)
    {
        const double yp = curve.f(xp);
        std::cout << xp << "   " << yp << std::endl;
    }
}

int CurveConsoleApplication::readChoiceOrDefault(int defaultChoice,
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

void CurveConsoleApplication::resetInputStream() const
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
