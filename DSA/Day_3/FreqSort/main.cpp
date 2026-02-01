#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> freq;

bool FreqSortComp(int a, int b) {
    if (freq[a] != freq[b])
        return freq[a] > freq[b];
    return a < b;
}

void sortByFrequency(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    sort(arr,arr+n, FreqSortComp);
}

int main() {
    int arr[] = {5, 5, 4, 6, 4};
//    int arr[] ={9, 9, 9, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortByFrequency(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
