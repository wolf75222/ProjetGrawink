#pragma once

#include <string>

class Drawable {

public:
    Drawable() = default;
    ~Drawable() = default;

    virtual std::string draw() const = 0;
};