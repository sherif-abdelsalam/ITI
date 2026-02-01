#include <iostream>

using namespace std;

int main()
{
    int n;
    int sum = 0;
    while(sum < 100){
        cout<<"Enter number: ";
        cin>>n;
        sum+=n;
    }
    cout<<"Sum = "<<sum;

    return 0;
}
