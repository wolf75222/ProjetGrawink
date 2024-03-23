#include "Shape.hpp"

class Circle : public Shape {
private:
    double radius;

public:
    Circle(int id, double x, double y, double radius, bool filled);
    void scale(float factor) override;
    void translate() override;
    void rotate() override;
    void fill() override;
    void draw() override;
    void erase() override;
};