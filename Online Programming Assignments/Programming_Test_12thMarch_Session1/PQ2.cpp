#include<iostream>
using namespace std;

class point{
    int x;
    int y;
    public:
        point() : x(0), y(0){}

        point(int _x, int _y) : x(_x), y(_y){}

        point operator+(int);

        point operator++(int);

        void display(){ cout << x << ", " << y << endl; }
};
int operation(int data1, int data2, int(*functocall)(int, int)) {

    return (*functocall)(data1, data2); // LINE-1

}

int main() {
    int  a, b, c, d;

    cin >> a >> b >> c;

    int (*fp[])(int, int) = { &add, &sub, &multi, &divi }; // LINE-2
int main(){
    int x, y, z;
    cin >> x >> y >> z;
    point p(x, y);
    p = p + z;
    p++;
    p.display();
    return 0;
}