#include <iostream>

using namespace std;

int arr_sum (int *arr, int size){

    long sum = 0;
    cout<<"Array Elements : ";
    for(int i = 0; i < size; i++){
        sum+= *(arr+i);
        cout<<*(arr+i) <<" ";
    }
    cout<<endl;
    return sum;
}


int main()
{
    int size;
    cout << "Enter Array Size: ";
    cin>>size;
    int *arr = new int[size];
    cout << "Enter Array Elements: ";
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    cout<< "Array Sum = " << arr_sum(arr,size)<<endl;

    return 0;
}
