#include <iostream>
#include <algorithm>
using namespace std;

void SortMatrix(int arr[][3], int rows, int cols) {
    int temp[10];
    int index = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[index++] = arr[i][j];
        }
    }

    sort(temp, temp + index);

    index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = temp[index++];
        }
    }
}

void printMatrix(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    printMatrix(arr, 3, 3);
    SortMatrix(arr, 3, 3);
    cout<<"=====\n";
    printMatrix(arr, 3, 3);

    return 0;
}

