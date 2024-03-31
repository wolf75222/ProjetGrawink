#pragma once

#include "Shape.hpp"

/**
 * @brief A class that represents a rectangle.
 * 
 * This class inherits from the Shape class and represents a rectangle.
 */
class Rectangle : public Shape {
private:
    double width = 1.0; ///< The width of the rectangle.
    double height = 1.0; ///< The height of the rectangle.

public:
    /**
     * @brief Construct a new Rectangle object.
     * 
     * @param _id The ID of the rectangle.
     * @param _center The center point of the rectangle.
     * @param _width The width of the rectangle.
     * @param _height The height of the rectangle.
     * @param _angle The rotation angle of the rectangle.
     */
    Rectangle(int _id, Point& _center, double _width, double _height, double _angle) : Shape(ShapeType::Rectangle, _id, _center, _angle), width(_width), height(_height) {};
    
    /**
     * @brief Scale the rectangle by a given factor.
     * 
     * @param factor The factor to scale the rectangle by.
     */
    void scale(double factor) override;

    /**
     * @brief Check if the rectangle is outside a given rectangle.
     * 
     * @param x The x-coordinate of the top-left corner of the rectangle.
     * @param y The y-coordinate of the top-left corner of the rectangle.
     * @param width The width of the rectangle.
     * @param height The height of the rectangle.
     * @return true if the rectangle is outside the rectangle, false otherwise.
     */
    bool isOutside(int x, int y, int width, int height) const override;

    /**
     * @brief Draw the rectangle.
     * 
     * @return A string that represents the rectangle.
     */
    std::string draw() const override;
};