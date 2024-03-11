#include "Circle.h"
#include <sstream> // Pour std::ostringstream

Circle::Circle(double centerX, double centerY, double radius, int id) :
    _center{centerX, centerY}, _radius(radius), _id(id), _isSelected(false) {
    // Initialiser les valeurs par défaut pour la couleur, l'opacité, etc.
    _fillColor = "black"; // Couleur de remplissage par défaut
    _opacity = 1.0; // Opacité par défaut
    _strokeColor = "none"; // Pas de contour par défaut
    _strokeWidth = 0.0; // Largeur du trait par défaut
}

std::string Circle::toSVG() const {
    std::ostringstream svg;
    svg << "<circle cx=\"" << _center.x
        << "\" cy=\"" << _center.y
        << "\" r=\"" << _radius
        << "\" fill=\"" << _fillColor
        << "\" stroke=\"" << _strokeColor
        << "\" stroke-width=\"" << _strokeWidth
        << "\" opacity=\"" << _opacity << "\" />";
    return svg.str();
}

void Circle::translate(double dx, double dy) {
    _center.x += dx;
    _center.y += dy;
}



