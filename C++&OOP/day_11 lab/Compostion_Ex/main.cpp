#include <iostream>
#include <graphics.h>
using namespace std;

class Shape {
protected:
    int color;
public:
    Shape(int c = WHITE) : color(c) {}
    void setColor(int c) { color = c; }
    int getColor() { return color; }
    virtual void Draw() = 0;
};

class Point {
private:
    int x, y;
public:
    Point(int x=0, int y=0) : x(x), y(y) {}
    void setX(int X) { x = X; }
    void setY(int Y) { y = Y; }
    int getX() { return x; }
    int getY() { return y; }
};

class Line : public Shape {
private:
    Point start, end;
public:
    Line(Point s, Point e, int c=RED) : Shape(c), start(s), end(e) {}
    void Draw() {
        setcolor(color);
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

class Rect : public Shape {
private:
    Point tl, br;
public:
    Rect(Point p1, Point p2, int c=BLUE) : Shape(c), tl(p1), br(p2) {}
    void Draw() {
        setcolor(color);
        rectangle(tl.getX(), tl.getY(), br.getX(), br.getY());
    }
};

class Circle : public Shape {
private:
    Point center;
    int radius;
public:
    Circle(Point c, int r, int col=YELLOW) : Shape(col), center(c), radius(r) {}
    void Draw() {
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
    }
};

class Picture {
private:
    Shape* shapes[10];
    int size;
public:

    Picture(Shape* arr[], int n) {
        size = n;
        for (int i = 0; i < size; i++)
            shapes[i] = arr[i];
    }
    void Paint() {
        for (int i = 0; i < size; i++)
            shapes[i]->Draw();
    }
    ~Picture(){
        delete[] shapes;
    }
};

int main() {

    initwindow(800, 600);

    Line L1(Point(100, 100), Point(300, 100), RED);
    Rect R1(Point(150, 150), Point(350, 300), BLUE);
    Circle C1(Point(400, 250), 60, YELLOW);
    Rect R2(Point(260, 300), Point(500, 450), WHITE);
    Circle C2(Point(300, 250), 49, LIGHTCYAN);
    Circle C3(Point(450, 250), 49, CYAN);

    Shape* arr[6] = { &L1, &R1, &C1 ,&C2, &R2, &C3 };

    Picture pic(arr, 6);
    pic.Paint();

    getch();
    closegraph();
    return 0;
}
