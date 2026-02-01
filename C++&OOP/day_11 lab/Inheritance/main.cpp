#include <iostream>
using namespace std;

class Base {
private:
    int x;
protected:
    int y;
public:
    Base() {
        x = 0;
        y = 0;
//        cout << "Base ctr\n";
    }

    Base(int x, int y) {
        this->x = x;
        this->y = y;
//        cout << "Base Parameterized ctr\n";
    }

    ~Base() {
//        cout << "Base dctr\n";
    }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    int getX() { return x; }
    int getY() { return y; }

    int sum() {
        return x + y;
    }
};

class Derived : public Base {
private:
    int z;
public:
    Derived() : Base() {
        z = 0;
//        cout << "Derived ctr\n";
    }

    Derived(int x, int y, int z) : Base(x, y) {
        this->z = z;
//        cout << "Derived Parameterized ctr\n";
    }

    ~Derived() {
//        cout << "Derived dctr\n";
    }

    void setZ(int z) { this->z = z; }
    int getZ() { return z; }

    int sum() {
        return getX() + y + z;
    }
};

class Derived_Junior : public Derived {
private:
    int m;

public:
    Derived_Junior() : Derived() {
        m = 0;
//        cout << "Derived_Junior ctr\n";
    }

    Derived_Junior(int x, int y, int z, int m): Derived(x, y, z)
    {
        this->m = m;
//        cout << "Derived_Junior Parameterized ctr\n";
    }

    ~Derived_Junior() {
//        cout << "Derived_Junior dctr\n";
    }

    void setM(int m) { this->m = m; }
    int getM() const { return m; }

    int sum() {
        return Derived::sum() + m;
    }
};


int main() {
    Derived_Junior jon_driv(1, 2, 3, 4);

    Base* base_to_jon = &jon_driv;
    cout << base_to_jon->sum() << endl;

//     base_to_jon->getZ();

    Derived* driv_to_jon = &jon_driv;

    cout << driv_to_jon->sum() << endl;

    Derived_Junior* jon_to_jon = &jon_driv;

    cout << jon_to_jon->sum() << endl;

    return 0;
}


