#include "Shape.hpp"

class Polygon : public Shape {
private:
    // Polygon? what kind of shape is a polygon, that can be any shape

public:
    Polygon(int id, double x, double y, double size, bool filled);
    void scale(float factor) override;
    void translate() override;
    void rotate() override;
    void fill() override;
    void draw() override;
    void erase() override;
};