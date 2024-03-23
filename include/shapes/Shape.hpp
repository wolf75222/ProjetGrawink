#include "../utils/Color.hpp"
#include "../utils/Drawable.hpp"

class Shape : public Drawable {
protected:
    int id;
    double x = 0.0;
    double y = 0.0;
    double size = 1.0;
    double angle = 0.0;

public:
    Shape(int _id, double _x, double _y, double _size, double _angle) : id(_id), x(_x), y(_y), size(_size), angle(_angle) {};

    virtual void scale(double factor) = 0;
    virtual void translate(double x, double y);
    virtual void rotate(double angle);

    int getId() {
        return this->id;
    };
};