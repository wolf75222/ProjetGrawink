#include "Shape.hpp"

class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(int id, double x, double y, double width, double height, bool filled);
    void scale(float factor) override;
    void translate() override;
    void rotate() override;
    void fill() override;
    void draw() override;
    void erase() override;
};