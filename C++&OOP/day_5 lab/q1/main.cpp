#include <iostream>
using namespace std;

void swap_pass_by_value(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swap_pass_by_ptr(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_pass_by_ref(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a, b;

    cout<<"Enter A: ";
    cin>>a;
    cout<<"Enter B: ";
    cin>>b;

    cout<<"\n\nValue swap (No Swap)"<<endl;
    swap_pass_by_value(a,b);
    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<endl;

    cout<<"\n\nPointer swap"<<endl;
    swap_pass_by_ptr(&a,&b);
    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<endl;

    cout<<"\n\nReference swap"<<endl;
    swap_pass_by_ref(a,b);
    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<endl;

    return 0;
}
