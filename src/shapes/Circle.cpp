#include <string>
#include <sstream>

#include "../../include/shapes/Circle.hpp"

void Circle::scale(double factor) {
    this->radius *= factor;
}

std::string Circle::draw() {
    std::stringstream ss;
    
    ss << "<circle id=\"" <<
    id << "\" cx=\"" << 
    x << "\" cy=\"" << 
    y << "\" r=\"" << 
    radius << "\" fill=\"" << 
    color.asSVG() << "\" stroke=\"" << 
    stroke.asSVG() << "\" stroke-width=\"" << 
    stroke_width << "transform=\"rotate(" <<
    angle << " " << x << " " << y << ")\"/>";
    
    return ss.str();
}