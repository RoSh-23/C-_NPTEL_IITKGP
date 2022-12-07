#include <iostream>
using namespace std;

class Complex
{
    double re, im;
public:
    Complex(double a = 0.0, double b = 0.0) : re(a), im(b) {}
    ~Complex() {}
    void display();
    double real() { return re;}
    double img() {return im;}
    void set_real(double r) {re = r;}
    void set_img(double i) {im = i;}
};

void Complex::display()
{
    cout << re;
    cout << " +j " << im << endl;
}

Complex operator+(Complex &t1, Complex &t2)
{
    Complex sum;
    sum.set_real(t1.real() + t2.real());
    sum.set_img(t1.img() + t2.img());
    return sum;
}

int main()
{
    Complex c1(4.5, 25.25), c2(8.3, 10.25), c3;
    cout << "1st complex No.:";
    c1.display();

    cout << "2nd complex No.:";
    c2.display();

    c3 = c1 + c2;

    cout << "Sum = ";
    c3.display();

    return 0;
}
