#include <iostream>
using namespace std;

class GeoShape {
private:
    float dim1;
    float dim2;

public:
    GeoShape() {
//        cout << "GeoShape Constructor\n";
        dim1 = 0;
        dim2 = 0;
    }

    GeoShape(float d1, float d2) {
//        cout << "GeoShape Parameterized Constructor\n";
        dim1 = d1;
        dim2 = d2;
    }

    ~GeoShape() {
//        cout << "GeoShape Destructor\n";
    }

    void setDim1(float d1) { dim1 = d1; }
    void setDim2(float d2) { dim2 = d2; }

    float getDim1() const { return dim1; }
    float getDim2() const { return dim2; }

    float CalcArea() {
        return 0;
    }
};


class Rectangle : public GeoShape {
public:
    Rectangle() : GeoShape() {
//        cout << "Rectangle Constructor\n";
    }

    Rectangle(float w, float h) : GeoShape(w, h) {
//        cout << "Rectangle Parameterized Constructor\n";
    }

    ~Rectangle() {
//        cout << "Rectangle Destructor\n";
    }

    float CalcArea() {
        return getDim1() * getDim2();
    }
};


class Square : public GeoShape {
public:
    Square() : GeoShape() {
//        cout << "Square Constructor\n";
    }

    Square(float side) : GeoShape(side, side) {
//        cout << "Square Parameterized Constructor\n";
    }

    ~Square() {
//        cout << "Square Destructor\n";
    }

    float CalcArea() const {
        return getDim1() * getDim2();
    }
};


class Circle : public GeoShape {
public:
    Circle() : GeoShape() {
//        cout << "Circle Constructor\n";
    }

    Circle(float radius) : GeoShape(radius, radius) {
//        cout << "Circle Parameterized Constructor\n";
    }

    ~Circle() {
//        cout << "Circle Destructor\n";
    }

    float CalcArea() const {
        float r = getDim1();
        return 3.14f * r * r;
    }
};


class Triangle : public GeoShape {
public:
    Triangle() : GeoShape() {
//        cout << "Triangle Constructor\n";
    }

    Triangle(float base, float height) : GeoShape(base, height) {
//        cout << "Triangle Parameterized Constructor\n";
    }

    ~Triangle() {
//        cout << "Triangle Destructor\n";
    }

    float CalcArea() const {
        return 0.5f * getDim1() * getDim2();
    }
};


int main() {
    Rectangle r(4, 5);
    Square s(5);
    Circle c(3);
    Triangle t(6, 8);

    cout << "Rectangle Area = " << r.CalcArea() << endl;
    cout << "Square Area    = " << s.CalcArea() << endl;
    cout << "Circle Area    = " << c.CalcArea() << endl;
    cout << "Triangle Area  = " << t.CalcArea() << endl;

    return 0;
}
