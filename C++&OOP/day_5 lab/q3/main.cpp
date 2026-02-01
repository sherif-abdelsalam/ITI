#include <iostream>

using namespace std;


void Calculate(int x, int y, int* SumPtr, int* SubPtr, int* MultipPtr, int* DivPtr){

    *SumPtr = x+y;
    *SubPtr = x-y;
    *MultipPtr = x*y;
    *DivPtr = x/y;
}


int main()
{
    int x, y;
    cout << "Enter X, Y: ";
    cin>>x>>y;
    int SumPtr;
    int SubPtr;
    int MultipPtr;
    int DivPtr;
    Calculate(x,y, &SumPtr, &SubPtr, &MultipPtr, &DivPtr);

    cout<<"Sum = " <<SumPtr <<endl;
    cout<<"Sub = " <<SubPtr <<endl;
    cout<<"Multiple = " <<MultipPtr <<endl;
    cout<<"Div = " <<DivPtr <<endl;

    return 0;
}
