#include "shape.hpp"
#include <iostream>

Shape::Shape(Point Center, std::string name) {
    this->Center = Center;
    this->name = name;
}

void Shape::print(std::ostream& out) const {
    out << this->name << "(" << this->Center.x << ", " << this->Center.y << ")" << std::endl;
}