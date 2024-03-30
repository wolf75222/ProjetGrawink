#pragma once

#include "Shape.hpp"
#include <vector>
#include <cmath>

class Polygon : public Shape {
private:
    std::vector<Point> vertices;

public:
    template<typename... Args> Polygon(int _id, Point& _center, double _angle, Args&&... args) : Shape(_id, _center, _angle), vertices{std::forward<Args>(args)...} {}

    Point getCenter() const override;

    void translate(const Point& p) override;
    void rotate(const Point& p, double angle) override;
    void scale(double factor) override;

    std::string draw() const override;
};