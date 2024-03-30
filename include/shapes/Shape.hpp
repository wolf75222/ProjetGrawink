#pragma once

#include "../utils/Drawable.hpp"
#include "../utils/Transformable.hpp"

class Shape : public Drawable, Transformable {
protected:
    int id;
    double angle = 0.0;

    Point& center;
    Color fill = Color();
    Color stroke = Color();

    double stroke_width = 1.0;

public:
    Shape(int _id, Point& _center, double _angle) : id(_id), center(_center), angle(_angle) {};

    virtual Point getCenter() const { return center; }
    virtual void setCenter(Point& p) { center = p; }

    void translate(Point& p) override;
    void rotate(Point& p, double angle) override;
    void scale(double factor) override = 0;

    const Color& getFillColor() const { return fill; }
    const Color& getStrokeColor() const { return stroke; }
    double getStrokeWidth() const { return stroke_width; }
    
    void setFillColor(Color& color) { fill = color; }
    void setStrokeColor(Color& color) { stroke = color; }
    void setStrokeWidth(double width) { stroke_width = width; }

    int getId() const { return this->id; };
};