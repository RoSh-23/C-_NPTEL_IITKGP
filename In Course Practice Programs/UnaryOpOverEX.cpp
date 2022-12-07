#include <iostream>
using namespace std;

class MyClass
{
    int data;
public:
    MyClass(int d) : data(d) { }
    MyClass& operator++()  // Pre-increment:
    {                      // Operate and return the operated object
        ++data;
        return *this;
    }
    MyClass operator++(int)  // Post-increment
    {                        // Return the(copy of) object; operate the object
        MyClass t(data);
        ++data;
        return t;
    }
    void disp()
    {
        cout << "Data = " << data << endl;
    }
};

int main()
{
    MyClass obj1(8);
    obj1.disp();

    MyClass obj2 = obj1++;
    obj2.disp();
    obj1.disp();

    obj2 = ++obj1;
    obj2.disp();
    obj1.disp();

    return 0;
}
