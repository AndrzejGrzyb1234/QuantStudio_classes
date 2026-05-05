#pragma once
#include "Curve.h"

/**
 * @brief Piecewise-constant interpolation of tabulated data.
 */
class PiecewiseConstant : public Curve
{
public:
    /// @brief Inherit the constructors of the base class.
    using Curve::Curve;

    /**
     * @brief Evaluates the piecewise-constant interpolant.
     * @param x Point at which the interpolant is to be evaluated.
     * @return Segment value associated with the specified point.
     */
    double f(double x) const override;
};
