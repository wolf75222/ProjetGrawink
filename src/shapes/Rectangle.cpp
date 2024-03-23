#include <string>
#include <sstream>

#include "../../include/shapes/Rectangle.hpp"

void Ellipse::scale(double factor) {
    this->height *= factor;
    this->width *= factor;
}

std::string Ellipse::draw() {
    std::stringstream ss;
    
    ss << "<rect id=\"" <<
    id << "\" x=\"" << 
    x << "\" y=\"" << 
    y << "\" width=\"" << 
    width << "\" height=\"" << 
    height << "\" fill=\"" << 
    color.asSVG() << "\" stroke=\"" << 
    stroke.asSVG() << "\" stroke-width=\"" << 
    stroke_width << "transform=\"rotate(" <<
    angle << " " << x << " " << y << ")\"/>";
    
    return ss.str();
}