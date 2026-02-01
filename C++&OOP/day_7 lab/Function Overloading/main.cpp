#include <iostream>
#include <cstring>
using namespace std;

class myTestClass
{
public:
    int Add(int x, int y) {
        return x + y;
    }
    int Add(int x, int y, int z) {
        return x + y + z;
    }
    void Add(char c1, char c2, char c3) {
        cout << "Concatenated chars: " << c1 << c2 << c3 << endl;
    }
    void Add(string str1, string str2) {
        cout << "Concatenated strings: " << str1+str2 << endl;
    }
};

int main()
{
    myTestClass overload;

    cout << "Add 2 integers: " << overload.Add(3, 4) << endl;
    cout << "Add 3 integers: " << overload.Add(1, 2, 3) << endl;

    overload.Add('a', 'b', 'c');

    string str1 = "Sherif ";
    string str2 = "Mohammed";
    overload.Add(str1, str2);

    return 0;
}
