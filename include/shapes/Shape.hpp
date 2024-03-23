#include "../utils/Color.hpp"
#include "../utils/Drawable.hpp"

class Shape : public Drawable {
private:
    int id;
    double x = 0.0;
    double y = 0.0;
    double size = 1.0;
    double angle = 0.0;

    bool filled = false;

public:
    virtual void scale(float factor) = 0;
    virtual void translate() = 0;
    virtual void rotate() = 0;
    virtual void fill() = 0;
    
    int getId() {
        return this->id;
    };
};