#pragma once

#include "Shape.hpp"

class Rectangle : public Shape {
private:
    double width = 1.0;
    double height = 1.0;

public:
    Rectangle(int _id, Point& _center, double _width, double _height, double _angle) : Shape(_id, _center, _angle), width(_width), height(_height) {};
    
    void scale(double factor) override;

    std::string draw() const override;
};