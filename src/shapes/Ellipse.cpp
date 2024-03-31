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

bool Ellipse::isOutside(int x, int y, int width, int height) const {
    return (center.getX() + this->width < x || center.getX() - this->width > x + width || center.getY() + this->height < y || center.getY() - this->height > y + height);
}