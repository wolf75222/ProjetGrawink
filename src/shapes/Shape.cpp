#include "../../include/shapes/Shape.hpp"

void Shape::translate(double x, double y) {
    this->x += x;
    this->y += y;
};

void Shape::rotate(double angle) {
    this->angle += angle;
};