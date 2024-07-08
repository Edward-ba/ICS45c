#include "triangle.hpp"
#include <algorithm>
#include <iostream>

Triangle::Triangle(Point Center, std::string name, int base, int height)
: Shape(Center, name){
    this->base = base;
    this->height = height;
}

double Triangle::area() const {
    return (double) base * (double) height / 2;
}

Triangle* Triangle::clone() const {
    return new Triangle(*this);
}

void Triangle::draw(std::ostream& out) const {
    int offset = std::max(this->height, this->base);
    for (int i = 0; i < height; i += 2) {
        for (int j = 0; j < (offset - i) / 2; ++j) {
            out << ' ';
        }
        for (int k = 0; k <= i; ++k) {
            out << '*';
        }
        out << std::endl;
    }
}