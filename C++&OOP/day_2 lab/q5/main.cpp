#include <iostream>
using namespace std;

int main() {
    int n;
    cout <<"Enter table number: ";
    cin >> n;

    for (int i = 1; i <= 12; i++) {
        cout << i << " * " << n << " = " << i * n << endl;
    }

    return 0;
}
