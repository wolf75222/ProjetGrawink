#pragma once

#include "Shape.hpp"

class Circle : public Shape {
private:
    double radius = 1.0;

public:
    Circle(int _id, Point& _center, double _radius, double _angle) : Shape(_id, _center, _angle), radius(_radius) {};

    void scale(double factor) override;
    void rotate(const Point& p, double angle) override;
    
    std::string draw() const override;
};