#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter Character: ";
    cin >> ch;

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        cout << ch << " is an alphabet.";
    } else {
        cout << ch << " is NOT an alphabet.";
    }

    return 0;
}

