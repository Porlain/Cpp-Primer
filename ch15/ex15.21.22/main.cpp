#include <iostream>
#include <string>

// (b) Geometric primitives (such as box, circle, sphere, cone)
// just for 2D shape
class Shape
{
public:
    Shape() = default;
    Shape(const std::string &na) : name(na) {}
    typedef std::pair<double, double> Coordinate;

protected:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

private:
    std::string name;
};

class Rectangle : public Shape
{
public:
    Rectangle() = default;
    Rectangle(const std::string &na, const Coordinate &a,
              const Coordinate &b, const Coordinate &c) : Shape(na), a(a), b(b), c(c) {}
    ~Rectangle() = default;

private:
    Coordinate a;
    Coordinate b;
    Coordinate c;
};

class Square : public Rectangle
{
public:
    Square() = default;
    Square(const std::string &n, const Coordinate &a,
           const Coordinate &b, const Coordinate &c) : Rectangle(n, a, b, c) {}
    ~Square() = default;
};

int main()
{
    return 0;
}