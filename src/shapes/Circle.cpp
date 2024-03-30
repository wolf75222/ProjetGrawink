#include <string>
#include <sstream>

#include "../../include/shapes/Circle.hpp"

void Circle::scale(double factor) {
    this->radius *= factor;
}

void Circle::rotate(Point& p, double angle) {
    // There is no point in rotating a circle    
}

std::string Circle::draw() const {
    std::stringstream ss;
    
    ss << "<circle id=\"" <<
    id << "\" cx=\"" << 
    center.getX() << "\" cy=\"" << 
    center.getY() << "\" r=\"" << 
    radius << "\" fill=\"" << 
    fill.asSVG() << "\" stroke=\"" << 
    stroke.asSVG() << "\" stroke-width=\"" << 
    stroke_width << "\" transform=\"rotate(" <<
    angle << " " << center.getX() << " " << center.getY() << ")\"/>";
    
    return ss.str();
}