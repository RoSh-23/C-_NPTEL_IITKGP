/*Program to implement Programming Calculator*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

template<class T>
class numberConversion
{
private:
    short int enteredBase;       // Base of entered number
    short int convertToBase;     // Base of number to which we have to convert entered number
    T enteredNum;                   // Entered number : String for Hexadecimal and Int for others
public:
    numberConversion(short int, short int, T);     // Constructor
    ~numberConversion() {}                          // Destructor

    void decToAny(void);        // Decimal to any number system
    void anyToDec(void);        // Any number system to Decimal
    void octHexToBin(void);     // Octal/Hexadecimal to Binary
    void binToOctHexa(void);    // Binary to Octal/Hexadecimal
};

//Constructor
template<class T>
numberConversion<T>::numberConversion(short int b1, short int b2, T inputNum) : enteredBase(b1), convertToBase(b2), enteredNum(inputNum) {}

// Decimal to any number system
template<class T>
void numberConversion<T>::decToAny(void)
{
    const int baseCharRep = 10;
    int inputNum = enteredNum, rem, i = 0;
    vector<char> convertedNum;      // Vector to hold the converted number
    vector<char>::iterator it;      // Iterator it of char vector type

    while(inputNum != 0)
    {
        rem = inputNum % convertToBase;
        if(rem > baseCharRep)
        {
            char hexa[] = {'A', 'B', 'C', 'D', 'E', 'F'};
            for(int j = 0; j < 6; j++)
            {
                if(rem + 55 == hexa[j])
                {
                    convertedNum.insert(convertedNum.begin() + i, hexa[j]);
                    inputNum = inputNum / convertToBase;
                    i++;
                }
            }
        }
        else
        {
            convertedNum.insert(convertedNum.begin() + i, rem + 48);
            inputNum = inputNum / convertToBase;
            i++;
        }
    }
    cout << "Converted Number in Base " << convertToBase << endl;
    for(it = convertedNum.end() - 1; it >= convertedNum.begin(); it--)
        cout << *it;
    cout << endl;
}

template<class T>
void numberConversion<T>::anyToDec(void)
{
    int inp = 0;

    vector<int>inputNum;
    vector<int>::iterator it;

    int convertedNum = 0, i = 0;

    /*if(enteredBase > 10)
    {
        for(int j = 0; j != '\0'; j++)
        {
            if(enteredNum[j] >= 65 && enteredNum[j] <= 70)
            {
                inputNum.insert(inputNum.begin() + i, enteredNum[j] - 55);
                inp++;
            }
            else
            {
                inputNum.insert(inputNum.begin() + i, enteredNum[j] - 48);
                inp++;
            }
        }
    }
    else*/
    {
        int temp = enteredNum, rem;
        while(temp != 0)
        {
            rem = temp % 10;
            inputNum.insert(inputNum.begin() + i, rem);
            temp = temp / 10;
        }
    }
    int power = 0;
    for(it = inputNum.end() - 1; it >= inputNum.begin(); it--)
    {
        convertedNum = convertedNum + (*it) * (pow(enteredBase , power));
        power++;
    }

    cout << "The converted number in base 10 is:\n";
    cout << convertedNum << endl;
}


int main()
{
    numberConversion<int> n1(10, 2, 4);
    n1.decToAny();
    numberConversion<int> n2(8, 10, 456);
    n2.anyToDec();

    return 0;
}
