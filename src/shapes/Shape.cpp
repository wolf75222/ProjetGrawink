#include "../../include/shapes/Shape.hpp"

void Shape::translate(Point& p) {
    center.setX(center.getX() + p.getX());
    center.setY(center.getY() + p.getY());
};

void Shape::rotate(Point& p, double angle) {
    double theta = angle * 3.141592653 / 180.0;
    double new_x = p.getX() + (center.getX() - p.getX()) * cos(theta) - (center.getY() - p.getY()) * sin(theta);
    double new_y = p.getY() + (center.getX() - p.getX()) * sin(theta) + (center.getY() - p.getY()) * cos(theta);
    
    this->angle = angle;
    center.setX(new_x);
    center.setY(new_y);
};