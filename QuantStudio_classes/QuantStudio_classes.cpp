#include <exception>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "Curve.h"
#include "CsvReader.h"
#include "LinearCurve.h"
#include "PiecewiseConstant.h"
#include "LogLinearCurve.h"

// Demonstration program for the available interpolation schemes.
int main()
{
    try
    {
        const std::vector<double> defaultX{ 0,1,2,3,4 };
        const std::vector<double> defaultY{ 100,200,50,400,405 };

        bool keepRunning = true;

        while (keepRunning)
        {
            std::vector<double> x;
            std::vector<double> y;

            std::cout << "Select the data source:\n";
            std::cout << "1. Built-in sample data\n";
            std::cout << "2. CSV file (data.csv)\n";
            std::cout << "Choice: ";

            int dataSourceChoice = 0;
            if (!(std::cin >> dataSourceChoice))
            {
                std::cout << "Invalid input. Built-in sample data will be used by default.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                dataSourceChoice = 1;
            }

            // Populate the input vectors according to the selected data source.
            switch (dataSourceChoice)
            {
            case 1:
                x = defaultX;
                y = defaultY;
                break;
            case 2:
                CsvReader::load("data.csv", x, y);
                break;
            default:
                std::cout << "Invalid choice. Built-in sample data will be used by default.\n";
                x = defaultX;
                y = defaultY;
                break;
            }

            std::cout << "Select the interpolation scheme:\n";
            std::cout << "1. Linear\n";
            std::cout << "2. Piecewise constant\n";
            std::cout << "3. Log-linear\n";
            std::cout << "Choice: ";

            int curveChoice = 0;
            if (!(std::cin >> curveChoice))
            {
                std::cout << "Invalid input. Linear interpolation will be used by default.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                curveChoice = 1;
            }

            std::unique_ptr<Curve> curve;

            // Instantiate the curve selected by the user at runtime.
            switch (curveChoice)
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

            std::cout << "\nWhat would you like to do next?\n";
            std::cout << "1. Choose data set and curve again\n";
            std::cout << "2. Exit\n";
            std::cout << "Choice: ";

            int nextActionChoice = 0;
            if (!(std::cin >> nextActionChoice))
            {
                std::cout << "Invalid input. Returning to the selection menu.\n\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (nextActionChoice == 2)
            {
                keepRunning = false;
            }
            else
            {
                if (nextActionChoice != 1)
                {
                    std::cout << "Invalid choice. Returning to the selection menu.\n";
                }
                std::cout << '\n';
            }
        }

        return 0;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Application error: " << ex.what() << std::endl;
        return 1;
    }
}
