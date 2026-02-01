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
    int x, y;
public:
    Point(int x=0, int y=0) : x(x), y(y) {}
    int getX() { return x; }
    int getY() { return y; }
};

class Line : public Shape {
    Point start, end;
public:
    Line(Point s, Point e, int c=RED) : Shape(c), start(s), end(e) {}
    void Draw() {
        setcolor(color);
        line(start.getX(), start.getY(), end.getY(), end.getY());
    }
};

class Rect : public Shape {
    Point tl, br;
public:
    Rect(Point p1, Point p2, int c=BLUE) : Shape(c), tl(p1), br(p2) {}
    void Draw() {
        setcolor(color);
        rectangle(tl.getX(), tl.getY(), br.getX(), br.getY());
    }
};

class Circle : public Shape {
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
    Shape*** shapes;   // Pointer to rows
    int* cols;         // Number of shapes in each row
    int rows;

public:
    Picture(Shape*** arr, int* colSizes, int r) {
        rows = r;

        cols = new int[rows];
        shapes = new Shape**[rows];

        for (int i = 0; i < rows; i++) {
            cols[i] = colSizes[i];
            shapes[i] = new Shape*[cols[i]];

            for (int j = 0; j < cols[i]; j++) {
                shapes[i][j] = arr[i][j];
            }
        }
    }

    void Paint() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols[i]; j++) {
                shapes[i][j]->Draw();
            }
        }
    }
};

int main() {
    initwindow(800, 600);

    // Shapes
    Line L1(Point(100, 100), Point(300, 100), RED);
    Line L2(Point(200, 200), Point(400, 400), LIGHTBLUE);
    Rect R1(Point(150, 150), Point(350, 300), BLUE);
    Circle C1(Point(400, 250), 60, YELLOW);
    Rect R2(Point(260, 300), Point(500, 450), WHITE);
    Circle C2(Point(300, 250), 49, GREEN);


    Shape** row1 = new Shape*[2]{ &L1, &R1 };
    Shape** row2 = new Shape*[3]{ &C1, &L2, &R2 };
    Shape** row3 = new Shape*[1]{ &C2 };

    Shape*** jagged = new Shape**[3]{ row1, row2, row3 };

    int colSizes[3] = { 2, 3, 1 };

    Picture pic(jagged, colSizes, 3);

    pic.Paint();

    getch();
    closegraph();
    return 0;
}
