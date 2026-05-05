// QuantStudio_classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "Curve.h"
#include "LinearCurve.h"
#include "PiecewiseConstant.h"
#include "LogLinearCurve.h"

int main()
{
    std::cout << "Hello World!\n";

    std::vector<double> x{ 0,1,2,3,4 };
    std::vector<double> y{ 100,200,50,400,405 };

    // Chooseing method:
    Curve* curve = new LinearCurve(x, y);
    //Curve* curve = new PiecewiseConstant(x, y);
    //Curve* curve = new LogLinearCurve(x, y);

    std::cout << "x     y\n";

    for (double xp = 0; xp <= 3.5; xp += 0.5)
    {
        double yp = curve->f(xp);
        std::cout << xp << "   " << yp << std::endl;
    }

    delete curve;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
