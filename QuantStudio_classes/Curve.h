#pragma once
#include <vector>

class Curve
{
protected:
    std::vector<double> _xValues;
    std::vector<double> _yValues;

public:
    Curve(const std::vector<double>& x,
        const std::vector<double>& y);

    // funkcja wirtualna - każda klasa musi ją zaimplementować
    virtual double f(double x) const = 0;

    virtual ~Curve();
};
