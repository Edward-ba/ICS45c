#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"
#include "rectangle.hpp"

class Square : public Rectangle{
public:
    Square(Point Center, std::string name, int side);
    Square* clone() const override;
protected:
    Square(const Square& other) = default;
};
#endif