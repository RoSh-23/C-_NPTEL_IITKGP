#include<iostream>
using namespace std;
class Character{
    char c;
public:
    Character(char _c) : c(_c) {}   
                  
    void show() {  cout << c << " ";  }

};

class Double{
    double d;
public:
    Double(double _d) : d(_d) {}
class Volume :  public ShapeAttribute {                    // LINE-1
public:
    Volume(double s) : ShapeAttribute(s) { }
    double getVal() {
        return _s * _s * _s;
    }
};

class Area :  public ShapeAttribute {                     // LINE-2   
public:
    Area(double s) : ShapeAttribute(s) { }
    double getVal(){
        return 6 * _s * _s;
    }
};
class Cube : public Volume, public Area  {                     // LINE-3
public:
    Cube(double s) : Volume(s), Area(s){}

    double getArea() { return Area::getVal(); }   // LINE-4

    double getVolume() { return Volume::getVal(); } // LINE-5
};
int main(){
    double d;
    char c;
    cin >> d >> c;
    Double fo(d);
    print(fo);
    print(c);
    return 0;
}