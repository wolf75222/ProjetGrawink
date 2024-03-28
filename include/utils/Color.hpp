class Color {
private:
    int r;
    int g;
    int b;
    double a;

public:
    std::string asSVG() {
        return "rgba()";
    }
};