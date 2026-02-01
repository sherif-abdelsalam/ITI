#include <iostream>
using namespace std;

int sum1(int x, int y, int z) {
    return x + y + z;
}

int sum2(int x, int y, int z = 0) {
    return x + y + z;
}

int sum3(int x, int y = 0, int z = 0) {
    return x + y + z;
}

int sum4(int x = 0, int y = 0, int z = 0) {
    return x + y + z;
}

int main() {

    cout << "Sum1 : "<< sum1(44,32,12) << endl;
    cout<<"============\n";

    cout << "sum2_1 : " << sum2(21,13) << endl;
    cout << "sum2_2 : " << sum2(21,13,12) << endl;
    cout<<"============\n";

    cout << "sum3_1 : " << sum3(21) << endl;
    cout << "sum3_2 : " << sum3(21,13) << endl;
    cout << "sum3_3 : " << sum3(21,13,12) << endl;
    cout<<"============\n";

    cout << "sum4_1 : " << sum4() << endl;
    cout << "sum4_2 : " << sum4(5) << endl;
    cout << "sum4_3 : " << sum4(5,10) << endl;
    cout << "sum4_4 : " << sum4(5,10,15) << endl;

    return 0;
}
