#include <iostream>
#include <algorithm>
using namespace std;

bool BSearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return true;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int BSearchRec(int arr[], int left, int right, int target) {

    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] < target)
        return BSearchRec(arr, mid + 1, right, target);
    else
        return BSearchRec(arr, left, mid - 1, target);
}


int main()
{
    int arr[] = {4, 3, 1, 2, 5, 9, 7, 10, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr+n);

    cout<<BSearchRec(arr,0,n,3)<<endl;

    return 0;
}
