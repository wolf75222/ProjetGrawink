#include <string>
#include <sstream>

#include "../../include/shapes/Ellipse.hpp"

void Ellipse::scale(double factor) {
    this->height *= factor;
    this->width *= factor;
}

std::string Ellipse::draw() {
    std::stringstream ss;
    
    ss << "<ellipse id=\"" <<
    id << "\" cx=\"" << 
    x << "\" cy=\"" << 
    y << "\" rx=\"" << 
    width << "\" ry=\"" << 
    height << "\" fill=\"" << 
    color.asSVG() << "\" stroke=\"" << 
    stroke.asSVG() << "\" stroke-width=\"" << 
    stroke_width << "transform=\"rotate(" <<
    angle << " " << x << " " << y << ")\"/>";
    
    return ss.str();
}