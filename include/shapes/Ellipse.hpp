#pragma once

#include "Shape.hpp"

/**
 * @brief A class that represents an ellipse.
 * 
 * This class inherits from the Shape class and represents an ellipse.
 */
class Ellipse : public Shape {
private:
    double width = 1.0; ///< The width of the ellipse.
    double height = 1.0; ///< The height of the ellipse.

public:
    /**
     * @brief Construct a new Ellipse object.
     * 
     * @param _id The ID of the ellipse.
     * @param _center The center point of the ellipse.
     * @param _width The width of the ellipse.
     * @param _height The height of the ellipse.
     * @param _angle The rotation angle of the ellipse.
     */
    Ellipse(int _id, Point& _center, double _width, double _height, double _angle) : Shape(ShapeType::Ellipsis, _id, _center, _angle), width(_width), height(_height) {};    

    /**
     * @brief Scale the ellipse by a given factor.
     * 
     * @param factor The factor to scale the ellipse by.
     */
    void scale(double factor) override;

    /**
     * @brief Check if the ellipse is outside a given rectangle.
     * 
     * @param x The x-coordinate of the top-left corner of the rectangle.
     * @param y The y-coordinate of the top-left corner of the rectangle.
     * @param width The width of the rectangle.
     * @param height The height of the rectangle.
     * @return true if the ellipse is outside the rectangle, false otherwise.
     */
    bool isOutside(int x, int y, int width, int height) const override;

    /**
     * @brief Draw the ellipse.
     * 
     * @return A string that represents the ellipse.
     */
    std::string draw() const override;
};