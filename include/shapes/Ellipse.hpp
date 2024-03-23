#include "Shape.hpp"

class Ellipse : public Shape {
private:
    double width;
    double height;

public:
    Ellipse(int id, double x, double y, double size, bool filled);
    void scale(float factor) override;
    void translate() override;
    void rotate() override;
    void fill() override;
    void draw() override;
    void erase() override;
};