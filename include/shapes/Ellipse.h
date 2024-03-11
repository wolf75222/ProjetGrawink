#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

class Ellipse : public Shape {
public:
    // Constructeur: initialise une nouvelle ellipse avec le centre (centerX, centerY), les rayons rx et ry, et un identifiant optionnel
    Ellipse(double centerX, double centerY, double rx, double ry, int id = 0);
    virtual ~Ellipse() {}

    // Implémentation de la méthode toSVG pour générer la représentation SVG de l'ellipse
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
    virtual std::string type() const override { return "Ellipse"; }
    virtual int id() const override { return _id; }
    virtual std::string fill() const override { return _fillColor; }
    virtual double opacity() const override { return _opacity; }
    virtual std::string strokeColor() const override { return _strokeColor; }
    virtual double strokeWidth() const override { return _strokeWidth; }

    virtual void applyTransformation(const std::string& transform) override;
    virtual void printDebugInfo() const override;

private:
    Point _center;
    double _rx, _ry; // Rayons en x et en y
    int _id;
    std::string _fillColor;
    double _opacity;
    std::string _strokeColor;
    double _strokeWidth;
    bool _isSelected;

};

#endif // ELLIPSE_H

