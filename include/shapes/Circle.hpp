#pragma once

#include "Shape.hpp"

/**
 * @brief A class that represents a circle.
 * 
 * This class inherits from the Shape class and represents a circle.
 */
class Circle : public Shape
{
private:
    double radius = 1.0; ///< The radius of the circle.

public:
    /**
     * @brief Construct a new Circle object.
     * 
     * @param _id The ID of the circle.
     * @param _center The center point of the circle.
     * @param _radius The radius of the circle.
     * @param _angle The rotation angle of the circle.
     */
    Circle(int _id, Point &_center, double _radius, double _angle) : Shape(ShapeType::Ellipsis, _id, _center, _angle), radius(_radius){};

    /**
     * @brief Scale the circle by a given factor.
     * 
     * @param factor The factor to scale the circle by.
     */
    void scale(double factor) override;

    /**
     * @brief Rotate the circle around a given point by a given angle.
     * 
     * @param p The point to rotate the circle around.
     * @param angle The angle to rotate the circle by.
     */
    void rotate(const Point &p, double angle) override;

    /**
     * @brief Check if the circle is outside a given rectangle.
     * 
     * @param x The x-coordinate of the top-left corner of the rectangle.
     * @param y The y-coordinate of the top-left corner of the rectangle.
     * @param width The width of the rectangle.
     * @param height The height of the rectangle.
     * @return true if the circle is outside the rectangle, false otherwise.
     */
    bool isOutside(int x, int y, int width, int height) const override;

    /**
     * @brief Draw the circle.
     * 
     * @return A string that represents the circle.
     */
    std::string draw() const override;
};