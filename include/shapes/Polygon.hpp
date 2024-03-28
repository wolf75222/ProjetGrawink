#include "Shape.hpp"
#include <vector>
#include <cmath>

class Point {
private:
    double x = 0.0;
    double y = 0.0;
public:
    Point(double _x, double _y) : x(_x), y(_y) {};

    double getX() const { return x; }
    double getY() const { return y; }

    void scale(double factor) {
        this->x *= factor;
        this->y *= factor;
    }

    void translate(double x, double y) {
        this->x += x;
        this->y += y;
    }

    void rotate(double center_x, double center_y, double angle) {
        double angle = angle * 3.141592653 / 180.0;
        double newX = center_x + (x - center_x) * std::cos(angle) - (y - center_y) * std::sin(angle);
        double newY = center_y + (x - center_x) * std::sin(angle) + (y - center_y) * std::cos(angle);
        x = newX;
        y = newY;
    }
};

class Polygon : public Shape {
private:
    std::vector<Point> vertices;

    void setCenter() {
        double sum_x = 0.0;
        double sum_y = 0.0;
        for (Point& point : vertices) {
            sum_x += point.getX();
            sum_y += point.getY();
        }
        double center_x = sum_x / vertices.size();
        double center_y = sum_y / vertices.size();
        
        this->x = center_x;
        this->y = center_y;
    }

public:
    template<typename... Args> Polygon(Args&&... args) : vertices{std::forward<Args>(args)...} {}

    void scale(double factor) override;
    void translate(double x, double y) override;
    void rotate(double angle) override;
};