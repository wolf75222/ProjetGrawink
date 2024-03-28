#include <string>
#include <sstream>

#include "../../include/shapes/Polygon.hpp"

void Polygon::scale(double factor) {
    this->setCenter();
    for (Point& vertex : vertices) {
        vertex.scale(factor);
    }
}

void Polygon::translate(double x, double y) {
    this->setCenter();
    for (Point& vertex : vertices) {
        vertex.translate(x, y);
    }
}

void Polygon::rotate(double angle) {
    this->setCenter();
    for (Point& vertex : vertices) {
        vertex.rotate(this->x, this->y, angle);
    }
}