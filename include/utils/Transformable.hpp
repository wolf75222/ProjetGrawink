#pragma once

#include <cmath>

class Point;

class Transformable {
public:
    Transformable() = default;
    ~Transformable() = default;

    virtual void translate(const Point& p) = 0;
    virtual void rotate(const Point& p, double angle) = 0;
    virtual void scale(double factor) = 0;
};

class Point : Transformable {
private:
    double x = 0.0;
    double y = 0.0;

public:
    Point(double _x, double _y) : x(_x), y(_y) {};

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    double getX() const { return x; }
    double getY() const { return y; }

    void translate(const Point& p) override {
        this->x += p.x;
        this->y += p.y;
    }

    void rotate(const Point& p, double angle) override {
        double angl = angle * 3.141592653 / 180.0;
        double newX = p.x + (x - p.x) * std::cos(angl) - (y - p.y) * std::sin(angl);
        double newY = p.y + (x - p.x) * std::sin(angl) + (y - p.y) * std::cos(angl);
        x = newX;
        y = newY;
    }

    void scale(double factor) {
        this->x *= factor;
        this->y *= factor;
    }
};