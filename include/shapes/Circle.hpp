#include "Shape.hpp"

class Circle : public Shape {
private:
    double radius = 1.0;

public:
    Circle(int _id, double _x, double _y, double _size, double _angle, double _radius) : Shape(_id, _x, _y, _size, _angle), radius(_radius) {};

    void scale(double factor) override;
    void rotate(double angle) override = 0;
    
    std::string draw() override;
};