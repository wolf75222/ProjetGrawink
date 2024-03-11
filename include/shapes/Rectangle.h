#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
public:
    // Constructeur: initialise un nouveau rectangle avec les coordonnées du coin supérieur gauche (x, y), la largeur, la hauteur et un identifiant optionnel
    Rectangle(double x, double y, double width, double height, int id = 0);
    virtual ~Rectangle() {}

    // Implémentation de la méthode toSVG pour générer la représentation SVG du rectangle
    virtual std::string toSVG() const override;

    // Transformations géométriques
    virtual void translate(double dx, double dy) override;
    virtual void rotate(double angle, const Point& center) override;
    virtual void scale(double scaleFactor) override;

    // Gestion des attributs de couleur et de style
    virtual void setFill(const std::string& color) override;
    virtual void setOpacity(double opacity) override;
    virtual void setStrokeColor(const std::string& color) override;
    virtual void setStrokeWidth(double width) override;

    // Sélecteurs
    virtual bool isSelected() const override;
    virtual void select(bool select) override;

    // Informations sur la forme
    virtual std::string type() const override { return "Rectangle"; }
    virtual int id() const override { return _id; }
    virtual std::string fill() const override { return _fillColor; }
    virtual double opacity() const override { return _opacity; }
    virtual std::string strokeColor() const override { return _strokeColor; }
    virtual double strokeWidth() const override { return _strokeWidth; }

    virtual void applyTransformation(const std::string& transform) override;
    virtual void printDebugInfo() const override;

private:
    Point _topLeft; // Point du coin supérieur gauche
    double _width, _height;
    int _id;
    std::string _fillColor;
    double _opacity;
    std::string _strokeColor;
    double _strokeWidth;
    bool _isSelected;

};

#endif // RECTANGLE_H

