#include <iostream>
#include <vector>
using namespace std;

template<typename T>                           // LINE-1

class MySequence {
    vector<T> _arr;
    const int _len;
public:
    MySequence(int len = 0) : _len(len) {

        _arr.resize(_len);                   // LINE-2

    }
    T& operator[](int i) {               // LINE-3

        if (0 <= i && i < _len)
            return _arr[i];

        throw _len;                   // LINE-4
    }
};
    char *n1, *n2;
    public:
        myType(char* _n1, char* _n2) : n1(strdup(_n1)), n2(strdup(_n2)) { }
        char* sum() {
            char *buf = new char[strlen(n1) + strlen(n2) + 1];
            strcpy(buf, n1);
            strcat(buf, n2);
            return buf;
        }
};
int main() {
    char str1[20];
    char str2[20];
    int n1;
    int n2;
    cin >> str1 >> str2;
    cin >> n1 >> n2;
    myType<char*> obj1(str1, str2);
    cout << obj1.sum() << endl;
    myType<int> obj2(n1, n2);
    cout << obj2.sum() << endl;
    return 0;
}