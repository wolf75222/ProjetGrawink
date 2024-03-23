#include "Shape.hpp"

class Ellipse : public Shape {
private:
    double width = 1.0;
    double height = 1.0;

public:
    Ellipse(int _id, double _x, double _y, double _size, double _angle, double _width, double _height) : Shape(_id, _x, _y, _size, _angle), width(_width), height(_height) {};
    
    void scale(double factor) override;

    std::string draw() override;
};