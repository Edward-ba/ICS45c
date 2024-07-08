#ifndef SHAPEHPP
#define SHAPEHPP

#include <iosfwd>
#include <string>

struct Point {
    int x;
    int y;
};

class Shape {
public:
    Shape(Point Center, std::string name);
    void print(std::ostream& out) const;
    Shape& operator=(const Shape& other) = delete;
    virtual double area() const = 0;
    virtual void draw(std::ostream& out) const = 0;
    virtual Shape* clone() const = 0;
    virtual ~Shape() = default;
protected:
    Shape(const Shape& other) = default;
private:
    Point Center;
    std::string name;
};
#endif