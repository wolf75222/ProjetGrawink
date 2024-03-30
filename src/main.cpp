#include <iostream>
#include "../include/utils/Color.hpp"
#include "../include/Grawink.hpp"

int main() {
    GrawEditor& editor = GrawEditor::GetEditor();

    Point center = Point(50, 50);
    Point translate = Point(10, 10);

    Color red = Color(255, 0, 0, 1);
    Color blue = Color(0, 0, 255, 1);
    Color white = Color(255, 255, 255, 1);
    Color black = Color(0, 0, 0, 1);

    // Circle* s = new Circle(1, center, 10, 0);
    // Ellipse* s = new Ellipse(1, center, 20, 10, 0);
    // Rectangle* s = new Rectangle(1, center, 20, 10, 0);
    Polygon* s = new Polygon(
        1,
        center,
        0,
        Point(50, 10),
        Point(90, 35),
        Point(80, 90),
        Point(20, 90),
        Point(10, 35)
    );
    s->translate(translate);
    s->scale(0.5);
    s->setFillColor(white);
    s->setStrokeColor(red);
    s->setStrokeWidth(3);

    Point shape_center = s->getCenter();
    s->rotate(shape_center, 45);

    std::cout << s->draw() << std::endl;

    return 0;
}