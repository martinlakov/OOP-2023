#include <iostream>
#include "figure.hpp"
#include "../color.hpp"

Figure::Figure(const Color &color) : color(color) {}

Color Figure::getColor() const
{
    return this->color;
}

std::ostream &operator<<(std::ostream &out, const Figure &figure)
{
    return figure.print(out);
}
