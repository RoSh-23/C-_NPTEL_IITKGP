#include <iostream>
using namespace std;

class Complex
{
    double *re, *im;
public:
    Complex(double r = 0.0, double i = 0.0) : re(new double(r)), im(new double(i)) {}
    ~Complex() {}
    friend Complex operator+(const Complex&, const Complex&);
    void display(void)
    {
        cout << *re << " +i " << *im << endl;
    }
};

Complex operator+(const Complex &c1, const Complex &c2)
{
    Complex sum;

    *(sum.re) = *(c1.re) + *(c2.re);
    *(sum.im) = *(c1.im) + *(c2.im);

    return sum;
}

int main()
{
    Complex com1(2.3, 4.5), com2(2.4, 5.6), com3;

    com1.display();
    com2.display();

    com3 = com1 + com2;

    com3.display();

    return 0;
}
