#include <iostream>
using namespace std;

class Stack {
    int *items, top, n;
    public:
        Stack(int);
        void operator+(int);   // Push
        void operator--();     // Pop
        int operator()();      // Peek: return the top element
};
Stack::Stack(int _n) : n(_n) {
    items = new int[_n];
    top = -1;
}
#include <iostream>
#include <string>
using namespace std;

class Customer{
private:
    int _custID;
    string _name;

      string _custCity;   // LINE-1

public:
    Customer(int custID, string name, string custCity) : 
        _custID(custID), _name(name), _custCity(custCity) { }

    Customer(const Customer &_customer ) : // LINE-2

        _custID(_customer._custID * 100), _name(_customer._name), 
        _custCity(_customer._custCity) { }   
 
    void changeCity(string& custCity) { _custCity = custCity; } // LINE-3

    void printCustomer (void) const; // LINE-4
};

class Invoice {
private:
    int _invoiceID;
    const Customer _customer;
    double _payable;
public:
    Invoice(int invoiceID, const Customer customer, double payable) :
        _invoiceID(invoiceID), _customer(customer), _payable(payable){}
    void printInvoice();
};

void Customer::printCustomer(void) const { // LINE-5

int main() {
    Stack s(5);
    int data;
    cin >> data;
    s.operator+(data);
    cin >> data;
    s.operator+(data);
    cin >> data;
    s.operator+(data);

    cout << s() << " ";
    --s;
    cout << s() << " ";
    --s;
    cout << s() << " ";
    return 0;
}