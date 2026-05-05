#pragma once
#include "Curve.h"

class LinearCurve : public Curve
{
public:
    using Curve::Curve;

    double f(double x) const override;
};
