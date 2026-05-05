#pragma once
#include "Curve.h"

class PiecewiseConstant : public Curve
{
public:
    using Curve::Curve; // constructor

    double f(double x) const override;
};
