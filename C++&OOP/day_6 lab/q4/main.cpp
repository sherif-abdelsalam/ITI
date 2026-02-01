#include <iostream>
using namespace std;

struct Complex
{
    private:
        float real;
        float img;

    public:
        void setReal(float r) { real = r; }
        void setImg(float i)  { img = i; }

        float getReal() { return real; }
        float getImg()  { return img; }

        Complex Add(Complex C)
        {
            Complex result;
            result.real = real + C.real;
            result.img  = img  + C.img;
            return result;
        }
};

Complex Add(Complex C1, Complex C2)
{
    Complex result;
    result.setReal(C1.getReal() + C2.getReal());
    result.setImg(C1.getImg() + C2.getImg());
    return result;
}

Complex Subtract(Complex C1, Complex C2)
{
    Complex result;
    result.setReal(C1.getReal() - C2.getReal());
    result.setImg(C1.getImg() - C2.getImg());
    return result;
}

void print(Complex C)
{
    float r = C.getReal();
    float i = C.getImg();

    if (r == 0 && i == 0)
        cout << "0";
    else if (i == 0)
        cout << r;
    else if (r == 0)
        cout << i << "i";
    else if (i > 0)
        cout << r << "+" << i << "i";
    else
        cout << r << i << "i";
    cout << endl;
}

int main()
{

//    real = 5, img = 3  // C1 = 5+3i
//    real = 5, img = -3  // C1 = 5 + -3i   ==> C1 = 5-3i
//    real = 5, img = 0  // C1 = 5 + 0i   ==> C1 = 5
//    real = 0, img = 3  // C1 = 0 + 3i   ==> C1 = 3i
//    real = 0, img = 0  // C1 = 0 + 0i   ==> C1 = 0

    Complex C1, C2, C3, C4, C5;
    Complex CSADD, CMADD, CSUB;

    C1.setReal(5);
    C1.setImg(3);
    cout << "C1 = "; print(C1);


    C2.setReal(5);
    C2.setImg(-3);
    cout << "C2 = "; print(C2);

    C3.setReal(5);
    C3.setImg(0);
    cout << "C3 = "; print(C3);

    C4.setReal(0);
    C4.setImg(3);
    cout << "C4 = "; print(C4);

    C5.setReal(0);
    C5.setImg(0);
    cout << "C5 = "; print(C5);


    cout << "Standalone Add(C1+C2): ";
    CSADD = Add(C1, C2);
    print(CSADD);

    cout << "Member Add(C1+C2): ";
    CMADD = C1.Add(C2);
    print(CMADD);

    cout << "Subtract(C4,C5): ";
    CSUB = Subtract(C4, C5);
    print(CSUB);

    return 0;
}
