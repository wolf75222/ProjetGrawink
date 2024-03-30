#include "../../include/shapes/Shape.hpp"

#include <iostream>

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


bool Shape::isOutside(int x, int y, int width, int height) {
    // Utilise getCenter pour obtenir le Point central
    Point center = this->getCenter();

    // Utilise getX() et getY() pour accéder aux coordonnées x et y du centre
    double centerX = center.getX();
    double centerY = center.getY();

    // Vérifie si le centre est en dehors de la zone spécifiée
    return centerX < x || centerY < y || centerX > x + width || centerY > y + height;
}



Shape::ShapeType Shape::getType() {
    return this->type;
};

void Shape::print() {
    Point center = this->getCenter();
    double centerX = center.getX();
    double centerY = center.getY();

    std::cout << "Shape " << this->id << " at (" << centerX << ", " << centerY << ")";

    std::cout << ", angle " << this->angle << ", and type ";

    switch (this->getType()) {
        case ShapeType::Stroke:
            std::cout << "Stroke";
            break;
        case ShapeType::Triangle:
            std::cout << "Triangle";
            break;
        case ShapeType::Rectangle:
            std::cout << "Rectangle";
            break;
        case ShapeType::Pentagon:
            std::cout << "Pentagon";
            break;
        case ShapeType::Hexagon:
            std::cout << "Hexagon";
            break;
        case ShapeType::Heptagon:
            std::cout << "Heptagon";
            break;
        case ShapeType::Octogon:
            std::cout << "Octogon";
            break;
        case ShapeType::Ellipsis:
            std::cout << "Ellipsis";
            break;
        case ShapeType::All:
            std::cout << "All";
            break;
        default:
            std::cout << "Unknown";
            break;
    }
    
    std::cout << std::endl;
}



std::string Shape::getName() {
    switch (this->type) {
        case ShapeType::Stroke:
            return "Stroke";
        case ShapeType::Triangle:
            return "Triangle";
        case ShapeType::Rectangle:
            return "Rectangle";
        case ShapeType::Pentagon:
            return "Pentagon";
        case ShapeType::Hexagon:
            return "Hexagon";
        case ShapeType::Heptagon:
            return "Heptagon";
        case ShapeType::Octogon:
            return "Octogon";
        case ShapeType::Ellipsis:
            return "Ellipsis";
        case ShapeType::All:
            return "All";
        default:
            return "Unknown";
    }
};
