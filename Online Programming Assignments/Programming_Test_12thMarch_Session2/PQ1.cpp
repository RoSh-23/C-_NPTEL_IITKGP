#include <iostream>
using namespace std;

class GeoTransformation;                                           // LINE-1

class Point { int _x, _y;
public:
    Point(int x = 0, int y = 0) : _x(x), _y(y) { }
    Point(const Point &tp) : _x(tp._x), _y(tp._y) { }              // LINE-2

    friend ostream& operator<<(ostream&, const Point&);    // LINE-3

    friend GeoTransformation;                                       // LINE-4
};

ostream& operator<<(ostream &out, const Point &p) { // LINE-5
        void disp() { cout << r << ", " << i << endl; }
};
int main(){
    int r, i;
    cin >> r >> i;
    ComplexNum obj1(r, i);    
    ComplexNum obj2 = obj1++;
    obj1.disp();
    obj2.disp();

    obj2 = ++obj1;
    obj1.disp();
    obj2.disp();
    return 0;
}