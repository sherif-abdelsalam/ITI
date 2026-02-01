#include <iostream>
using namespace std;

class GeoShape {
protected:
    float dim1;
    float dim2;

public:
    GeoShape() : dim1(0), dim2(0) {}

    GeoShape(float d1, float d2) : dim1(d1), dim2(d2) {}

    void setDim1(float d1) { dim1 = d1; }
    void setDim2(float d2) { dim2 = d2; }

    float getDim1() { return dim1; }
    float getDim2() { return dim2; }

    virtual float CalcArea() = 0;
};


class Rectangle : public GeoShape {
public:
    Rectangle(float w, float h) : GeoShape(w, h) {}

    float CalcArea() {
        return dim1 * dim2;
    }
};


class Square : protected GeoShape {
public:
    Square(float side) : GeoShape(side, side) {}

    void setSide(float side) {
        dim1 = dim2 = side;
    }

    float CalcArea() {
        return dim1 * dim2;
    }
};


class Circle : protected GeoShape {
public:
    Circle(float radius) : GeoShape(radius, radius) {}

    void setRadius(float r) {
        dim1 = dim2 = r;
    }

    float CalcArea() {
        float r = dim1;
        return 3.14f * r * r;
    }
};


class Triangle : public GeoShape {
public:
    Triangle(float base, float height) : GeoShape(base, height) {}

    float CalcArea() {
        return 0.5f * dim1 * dim2;
    }
};


int main() {
    Rectangle r(4, 5);
    Square s(5);
    Circle c(3);
    Triangle t(6, 8);

//    s.setDim1(4);
//    GeoShape g;

    cout << "Rectangle Area = " << r.CalcArea() << endl;
    cout << "Square Area    = " << s.CalcArea() << endl;
    cout << "Circle Area    = " << c.CalcArea() << endl;
    cout << "Triangle Area  = " << t.CalcArea() << endl;

    return 0;
}
