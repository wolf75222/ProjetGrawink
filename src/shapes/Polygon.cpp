#include "../../include/shapes/Polygon.hpp"

#include <string>
#include <sstream>

void Polygon::scale(double factor) {
    for (Point& vertex : vertices) {
        vertex.scale(factor);
    }
}

void Polygon::translate(const Point& p) {
    for (Point& vertex : vertices) {
        vertex.translate(p);
    }
}

void Polygon::rotate(const Point& p, double angle) {
    for (Point& vertex : vertices) {
        vertex.rotate(p, angle);
    }
    this->angle = angle;
}

Point Polygon::getCenter() const {
    double sum_x = 0.0;
    double sum_y = 0.0;
    for (const Point& point : vertices) {
        sum_x += point.getX();
        sum_y += point.getY();
    }
    double center_x = sum_x / vertices.size();
    double center_y = sum_y / vertices.size();
        
    return Point(center_x, center_y);
}


std::string Polygon::draw() const {
    std::stringstream ss;
    
    ss << "<polygon id=\"" <<
    id << "\" points=\"";

    for(const Point& vertex : vertices) {
        ss << vertex.getX() << "," << vertex.getY() << " ";
    }

    ss << "\" fill=\"" << 
    fill.asSVG() << "\" stroke=\"" << 
    stroke.asSVG() << "\" stroke-width=\"" << 
    stroke_width << "\" transform=\"rotate(" <<
    angle << " " << center.getX() << " " << center.getY() << ")\"/>";
    
    return ss.str();
}