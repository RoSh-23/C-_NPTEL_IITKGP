#include <iostream>
using namespace std;

class Celsius;       // LINE-1    

class Fahrenheit {
    double _temp;
public:
    Fahrenheit(double temp = 0.0) : _temp(temp) { }

    friend Celsius operator+(Celsius&, Fahrenheit&);     // LINE-2

    Celsius operator Celsius()();     // LINE-3
};

class Celsius {
    double _temp;
public:
    Celsius(double temp = 0.0) : _temp(temp) { }
    void show();

    friend Celsius operator+(Celsius&, Fahrenheit&);       // LINE-4

    friend Celsius operator Celsius();       // LINE-5
};

Celsius  Fahrenheit::operator Celsius()() {     // LINE-6

    Celsius c;
    c._temp = (_temp - 32) * ((double)5 / 9);
    return c;
}

void g::disp() { cout << we << endl; }

int main() {
    double i, j;
    cin >> i >> j;
    kg n1(i);
    g n2(j);
    n2 = n2 + n1;
    n2.disp();
    return 0;
}