#include <iostream>

using namespace std;

int recursicePower(int n, int pow){
    if(pow == 0) return 1;
    return n * recursicePower(n,pow-1);

}
// 4 ^ 3

int main()
{
    int num, pow;
    cout<<"Enter Number: ";
    cin>>num;
    cout<<"Enter Power: ";
    cin>>pow;
    cout<<recursicePower(num,pow);
    return 0;
}
