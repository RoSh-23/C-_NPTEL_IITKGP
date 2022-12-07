#include <iostream>
#include <exception>
#include <cstring>
using namespace std;

class IndexOutOfBound : public exception{ // LINE-1

    int _what;
public:
    IndexOutOfBound(int what) : _what(what) {}

    _______________ ;                             // LINE-2

    virtual const char* what() const throw();
};
class Array {
    int *_ptr, _size;
public:
    Array(int size) : _size(size) {
        _ptr = new int[_size];
        for (int i = 0; i < _size; i++)
            _ptr[i] = i + 1;
    }
    _______________ {                           // LINE-3

        if (i >= _size)
            _______________;                     // LINE-4

        return _ptr[i];
    }
};

            cout << acc_no << " : " << name << " : " << balance << endl; 
        }    
};
long Account::sl = 10000;

int main(){
    const Account *ac[3];
    for(int i = 0; i < 3; i++){
        string n;
        double b;
        cin >> n >> b;
        ac[i] = new Account(n, b);
    }
    for(int i = 0; i < 3; i++){
        double cb;
        cin >> cb;
        ac[i]->change(cb);
    }
    for(int i = 0; i < 3; i++){
        ac[i]->print();
    }
    return 0;
}