#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
public:
    // Constructeur: initialise un nouveau triangle avec les coordonnées de ses trois sommets et un identifiant optionnel
    Triangle(const Point& p1, const Point& p2, const Point& p3, int id = 0);
    virtual ~Triangle() {}

    // Implémentation de la méthode toSVG pour générer la représentation SVG du triangle
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
    virtual std::string type() const override { return "Triangle"; }
    virtual int id() const override { return _id; }
    virtual std::string fill() const override { return _fillColor; }
    virtual double opacity() const override { return _opacity; }
    virtual std::string strokeColor() const override { return _strokeColor; }
    virtual double strokeWidth() const override { return _strokeWidth; }

    virtual void applyTransformation(const std::string& transform) override;
    virtual void printDebugInfo() const override;

private:
    Point _p1, _p2, _p3; // Les trois sommets du triangle
    int _id;
    std::string _fillColor;
    double _opacity;
    std::string _strokeColor;
    double _strokeWidth;
    bool _isSelected;

};

#endif // TRIANGLE_H

