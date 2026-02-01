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
        cout << "Parameterless Constructor\n";
    }

    Complex(float r, float i) {
        this->real = r;
        this->img = i;
        cout << "Two parameters Constructor\n";
    }

    Complex(float val) {
        this->real = val;
        this->img = val;
        cout << "One parameters Constructor\n";
    }



    void setReal(float r)  { this->real = r; }
    void setImg(float i)   { this->img = i; }

    float getReal() const { return this->real; }
    float getImg()  const { return this->img; }

    Complex(Complex &C) {
        this->real = C.real;
        this->img  = C.img;
        cout << "Copy Constructor\n";
    }

    Complex AddComplex(Complex C);
    Complex SubComplex(Complex C);
    void PrintComplex();
    ~Complex() {
        cout << "Destructor for (" << this->real << "," << this->img << "i)\n";
    }
};

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


	Complex C1(3,4), C2(5), C3;
	C3 = C1.AddComplex(C2);

    return 0;
}
