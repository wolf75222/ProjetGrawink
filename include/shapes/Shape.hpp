#pragma once

#include "../utils/Drawable.hpp"
#include "../utils/Transformable.hpp"
#include "../utils/Color.hpp"

#include <iostream>
#include <string>
#include <cstdint>

/**
 * @class Shape
 * @brief The Shape class represents a drawable shape on a canvas.
 *
 * The Shape class provides methods for translating, rotating, and scaling shapes on a canvas.
 * It also supports setting the fill and stroke colors, as well as the stroke width of the shape.
 * The class is abstract and serves as a base class for specific shape implementations.
 */
class Shape : public Drawable, Transformable
{
protected:
    int id;             ///< The unique identifier of the shape.
    double angle = 0.0; ///< The rotation angle of the shape.

    Point center;           ///< The center point of the shape.
    Color fill = Color();   ///< The fill color of the shape.
    Color stroke = Color(); ///< The stroke color of the shape.

    double stroke_width = 1.0; ///< The stroke width of the shape.

public:
    /**
     * @enum ShapeType
     * @brief The ShapeType enum represents the type of the shape.
     */
    enum class ShapeType : uint64_t
    {
        Stroke = 1ULL << 0,
        Triangle = 1ULL << 1,
        Rectangle = 1ULL << 2,
        Pentagon = 1ULL << 3,
        Hexagon = 1ULL << 4,
        Heptagon = 1ULL << 5,
        Octogon = 1ULL << 6,
        Ellipsis = 1ULL << 7,
        Polygon = 1ULL << 8,
        All = ~0ULL
    };
    ShapeType type; ///< The type of the shape.

    /**
     * @brief Shape constructor.
     * @param _type The type of the shape.
     * @param _id The unique identifier of the shape.
     * @param _center The center point of the shape.
     * @param _angle The rotation angle of the shape.
     */
    Shape(ShapeType _type, int _id, Point &_center, double _angle) : type(_type), id(_id), center(_center), angle(_angle) {}

    /**
     * @brief Represents a point in a two-dimensional space.
     * @return The center point of the shape.
     */
    virtual Point getCenter() const { return center; }

    /**
     * @brief setCenter sets the center point of the shape.
     * @param p The new center point of the shape.
     */
    virtual void setCenter(const Point &p) { center = p; }

    /**
     * @brief Translate the shape by a given point.
     * @param p The point to translate the shape by.
     */
    void translate(const Point &p) override;

    /**
     * @brief Rotate the shape around a given point by a given angle.
     * @param p The point to rotate the shape around.
     * @param angle The angle to rotate the shape by.
     */
    void rotate(const Point &p, double angle) override;

    /**
     * @brief Scale the shape by a given factor.
     * @param factor The factor to scale the shape by.
     */
    void scale(double factor) override = 0;

    /**
     * @brief Get the fill color of the shape.
     * @return The fill color of the shape.
     */
    const Color &getFillColor() const { return fill; }

    /**
     * @brief Get the stroke color of the shape.
     * @return The stroke color of the shape.
     */
    const Color &getStrokeColor() const { return stroke; }

    /**
     * @brief Get the stroke width of the shape.
     * @return The stroke width of the shape.
     */
    double getStrokeWidth() const { return stroke_width; }

    /**
     * @brief Set the fill color of the shape.
     * @param color The color to set the fill color to.
     */
    void setFillColor(const Color &color) { fill = color; }

    /**
     * @brief Set the stroke color of the shape.
     * @param color The color to set the stroke color to.
     */
    void setStrokeColor(const Color &color) { stroke = color; }

    /**
     * @brief Set the stroke width of the shape.
     * @param width The width to set the stroke width to.
     */
    void setStrokeWidth(double width) { stroke_width = width; }

    /**
     * @brief Check if the shape is outside a given rectangle.
     * @param x The x-coordinate of the top-left corner of the rectangle.
     * @param y The y-coordinate of the top-left corner of the rectangle.
     * @param width The width of the rectangle.
     * @param height The height of the rectangle.
     * @return true if the shape is outside the rectangle, false otherwise.
     */
    virtual bool isOutside(int x, int y, int width, int height) const;

    /**
     * @brief Get the type of the shape.
     * @return The type of the shape.
     */
    ShapeType getType();

    /**
     * @brief Get the name of the shape.
     * @return The name of the shape.
     */
    std::string getName();

    /**
     * @brief Print the shape.
     */
    void print();

    /**
     * @brief Get the ID of the shape.
     * @return The ID of the shape.
     */
    int getId() const { return this->id; };
};