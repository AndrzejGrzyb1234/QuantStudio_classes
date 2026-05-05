#include "Curve.h"
#include <stdexcept>

// Store the input data and verify the basic consistency conditions.
Curve::Curve(const std::vector<double>& x,
    const std::vector<double>& y)
    : _xValues(x), _yValues(y)
{
    if (x.size() != y.size())
        throw std::invalid_argument("Different vector sizes!");

    if (x.size() < 2)
        throw std::invalid_argument("Not enough points!");
}

// A virtual destructor is required for safe polymorphic destruction.
Curve::~Curve() {}
