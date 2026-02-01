#include <iostream>
#include <graphics.h>
using namespace std;

#include <iostream>
#include <graphics.h>
using namespace std;


class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    void setX(int X) { x = X; }
    void setY(int Y) { y = Y; }

    int getX() const { return x; }
    int getY() const { return y; }

    void Draw() const {
        putpixel(x, y, WHITE);
    }
};

class Line {
private:
    Point start;
    Point end;

public:
    Line() : start(0,0), end(0,0) {}
    Line(Point s, Point e) : start(s), end(e) {}

    void setStart(Point s) { start = s; }
    void setEnd(Point e) { end = e; }

    Point getStart() { return start; }
    Point getEnd() { return end; }

    void Draw() {
        setcolor(RED);
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};


class Rect {
private:
    Point tl;
    Point t2;

public:
    Rect() : tl(0,0), t2(0,0) {}
    Rect(Point p1, Point p2) : tl(p1), t2(p2) {}


    void setTopLeft(Point p) { tl = p; }
    void setBottomRight(Point p) { t2 = p; }

    void Draw() {
        setcolor(BLUE);
        rectangle(tl.getX(), tl.getY(), t2.getX(),t2.getY());
    }
};


class Circle {
private:
    Point center;
    int radius;

public:
    Circle() : center(0,0), radius(0) {}
    Circle(Point c, int r) : center(c), radius(r) {}

    void setCenter(Point c) { center = c; }
    void setRadius(int r)   { radius = r; }

    void Draw() {
        setcolor(YELLOW);
        circle(center.getX(), center.getY(), radius);
    }
};

int main() {

    initwindow(800, 600);

    Point p1(300, 250);
    Point p2(500, 350);

    Line L(p1, p2);

    Rect R(p1, p2);

    Circle C(Point(400,300), 50);

    L.Draw();
    R.Draw();
    C.Draw();

    getch();
    closegraph();
    return 0;
}
