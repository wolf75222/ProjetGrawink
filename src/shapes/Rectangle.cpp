#include "../../include/shapes/Rectangle.hpp"

#include <string>
#include <sstream>

void Rectangle::scale(double factor)
{
    this->height *= factor;
    this->width *= factor;
}

std::string Rectangle::draw() const
{
    std::stringstream ss;

    ss << "<rect id=\"" << id << "\" x=\"" << center.getX() << "\" y=\"" << center.getY() << "\" width=\"" << width << "\" height=\"" << height << "\" fill=\"" << fill.asSVG() << "\" stroke=\"" << stroke.asSVG() << "\" stroke-width=\"" << stroke_width << "\" transform=\"rotate(" << angle << " " << center.getX() << " " << center.getY() << ")\"/>";

    return ss.str();
}



bool Rectangle::isOutside(int x, int y, int width, int height) const
{
    return (center.getX() + this->width < x || center.getX() - this->width > x + width || center.getY() + this->height < y || center.getY() - this->height > y + height);
}