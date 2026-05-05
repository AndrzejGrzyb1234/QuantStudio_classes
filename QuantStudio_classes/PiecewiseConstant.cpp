#include "PiecewiseConstant.h"

// Piecewise-constant interpolation.
double PiecewiseConstant::f(double x) const
{
    for (size_t i = 0; i < _xValues.size() - 1; i++)
    {
        if (x >= _xValues[i] && x < _xValues[i + 1])
        {
            return _yValues[i]; // Return the constant value assigned to the interval.
        }
    }

    return _yValues.back();
}
