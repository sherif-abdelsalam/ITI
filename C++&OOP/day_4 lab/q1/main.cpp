#include <iostream>

using namespace std;

int largest_number(int number1, int number2, int number3){

    int largestNumber = number1;
    if (number2 > largestNumber) largestNumber = number2;
    if (number3 > largestNumber) largestNumber = number3;

    return largestNumber;
}

int main()
{
    int num1, num2, num3;
    cout<<"Enter 3 numbers and get the largest: ";
    cin>> num1 >> num2 >> num3;
    int maxNum = largest_number(num1,num2,num3);
    cout<<"Largest Number is : " <<maxNum;
    return 0;
}
