#include "Curve.h"
#include <stdexcept>

// Konstruktor - zapis danych + walidacja
Curve::Curve(const std::vector<double>& x,
    const std::vector<double>& y)
    : _xValues(x), _yValues(y)
{
    if (x.size() != y.size())
        throw std::invalid_argument("Rozne rozmiary wektorow!");

    if (x.size() < 2)
        throw std::invalid_argument("Za malo punktow!");
}

// Destruktor (pusty, ale potrzebny przy polimorfizmie)
Curve::~Curve() {}
