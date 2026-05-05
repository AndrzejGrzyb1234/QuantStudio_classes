#include "LogLinearCurve.h"
#include <cmath>
#include <stdexcept>

// Piecewise log-linear interpolation.
double LogLinearCurve::f(double x) const
{
    for (size_t i = 0; i < _xValues.size() - 1; i++)
    {
        if (x >= _xValues[i] && x <= _xValues[i + 1])
        {
            double x0 = _xValues[i];
            double x1 = _xValues[i + 1];
            double y0 = _yValues[i];
            double y1 = _yValues[i + 1];

            // Ensure that the logarithm is applied only to positive values.
            if (y0 <= 0 || y1 <= 0)
                throw std::runtime_error("Log of a number <= 0!");

            double logy0 = std::log(y0);
            double logy1 = std::log(y1);

            double logy = logy0 + (logy1 - logy0) * (x - x0) / (x1 - x0);

            return std::exp(logy);
        }
    }

    return _yValues.back();
}
