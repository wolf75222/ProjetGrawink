#pragma once

#include <string>

/**
 * @class Drawable
 * @brief The Drawable class represents an object that can be drawn.
 *
 * The Drawable class provides a method for drawing objects.
 */
class Drawable {

public:
    /**
     * @brief Construct a new Drawable object.
     */
    Drawable() = default;
    /**
     * @brief Destroy the Drawable object.
     */
    ~Drawable() = default;

    /**
     * @brief Draw the object.
     *
     * @return A string that represents the object.
     */
    virtual std::string draw() const = 0;
};