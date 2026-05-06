#include <exception>
#include <iostream>
#include <limits>

#include "CurveConsoleApplication.h"

namespace
{
void resetInputStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool tryReadChoice(int& choice)
{
    if (!(std::cin >> choice))
    {
        resetInputStream();
        return false;
    }

    return true;
}

bool showInitialMenu()
{
    while (true)
    {
        std::cout << "What would you like to do?\n";
        std::cout << "1. Choose data set and curve for calculations\n";
        std::cout << "2. Exit\n";
        std::cout << "Choice: ";

        int initialActionChoice = 0;
        const bool hasValidInput = tryReadChoice(initialActionChoice);

        std::cout << '\n';

        if (!hasValidInput || (initialActionChoice != 1 && initialActionChoice != 2))
        {
            std::cout << "Invalid choice. Returning to the selection menu.\n\n";
            continue;
        }

        return initialActionChoice == 1;
    }
}

bool shouldRunAgain()
{
    std::cout << "\nWhat would you like to do next?\n";
    std::cout << "1. Choose data set and curve again\n";
    std::cout << "2. Exit\n";
    std::cout << "Choice: ";

    int nextActionChoice = 0;
    const bool hasValidInput = tryReadChoice(nextActionChoice);

    std::cout << '\n';

    if (!hasValidInput || (nextActionChoice != 1 && nextActionChoice != 2))
    {
        std::cout << "Invalid choice. Returning to the selection menu.\n\n";
        return true;
    }

    return nextActionChoice == 1;
}
}

// Demonstration program for the available interpolation schemes.
int main()
{
    try
    {
        const CurveConsoleApplication application;

        while (true)
        {
            if (!showInitialMenu())
            {
                return 0;
            }

            application.run();

            if (!shouldRunAgain())
            {
                return 0;
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
