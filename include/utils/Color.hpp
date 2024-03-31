#pragma once

#include <string>
#include <sstream>

/**
 * @brief A class that represents a color.
 * 
 * This class represents a color with red, green, blue, and alpha components.
 */
class Color {
private:
    int red = 0; ///< The red component of the color.
    int green = 0; ///< The green component of the color.
    int blue = 0; ///< The blue component of the color.
    double alpha = 1.0; ///< The alpha component of the color.

public:
    /**
     * @brief Construct a new Color object.
     */
    Color() = default;

    /**
     * @brief Construct a new Color object.
     * 
     * @param _red The red component of the color.
     * @param _green The green component of the color.
     * @param _blue The blue component of the color.
     * @param _alpha The alpha component of the color.
     */
    Color(int _red, int _green, int _blue, double _alpha) : red(_red), green(_green), blue(_blue), alpha(_alpha) {};

    /**
     * @brief asSVG returns the color as an SVG string.
     * @return The color as an SVG string.
     */
    std::string asSVG() const {
        std::stringstream ss;
        ss << "rgba(" << red << ", " << green << ", " << blue << ", " << alpha << ")";
    
        return ss.str();
    }
};