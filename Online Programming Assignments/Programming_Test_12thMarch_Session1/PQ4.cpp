#include<iostream>
using namespace std;

class WaterHabitat{
    string name;
    int amt;
    public:
        WaterHabitat(string _name, int _amt) : name(_name), amt(_amt){}
        virtual void eat(){ cout << name << " eats " << amt << " kg in water" 
                                    << endl; }
};

class LandHabitat{
    string name;
    int amt;
    public:
        LandHabitat(string _name, int _amt) : name(_name), amt(_amt){}
        virtual void eat(){ cout << name << " eats " << amt << " kg on land" 
                                    << endl; }
};
#include <iostream>
#include <string>
using namespace std;

class loan_manager;    // LINE-1

class customer {
    int _custID;
    string _custName;
    int _cibilScore;
public:
    customer(int custID, string custName, int cibilScore) : _custID(custID),
        _custName(custName), _cibilScore(cibilScore){}
    void changeScore(int change) const {    // LINE-2

         const_cast<customer*>(this)->_cibilScore += change;    // LINE-3

    }
    friend loan_manager;    // LINE-4
};
int main(){
    string s;
    int a, b;
    cin >> s;
    cin >> a >> b;

    Amphibians ani(s, a, b);
    ani.eat();
    return 0;
}