#pragma once

#include "Color.hpp"
#include <string>

class Drawable {
protected:
    // double stroke_width = 1;
    // Color stroke;
    // Color color;

public:
    Drawable() = default;
    ~Drawable() = default;

    virtual std::string draw() const = 0;
    // virtual void erase() = 0;

    // void setStrokeWidth(double width) {
    //     this->stroke_width = width;
    // }

    // void setStrokeColor(Color& color){
    //     this->stroke = color;
    // }

    // void setColor(Color& color){
    //     this->color = color;
    // }

    // double getStrokeWidth() {
    //     return this->stroke_width;
    // };

    // Color& getStrokeColor() {
    //     return this->stroke;
    // };

    // Color& getColor() {
    //     return this->color;
    // };
};