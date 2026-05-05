#pragma once
#include "Curve.h"

/**
 * @brief Piecewise log-linear interpolation of tabulated data.
 */
class LogLinearCurve : public Curve
{
public:
    /// @brief Inherit the constructors of the base class.
    using Curve::Curve;

    /**
     * @brief Evaluates the piecewise log-linear interpolant.
     * @param x Point at which the interpolant is to be evaluated.
     * @return Interpolated value at the specified point.
     */
    double f(double x) const override;
};
