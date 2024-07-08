#include "rectangle.hpp"
#include <iostream>


void Rectangle::draw(std::ostream& out) const {
    for (int i = 0; i < this->height; ++i) {
        out << std::string(this->width, '*') << std::endl;
    }
}

double Rectangle::area() const {
    return width * height;
}

Rectangle::Rectangle(Point Center, std::string name, int width, int height)
: Shape(Center, name) {
    this->width = width;
    this->height = height;
}

Rectangle* Rectangle::clone() const {
    return new Rectangle(*this);
}