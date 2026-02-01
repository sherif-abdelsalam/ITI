#include <iostream>

using namespace std;

template <typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}


class Complex {
private:
    float real;
    float img;

public:
    Complex() {
        this->real = 0;
        this->img = 0;
//        cout << "Parameterless Constructor\n";
    }

    Complex(int r, float i) {
        this->real = r;
        this->img = i;
//        cout << "Two parameters Constructor\n";
    }

    Complex(float val) {
        this->real = val;
        this->img = 0;
//        cout << "One parameters Constructor\n";
    }



    void setReal(float r)  { this->real = r; }
    void setImg(float i)   { this->img = i; }

    float getReal() const { return this->real; }
    float getImg()  const { return this->img; }

    Complex(const Complex &C) {
        this->real = C.real;
        this->img  = C.img;
//        cout << "Copy Constructor\n";
    }

    Complex AddComplex(Complex C);
    Complex SubComplex(Complex C);
    void PrintComplex();
    ~Complex() {
//        cout << "Destructor for (" << this->real << "," << this->img << "i)\n";
    }


    /// Operators
    /// =
    Complex operator=(const Complex&C ){
        this->real = C.real;
        this->img = C.img;
        return *this;
    }
    /// C1 - C
    Complex operator-(const Complex& C) {
        return Complex(this->real - C.real, this->img - C.img);
    }
    /// C1 - val
    Complex operator-(int val) {
        return Complex(this->real - val, this->img);
    }

    /// val - C1
    friend Complex operator-(int val, const Complex& C);

    /// C1 -= C
    Complex& operator-=(const Complex& C) {
        this->real -= C.real;
        this->img  -= C.img;
        return *this;
    }

    Complex& operator--() {
        this->real--;
        this->img--;
        return *this;
    }

    Complex operator--(int) {
        Complex temp(*this);
        this->real--;
        this->img--;
        return temp;
    }

    bool operator==(const Complex& C) {
        return (this->real == C.real) && (this->img == C.img);
    }

    bool operator!=(const Complex& C) {
        return !(*this == C);
    }

    bool operator<(const Complex& C) {
        if (this->real < C.real) return true;
        if (this->real == C.real && this->img < C.img) return true;
        return false;
    }

    bool operator>(const Complex& C) const {
        if (this->real > C.real) return true;
        if (this->real == C.real && this->img > C.img) return true;
        return false;
    }

    bool operator<=(const Complex& C) const {
        return (*this < C) || (*this == C);
    }

    bool operator>=(const Complex& C) const {
        return (*this > C) || (*this == C);
    }

     operator int() const {
        return static_cast<int>(real);
    }

    float& operator[](char c){
        return (c == 'R' || c == 'r') ? real : img;
    }
};

Complex operator-(int val, const Complex& C) {
    return Complex(val - C.real, -C.img);
}

Complex Complex::AddComplex(Complex C){
    Complex result;
    result.real = this->real + C.real;
    result.img  = this->img  + C.img;
    return result;
}

Complex Complex::SubComplex(Complex C){
    Complex result;
    result.real = this->real - C.real;
    result.img  = this->img  - C.img;
    return result;

}


void Complex::PrintComplex(){
    if (real == 0 && img == 0)
        cout << "0";
    else if (img == 0)
        cout << real;
    else if (real == 0)
        cout << img << "i";
    else if (img > 0)
        cout << real << "+" << img << "i";
    else
        cout << real << img << "i";

    cout << endl;
}


template <typename T>
class Stack{
private:
    T* stk;
    int size;
    int top;
    static int counter;

public:
    // Constructors
    Stack() {
        size = 5;
        top = 0;
        stk = new T[size];
        counter++;
//        cout << "Parameterless Constructor\n";
    }

    Stack(int size) {
        this->size = size;
        top = 0;
        stk = new T[size];
        counter++;
//        cout << "Parameterized Constructor\n";
    }

    Stack(const Stack& S) {
        size = S.size;
        top = S.top;
        stk = new T[size];
        for(int i = 0; i < top; i++)
            stk[i] = S.stk[i];
        counter++;
//        cout << "Copy Constructor\n";
    }

    ~Stack() {
        delete[] stk;
        counter--;
//        cout << "Destructor\n";
    }

    static int getCounter() { return counter; }

    bool isEmpty() { return top == 0; }
    bool isFull()  { return top == size; }

    T Peak() { return isEmpty() ? -1 : stk[top - 1]; }

    void Push(T e) {
        if(isFull()) { cout << "Stack is full\n"; return; }
        stk[top++] = e;
    }

    T Pop() {
        if(isEmpty()) { cout << "Stack is empty\n"; return -1; }
        return stk[--top];
    }

    Stack Reverse() {
        Stack rev(top);
        for(int i = top - 1; i >= 0; i--)
            rev.Push(stk[i]);
        return rev;
    }

    void PrintStack() {
        for(int i = 0; i < top; i++)
            cout << stk[i] << " ";
        cout << endl;
    }

    Stack& operator=(const Stack& S){
            delete[] this->stk;
            size = S.size;
            top = S.top;
            stk = new T[size];
            for(int i = 0; i < top; i++)
                stk[i] = S.stk[i];

        return *this;
    }

    Stack operator+(const Stack& S) {
        Stack result(top + S.top);
        for(int i = 0; i < top; i++)
            result.Push(stk[i]);
        for(int i = 0; i < S.top; i++)
            result.Push(S.stk[i]);
        return result;
    }

    T& operator[](int idx) { return stk[idx]; }

};

template <typename T>
int Stack<T>::counter = 0;

int main()
{
    int a=3, b = 5;
    Swap<int>(a,b);
    cout<<a<<" "<<b<<endl;

    char Ch1='Z', Ch2='O';
    Swap<char>(Ch1, Ch2);
    cout<< Ch1<<" "<<Ch2<<endl;

    cout<<"===============\n";
    Complex C1(5), C2(2,7);
    Swap<Complex>(C1, C2);
    C1.PrintComplex();
    C2.PrintComplex();

    cout<<"===============\n";    Stack<int> S;
    Stack<int> S5;
    S.Push(10);
    S.Push(20);
    cout<< S.Pop()<<endl;

    cout<<"===============\n";    Stack<char> S2(3);
    S2.Push('A');
    S2.Push('B');
    S2.Push('C');
    cout<< S2.Pop()<<endl;

    cout<<"===============\n";
    Stack<Complex> S3(4);
    S3.Push(C2);
    S3.Push(C1);
    Complex C = S3.Pop();
    C.PrintComplex();
    return 0;
}
