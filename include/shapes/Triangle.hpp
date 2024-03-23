#include "Shape.hpp"

class Triangle : public Shape {
private:
    double side_length;

public:
    Triangle();
    void scale(float factor) override;
    void translate() override;
    void rotate() override;
    void fill() override;
    void draw() override;
    void erase() override;
};