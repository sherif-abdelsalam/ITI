#include <iostream>
using namespace std;


int* IncrementArrayFixed()
{
    int arr[5] = {1,2,3,4,5};
    for(int i = 0; i < 5; i++)
        arr[i]+=10;

    return arr;
}


int* IncrementArrayDynamic()
{
    int* arr = new int[5]{1,2,3,4,5};

    for(int i = 0; i < 5; i++)
        arr[i]+=10;

    return arr;
}

int main()
{
    int* p1 = IncrementArrayFixed();

    cout<<"Fixed Array \n\n";
    for(int i = 0; i < 5; i++) cout<< p1[i] <<" ";
    cout<<"\n\n\n";

    cout << "Dynamic Array \n" << endl;
    int* p2 = IncrementArrayDynamic();
    for(int i = 0; i < 5; i++) cout << p2[i] <<" ";
    cout<<endl;

    delete[] p2;
    delete[] p1;

    return 0;
}
