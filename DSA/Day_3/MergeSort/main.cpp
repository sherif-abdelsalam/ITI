#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
         for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void mergeSortedArrays(int arr[], int left, int mid, int right) {

    int size = right - left + 1;
    int* temp = new int[size];

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < size; p++) {
        arr[left + p] = temp[p];
    }

    delete[] temp;
}


void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = (left+right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    mergeSortedArrays(arr, left, mid, right);
}



int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) cout << arr[i] << " "; cout<<"\n===============\n";
//
//    selectionSort(arr, n);
//    for (int i = 0; i < n; i++) cout << arr[i] << " "; cout<<endl;
//
//    bubbleSort(arr, n);
//    for (int i = 0; i < n; i++) cout << arr[i] << " "; cout<<endl;

    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) cout << arr[i] << " "; cout<<endl;



    return 0;
}
