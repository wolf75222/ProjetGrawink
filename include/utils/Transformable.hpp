#pragma once

#include <cmath>

class Point;

/**
 * @class Transformable
 * @brief The Transformable class represents an object that can be transformed.
 *
 * The Transformable class provides methods for translating, rotating, and scaling objects.
 */
class Transformable {
public:
    Transformable() = default;
    ~Transformable() = default;

    /**
     * @brief Translate the object by a given point.
     *
     * @param p The point to translate the object by.
     */
    virtual void translate(const Point& p) = 0;

    /**
     * @brief Rotate the object around a given point by a given angle.
     *
     * @param p The point to rotate the object around.
     * @param angle The angle to rotate the object by.
     */
    virtual void rotate(const Point& p, double angle) = 0;

    /**
     * @brief Scale the object by a given factor.
     *
     * @param factor The factor to scale the object by.
     */
    virtual void scale(double factor) = 0;
};

/**
 * @class Point
 * @brief The Point class represents a point in 2D space.
 *
 * The Point class represents a point in 2D space with x and y coordinates.
 */
class Point : Transformable {
private:
    double x = 0.0; ///< The x-coordinate of the point.
    double y = 0.0; ///< The y-coordinate of the point.

public: 
    /**
     * @brief Construct a new Point object.
     *
     * @param _x The x-coordinate of the point.
     * @param _y The y-coordinate of the point.
     */
    Point(double _x, double _y) : x(_x), y(_y) {};

    /**
     * @brief Set the x-coordinate of the point.
     *
     * @param x The x-coordinate of the point.
     */
    void setX(double x) { this->x = x; }

    /**
     * @brief Set the y-coordinate of the point.
     *
     * @param y The y-coordinate of the point.
     */
    void setY(double y) { this->y = y; }

    /**
     * @brief Get the x-coordinate of the point.
     *
     * @return The x-coordinate of the point.
     */
    double getX() const { return x; }

    /**
     * @brief Get the y-coordinate of the point.
     *
     * @return The y-coordinate of the point.
     */
    double getY() const { return y; }

    /**
     * @brief Translate the point by a given point.
     *
     * @param p The point to translate the point by.
     */
    void translate(const Point& p) override {
        this->x += p.x;
        this->y += p.y;
    }

    /**
     * @brief Rotate the point around a given point by a given angle.
     *
     * @param p The point to rotate the point around.
     * @param angle The angle to rotate the point by.
     */
    void rotate(const Point& p, double angle) override {
        double angl = angle * 3.141592653 / 180.0;
        double newX = p.x + (x - p.x) * std::cos(angl) - (y - p.y) * std::sin(angl);
        double newY = p.y + (x - p.x) * std::sin(angl) + (y - p.y) * std::cos(angl);
        x = newX;
        y = newY;
    }

    /**
     * @brief Scale the point by a given factor.
     *
     * @param factor The factor to scale the point by.
     */
    void scale(double factor) override{
        this->x *= factor;
        this->y *= factor;
    }
};