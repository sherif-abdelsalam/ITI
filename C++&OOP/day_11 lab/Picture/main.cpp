#include <iostream>
#include <graphics.h>

using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int X = 0, int Y = 0) : x(X), y(Y) {}
    void setX(int X) { x = X; }
    void setY(int Y) { y = Y; }
    int getX() { return x; }
    int getY() { return y; }
};

class Rect {
private:
    Point topLeft, bottomRight;
    int color;
public:
    Rect(Point p1 = Point(), Point p2 = Point(), int c = WHITE) : topLeft(p1), bottomRight(p2), color(c) {}
    void Draw() {
        setcolor(color);
        rectangle(topLeft.getX(), topLeft.getY(), bottomRight.getX(), bottomRight.getY());
    }
};

class Circle {
private:
    Point center;
    int radius;
    int color;
public:
    Circle(Point c = Point(), int r = 0, int col = WHITE) : center(c), radius(r), color(col) {}
    void Draw() {
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
    }
};

class Line {
private:
    Point start, end;
    int color;
public:
    Line(Point s = Point(), Point e = Point(), int col = WHITE) : start(s), end(e), color(col) {}
    void Draw() {
        setcolor(color);
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

class Picture {
private:
    int cNum, rNum, lNum;
    Circle* pCircles;
    Rect* pRects;
    Line* pLines;
public:
    Picture() : cNum(0), rNum(0), lNum(0), pCircles(NULL), pRects(NULL), pLines(NULL) {}
    void setCircles(int num, Circle* arr) { cNum = num; pCircles = arr; }
    void setRects(int num, Rect* arr) { rNum = num; pRects = arr; }
    void setLines(int num, Line* arr) { lNum = num; pLines = arr; }
    void Paint() {
        for(int i = 0; i < cNum; i++) pCircles[i].Draw();
        for(int i = 0; i < rNum; i++) pRects[i].Draw();
        for(int i = 0; i < lNum; i++) pLines[i].Draw();
    }
};

int main(){
    initwindow(600, 500);

    Circle circles[3] = {
        Circle (Point(300, 250), 49, GREEN),
        Circle (Point(400, 250), 60, YELLOW)
    };

    Rect rects[2] = {
        Rect (Point(150, 150), Point(350, 300), BLUE),
        Rect (Point(260, 300), Point(500, 450), WHITE)
    };

    Line lines[2] = {
        Line (Point(100, 100), Point(300, 100), RED),
        Line (Point(200, 200), Point(400, 400), LIGHTBLUE)
    };

    Picture myPic;
    myPic.setCircles(3, circles);
    myPic.setRects(2, rects);
    myPic.setLines(2, lines);

    myPic.Paint();

    getch();
    closegraph();
    return 0;
}
