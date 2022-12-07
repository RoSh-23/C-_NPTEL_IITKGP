/*Program to implement Programming Calculator*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

template<class T>
class numberConversion
{
public:
    short int enteredBase;       // Base of entered number
    short int convertToBase;     // Base of number to which we have to convert entered number
    T enteredNum;                // Entered number : String for Hexadecimal and Int for others
//public:
    numberConversion(short int, short int, T);     // Constructor
    ~numberConversion() {}                         // Destructor

    void decToAny(void);        // Decimal to any number system
    void binOctToDec(void);     // Any number system to Decimal
    void hexaToDec(void);       // Hexadecimal to Decimal
    void octHexToBin(void);     // Octal/Hexadecimal to Binary
    void binToOctHexa(void);    // Binary to Octal/Hexadecimal
    void displayEntNum(void);   // Method to display the entered number
};


int main()
{
    int choice;
    do
    {
        system("cls");
        cout << "\n----------------Programming Calculator----------------------------\n";

        int b1, b2;
        cout << "\nEnter Input Number Base: ";
        cin >> b1;
        cout << "\nEnter Output Number Base: ";
        cin >> b2;

        if(b1 == 16)
        {
            string inp;
            cout << "\nEnter Input Number(use CAPITAL LETTERS): ";
            cin >> inp;
            numberConversion<string> obj(b1, b2, inp);
            obj.displayEntNum();
            obj.hexaToDec();
        }
        else
        {
            long int inp;
            cout << "\nEnter Input Number: ";
            cin >> inp;
            numberConversion<long int> obj(b1, b2, inp);
            obj.displayEntNum();
            if(b1 == 10)
                obj.decToAny();
            else
                obj.binOctToDec();
        }

        cout << "\nDo you want to perform another operation?\n";
        cout << "Press\n 1: for YES\n 2: for NO\n";
        cin >> choice;
    }while(choice == 1);

    return 0;
}

//Constructor
template<class T>
numberConversion<T>::numberConversion(short int b1, short int b2, T inputNum) : enteredBase(b1), convertToBase(b2), enteredNum(inputNum) {}

// Decimal to any number system
template<class T>
void numberConversion<T>::decToAny(void)
{
    const int baseCharRep = 10;
    long int inputNum = enteredNum, rem;
    int i = 0;
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
    cout << "Converted number (base " << convertToBase << "): ";
    for(it = convertedNum.end() - 1; it >= convertedNum.begin(); it--)
        cout << *it;
    cout << endl;
}

template<class T>
void numberConversion<T>::binOctToDec(void)
{
    long int inp = 0;

    vector<int>inputNum;
    vector<int>::iterator it;

    long int convertedNum = 0;
    int i = 0;

    long int temp = enteredNum, rem;
    while(temp != 0)
    {
        rem = temp % 10;
        inputNum.insert(inputNum.begin(), rem);
        temp = temp / 10;
    }

    int power = 0;
    for(it = inputNum.end() - 1; it >= inputNum.begin(); it--)
    {
        convertedNum = convertedNum + (*it) * (pow(enteredBase , power));
        power++;
    }
    cout << "Converted number(base 10): " << convertedNum << endl;
}

template<class T>
void numberConversion<T>::hexaToDec(void)
{
    vector<int>inputNum;
    vector<int>::iterator it;

    long int convertedNum = 0;
    int i = 0;

    for(int j = 0; enteredNum[j] != '\0'; j++)
    {
        if((enteredNum[j] >= 'A') && (enteredNum[j] <= 'F'))
        {
            inputNum.insert(inputNum.begin(), ((int)enteredNum[j] - 55));
        }
        else
        {
            inputNum.insert(inputNum.begin(), ((int)enteredNum[j] - 48));
        }
    }

    int power = 0;
    for(it = inputNum.end() - 1; it >= inputNum.begin(); it--)
    {
        convertedNum = convertedNum + (*it) * (pow(enteredBase , power));
        power++;
    }
    cout << "Converted number(base 10): " << convertedNum << endl;
}

template<class T>
void numberConversion<T>::displayEntNum(void)
{
    cout << "\nEntered Number (base " << enteredBase << "): " << enteredNum << endl;
}
