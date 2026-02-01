#include <graphics.h>
#include <iostream>
using namespace std;

class Lamp {
private:
    int x, y;
    int radius;
    bool isOn;

public:
    Lamp(int X, int Y, int R) : x(X), y(Y), radius(R), isOn(false) {}

    void toggle() { isOn = !isOn; }
    bool getState() const { return isOn; }

    int getX() { return x; }
    int getY() { return y; }
    int getRadius() { return radius; }

    void Draw() {

        line(x, y + radius, x, y + radius + 60);
        if (isOn)
            setfillstyle(SOLID_FILL, YELLOW);
        else
            setfillstyle(SOLID_FILL, LIGHTGRAY);

        circle(x, y, radius);
        floodfill(x, y, WHITE);
    }

    bool isClicked(int mx, int my) {
        int dx = mx - x;
        int dy = my - y;
        return dx*dx + dy*dy <= radius*radius;
    }
};

class Man {
private:
    int x, y;
    bool happy;

public:
    Man(int X, int Y) : x(X), y(Y), happy(false) {}

    void setMood(bool mood) { happy = mood; }

    int getX() { return x; }
    int getY() { return y; }

    void Draw() const {

        circle(x, y, 50);
        circle(x - 15, y - 15, 5);
        circle(x + 15, y - 15, 5);

        if (happy)
            arc(x, y + 10, 200, 340, 20);  // smile
        else
            arc(x, y + 20, 20, 160, 20);


        line(x, y + 50, x, y + 150);
        line(x, y + 150, x - 30, y + 200); // left leg
        line(x, y + 150, x + 30, y + 200); // right leg
        line(x, y + 70, x - 50, y + 100);  // left arm
        line(x, y + 70, x + 50, y + 100);  // right arm
    }
};


int main() {
    initwindow(600, 600, "Lamp & Man Interactive");

    Lamp lamp(450, 200, 30);
    Man man(200, 300);


    cleardevice();
    lamp.Draw();
    man.Draw();

    line(man.getX()+50, man.getY()+100, lamp.getX(), lamp.getY() + lamp.getRadius()+60);
    setcolor(WHITE);
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx = mousex();
            int my = mousey();
            clearmouseclick(WM_LBUTTONDOWN);

            if (lamp.isClicked(mx, my)) {
                lamp.toggle();
                man.setMood(lamp.getState());

                cleardevice();
                lamp.Draw();
                man.Draw();
                line(man.getX()+50, man.getY()+100, lamp.getX(), lamp.getY() + lamp.getRadius()+60);
            }
        }
        delay(50);
    }

    closegraph();
    return 0;
}
