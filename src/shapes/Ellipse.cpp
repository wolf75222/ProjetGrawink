#include "../../include/shapes/Ellipse.hpp"

#include <string>
#include <sstream>

void Ellipse::scale(double factor) {
    this->height *= factor;
    this->width *= factor;
}

std::string Ellipse::draw() const {
    std::stringstream ss;
    
    ss << "<ellipse id=\"" <<
    id << "\" cx=\"" << 
    center.getX() << "\" cy=\"" << 
    center.getY() << "\" rx=\"" << 
    width << "\" ry=\"" << 
    height << "\" fill=\"" << 
    fill.asSVG() << "\" stroke=\"" << 
    stroke.asSVG() << "\" stroke-width=\"" << 
    stroke_width << "\" transform=\"rotate(" <<
    angle << " " << center.getX() << " " << center.getY() << ")\"/>";
    
    return ss.str();
}