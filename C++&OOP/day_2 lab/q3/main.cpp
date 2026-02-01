#include <iostream>
#include "MyLibrary.h"

using namespace std;

int main() {
    int n;
    do{
        cout<<"Enter odd number: " ;
        cin>>n;
    }while(!(n&1));

    int row = 0;
    int col = n / 2;

    int x_offset = 40;
    int y_offset = 5;

    cout << "Magic Box Order " << n << endl;

    // Loop from 1 to 9
    for (int i = 1; i <= n * n; i++) {

        gotoxy(col * 4 + x_offset, row * 2 + y_offset);

        cout << i;

        if (i % n == 0) {
            row++;
        }
        else {
            row--;
            col--;
        }
        if (row < 0) row = n - 1;
        if (row == n) row = 0;

        if (col < 0) col = n - 1;
        if (col == n) col = 0;
    }


    return 0;
}
