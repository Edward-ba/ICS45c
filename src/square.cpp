#include "square.hpp"
#include <iostream>

Square::Square(Point Center, std::string name, int side)
: Rectangle(Center, name, side, side) {
}

Square* Square::clone() const {
    return new Square(*this);
}