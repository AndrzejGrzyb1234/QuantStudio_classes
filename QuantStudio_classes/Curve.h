#pragma once
#include <vector>

/**
 * @brief Abstract base class representing a curve defined on discrete data points.
 */
class Curve
{
protected:
    std::vector<double> _xValues;
    std::vector<double> _yValues;

public:
    /**
     * @brief Constructs a curve from paired coordinate vectors.
     * @param x Vector of abscissae.
     * @param y Vector of ordinates.
     */
    Curve(const std::vector<double>& x,
        const std::vector<double>& y);

    /**
     * @brief Evaluates the curve at the specified argument.
     * @param x Point at which the curve is to be evaluated.
     * @return Value of the curve at the given point.
     */
    virtual double f(double x) const = 0;

    /**
     * @brief Destroys the curve instance.
     */
    virtual ~Curve();
};
