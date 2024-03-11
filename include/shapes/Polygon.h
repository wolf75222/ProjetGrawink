#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include <vector>

class Polygon : public Shape {
public:
    // Constructeur: prend une liste de points définissant les sommets du polygone
    Polygon(const std::vector<Point>& vertices, int id = 0);
    virtual ~Polygon() {}

    // Méthode virtuelle pure pour générer la représentation SVG du polygone
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
    virtual std::string type() const override { return "Polygon"; }
    virtual int id() const override { return _id; }
    virtual std::string fill() const override { return _fillColor; }
    virtual double opacity() const override { return _opacity; }
    virtual std::string strokeColor() const override { return _strokeColor; }
    virtual double strokeWidth() const override { return _strokeWidth; }

    virtual void applyTransformation(const std::string& transform) override;
    virtual void printDebugInfo() const override;

private:
    std::vector<Point> _vertices; // Liste des sommets du polygone
    int _id;
    std::string _fillColor;
    double _opacity;
    std::string _strokeColor;
    double _strokeWidth;
    bool _isSelected;

};

#endif // POLYGON_H

