#include <iostream>
using namespace std;

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


    friend istream& operator>>(istream& in, Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c);

};

Complex operator-(int val, const Complex& C) {
    return Complex(val - C.real, -C.img);
}
istream& operator>>(istream& in, Complex& c) {
    cout << "Enter real: ";
    in >> c.real;
    cout << "Enter imag: ";
    in >> c.img;
    return in;
}

ostream& operator<<(ostream& out, const Complex& c) {
    if (c.real == 0 && c.img == 0) {
        out << 0;
    }
    else if (c.img == 0) {
        out << c.real;
    }
    else if (c.real == 0) {
        out << c.img << "i";
    }
    else {
        out << c.real;
        if (c.img > 0)
            out << " + " << c.img << "i";
        else
            out << " - " << -c.img << "i";
    }
    return out;
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

int main()
{
//    Complex C1(3,4), C2(5), C3;
//    C1.PrintComplex();
//    C2.PrintComplex();
//    cout<<"========================\n";
//
//    cout << "C1 - C2 : ";
//    C3 = C1 - C2;
//    C3.PrintComplex();
//
//    cout << "7 - C2 : ";
//    C3 = 7 - C2;
//    C3.PrintComplex();
//
//    cout << "C2 - 7 : ";
//    C3 = C2 - 7;
//    C3.PrintComplex();
//
//    cout << "C1 -= C2 : ";
//    C1 -= C2;
//    C1.PrintComplex();
//
//    cout << "C2 = --C1 : ";
//    C1.PrintComplex();
//    C2 = --C1;
//    C2.PrintComplex();
//
//    cout << "C2 = C1--";
//    C2 = C1--;
//    cout<<"\nC2 : "; C2.PrintComplex();
//    cout<<"C1 : "; C1.PrintComplex();
//
//
//
//    cout<<"============\n";
//    C1.PrintComplex();
//    C2.PrintComplex();
//    cout<<"=============\n";
//    cout << "C1 == C2 : " << (C1 == C2) << endl;
//    cout << "C1 != C2 : " << (C1 != C2) << endl;
//    cout << "C1 > C2 : " << (C1 > C2) << endl;
//    cout << "C1 >= C2 : " << (C1 >= C2) << endl;
//    cout << "C1 < C2 : " << (C1 < C2) << endl;
//    cout << "C1 <= C2 : " << (C1 <= C2) << endl;
//
//
//    cout << "(int) C1 : " << (int)C1 << endl;
//    cout << "C1['R'] : " << C1['R'] << endl;
//
//    cout<<"--------------------------------------------\n";
    Complex inCompex;
    cin>>inCompex;
    cout<<inCompex;

    return 0;
}
