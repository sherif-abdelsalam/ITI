#include <iostream>

using namespace std;
// 3. what is the output from the following?
// using namespace std; // Assuming this is intended based on cout usage
class test
{
private:
    int x;

public:
    // 1. Constructor (with default argument)
    test(int _x = 0)
    {
        x = _x;
    }

    // 2. Copy Constructor
    test(test &z)
    {
        x = z.x;
        z.x = 0; // The key modification in this copy constructor
    }

    void print()
    {
        std::cout << x; // Using std::cout for explicit namespace
    }
};

int main()
{
    test t1(20);
    test t2 = t1;
    t1.print();
    std::cout << ":";
    t2.print();
    return 0;
}
