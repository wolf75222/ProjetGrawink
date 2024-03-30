#pragma once

#include <string>
#include <sstream>

class Color {
private:
    int red = 0;
    int green = 0;
    int blue = 0;
    double alpha = 1.0;

public:
    Color() = default;
    Color(int _red, int _green, int _blue, double _alpha) : red(_red), green(_green), blue(_blue), alpha(_alpha) {};

    std::string asSVG() const {
        std::stringstream ss;
        ss << "rgba(" << red << ", " << green << ", " << blue << ", " << alpha << ")";
    
        return ss.str();
    }
};