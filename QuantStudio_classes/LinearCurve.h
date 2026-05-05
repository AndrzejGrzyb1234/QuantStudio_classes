#pragma once
#include "Curve.h"

/**
 * @brief Piecewise linear interpolation of tabulated data.
 */
class LinearCurve : public Curve
{
public:
    /// @brief Inherit the constructors of the base class.
    using Curve::Curve;

    /**
     * @brief Evaluates the piecewise linear interpolant.
     * @param x Point at which the interpolant is to be evaluated.
     * @return Interpolated value at the specified point.
     */
    double f(double x) const override;
};
