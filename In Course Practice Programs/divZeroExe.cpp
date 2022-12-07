#include <iostream>
#include <exception>
using namespace std;
// declare a user-defined exception
class DivideByZeroException : public exception { // LINE-1
public:
virtual const char* what() const throw();
};
void divide(int i, int j) {
try {
if (j == 0)
// throw the exception object
{
DivideByZeroException e2;
throw e2 ; // LINE-2
}
else if (i == 0)
{
 int er = 0;
throw er;
} // LINE-3

else
cout << (double)i / j;
}
catch (int& e) {
cout << "result is always: " << e;
}
catch (DivideByZeroException e) {
cout << e.what() << endl;
}
}
const char* DivideByZeroException::what() const throw() {
return "cannot divide by 0";
}
int main() {
int i, j;
cin >> i >> j;
divide(i, j);
return 0;
}
