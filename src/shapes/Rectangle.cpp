#include <string>
#include <sstream>

#include "../../include/shapes/Rectangle.hpp"

void Rectangle::scale(double factor) {
    this->height *= factor;
    this->width *= factor;
}

std::string Rectangle::draw() const {
    std::stringstream ss;
    
    ss << "<rect id=\"" <<
    id << "\" x=\"" << 
    center.getX() << "\" y=\"" << 
    center.getY() << "\" width=\"" << 
    width << "\" height=\"" << 
    height << "\" fill=\"" << 
    fill.asSVG() << "\" stroke=\"" << 
    stroke.asSVG() << "\" stroke-width=\"" << 
    stroke_width << "\" transform=\"rotate(" <<
    angle << " " << center.getX() << " " << center.getY() << ")\"/>";
    
    return ss.str();
}