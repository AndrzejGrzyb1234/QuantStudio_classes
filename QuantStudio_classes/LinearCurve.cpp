#include "LinearCurve.h"

// Piecewise linear interpolation.
double LinearCurve::f(double x) const
{
    for (size_t i = 0; i < _xValues.size() - 1; i++)
    {
        if (x >= _xValues[i] && x <= _xValues[i + 1])
        {
            double x0 = _xValues[i];
            double x1 = _xValues[i + 1];
            double y0 = _yValues[i];
            double y1 = _yValues[i + 1];

            return y0 + (y1 - y0) * (x - x0) / (x1 - x0);
        }
    }

    return _yValues.back();
}
