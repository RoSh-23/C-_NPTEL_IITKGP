#include <iostream>
using namespace std;

class ComplexNum {
    double _r, _i;
public:
    ComplexNum(double r = 0.0, double i = 0.0) : _r(r), _i(i) { }         // LINE-1

    ComplexNum(const ComplexNum &c) : _r(c._r), _i(c._i) { }   // LINE-2

    ComplexNum operator=(const ComplexNum &c) {                          // LINE-3
        _r = c._r;
        _i = c._i;
        return *this;
    }

    ComplexNum operator*(const ComplexNum &c) {                          // LINE-4

int main(){
    int n, i1, i2, n1, n2, j1, j2;
    cin >> n >> i1 >> n1 >> i2 >> n2 >> j1 >> j2;
    Array ar(n);
    try{
        ar.setEle(i1, n1);
        ar.setEle(i2, n2);
        cout << ar.getEle(j1) << ", " << ar.getEle(j2);
    }catch(int i){
        cout << "error at " << i;
    }
    return 0;
}