#include "Color.hpp"

class Drawable {
private:
    int opacity = 255;
    double stroke_width = 1;
    Color stroke;
    Color color;

public:
    virtual void draw() = 0;
    virtual void erase() = 0;

    void setOpacity(int opacity) {
        this->opacity = opacity;
    }

    void setStrokeWidth(double width) {
        this->stroke_width = width;
    }

    void setStrokeColor(Color& color){
        this->stroke = color;
    }

    void setColor(Color& color){
        this->color = color;
    }
    
    int getOpacity() {
        return this->opacity;
    };

    double getStrokeWidth() {
        return this->stroke_width;
    };

    Color getStrokeColor() {
        return this->stroke;
    };

    Color getColor() {
        return this->color;
    };
};