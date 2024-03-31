#pragma once

#include "Shape.hpp"
#include <vector>
#include <cmath>

/**
 * @brief A class that represents a polygon.
 * 
 * This class inherits from the Shape class and represents a polygon.
 */
class Polygon : public Shape {
private:
    std::vector<Point> vertices; ///< The vertices of the polygon.

public:
    /**
     * @brief Construct a new Polygon object.
     * 
     * @param _id The ID of the polygon.
     * @param _center The center point of the polygon.
     * @param _angle The rotation angle of the polygon.
     * @param args The vertices of the polygon.
     */
    template<typename... Args> Polygon(int _id, Point& _center, double _angle, Args&&... args) : Shape(ShapeType::Polygon ,_id, _center, _angle), vertices{std::forward<Args>(args)...} {
        switch (vertices.size()) {
            case 5:
                type = ShapeType::Pentagon;
                break;
            case 6:
                type = ShapeType::Hexagon;
                break;
            case 7:
                type = ShapeType::Heptagon;
                break;
            case 8:
                type = ShapeType::Octogon;
                break;
            default:
                type = ShapeType::Polygon;
                break;
        }
    }

    /**
     * @brief Get the center point of the polygon.
     * 
     * @return The center point of the polygon.
     */
    Point getCenter() const override;

    /**
     * @brief Translate the polygon by a given point.
     * 
     * @param p The point to translate the polygon by.
     */
    void translate(const Point& p) override;

    /**
     * @brief Rotate the polygon around a given point by a given angle.
     * 
     * @param p The point to rotate the polygon around.
     * @param angle The angle to rotate the polygon by.
     */
    void rotate(const Point& p, double angle) override;

    /**
     * @brief Scale the polygon by a given factor.
     * 
     * @param factor The factor to scale the polygon by.
     */
    void scale(double factor) override;

    /**
     * @brief Check if the polygon is outside a given rectangle.
     * 
     * @param x The x-coordinate of the top-left corner of the rectangle.
     * @param y The y-coordinate of the top-left corner of the rectangle.
     * @param width The width of the rectangle.
     * @param height The height of the rectangle.
     * @return true if the polygon is outside the rectangle, false otherwise.
     */
    bool isOutside(int x, int y, int width, int height) const override;

    /**
     * @brief Draw the polygon.
     * 
     * @return A string that represents the polygon.
     */
    std::string draw() const override;
};