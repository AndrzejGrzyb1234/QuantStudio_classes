#include <iostream>
#include <memory>
#include <vector>

#include "Curve.h"
#include "LinearCurve.h"
#include "PiecewiseConstant.h"
#include "LogLinearCurve.h"

// Demonstration program for the available interpolation schemes.
int main()
{
    std::cout << "Hello World!\n";

    std::vector<double> x{ 0,1,2,3,4 };
    std::vector<double> y{ 100,200,50,400,405 };

    std::cout << "Select the interpolation scheme:\n";
    std::cout << "1. Linear\n";
    std::cout << "2. Piecewise constant\n";
    std::cout << "3. Log-linear\n";
    std::cout << "Choice: ";

    int choice = 0;
    std::cin >> choice;

    std::unique_ptr<Curve> curve;

    // Instantiate the curve selected by the user at runtime.
    switch (choice)
    {
    case 1:
        curve = std::make_unique<LinearCurve>(x, y);
        break;
    case 2:
        curve = std::make_unique<PiecewiseConstant>(x, y);
        break;
    case 3:
        curve = std::make_unique<LogLinearCurve>(x, y);
        break;
    default:
        std::cout << "Invalid choice. Linear interpolation will be used by default.\n";
        curve = std::make_unique<LinearCurve>(x, y);
        break;
    }

    std::cout << "x     y\n";

    for (double xp = 0; xp <= 3.5; xp += 0.5)
    {
        double yp = curve->f(xp);
        std::cout << xp << "   " << yp << std::endl;
    }

    return 0;
}
