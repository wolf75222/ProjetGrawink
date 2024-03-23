class Color {
private:
    int r;
    int g;
    int b;
    double a;
    
public:
    char* asSVG() {
        return "rgba()";
    }
};