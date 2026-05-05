#pragma once
#include "Curve.h"

class LogLinearCurve : public Curve
{
public:
    using Curve::Curve;

    double f(double x) const override;
};
