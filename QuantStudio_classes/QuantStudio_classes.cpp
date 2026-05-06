#include <exception>
#include <iostream>
#include <limits>

#include "CurveConsoleApplication.h"
#include "MatrixConsoleApplication.h"

namespace
{
enum class MainMenuChoice
{
    Curves = 1,
    Matrices = 2,
    Exit = 3
};

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

MainMenuChoice showInitialMenu()
{
    while (true)
    {
        std::cout << "What would you like to do?\n";
        std::cout << "1. Choose data set and curve for calculations\n";
        std::cout << "2. Perform matrix operations\n";
        std::cout << "3. Exit\n";
        std::cout << "Choice: ";

        int initialActionChoice = 0;
        const bool hasValidInput = tryReadChoice(initialActionChoice);

        std::cout << '\n';

        if (!hasValidInput || (initialActionChoice < 1 || initialActionChoice > 3))
        {
            std::cout << "Invalid choice. Returning to the selection menu.\n\n";
            continue;
        }

        return static_cast<MainMenuChoice>(initialActionChoice);
    }
}

bool shouldRunAgain()
{
    std::cout << "\nWhat would you like to do next?\n";
    std::cout << "1. Return to the selection menu\n";
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

void runSelectedApplication(MainMenuChoice selectedApplication,
    const CurveConsoleApplication& curveApplication,
    const MatrixConsoleApplication& matrixApplication)
{
    // Keeping the main menu dispatch here makes it easy to plug new features
    // into the program without moving logic back into the specialized classes.
    switch (selectedApplication)
    {
    case MainMenuChoice::Curves:
        curveApplication.run();
        break;
    case MainMenuChoice::Matrices:
        matrixApplication.run();
        break;
    case MainMenuChoice::Exit:
        break;
    }
}
}

// Demonstration program for the available interpolation schemes.
int main()
{
    try
    {
        const CurveConsoleApplication curveApplication;
        const MatrixConsoleApplication matrixApplication;

        while (true)
        {
            const MainMenuChoice selectedApplication = showInitialMenu();

            if (selectedApplication == MainMenuChoice::Exit)
            {
                return 0;
            }

            runSelectedApplication(
                selectedApplication,
                curveApplication,
                matrixApplication);

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
