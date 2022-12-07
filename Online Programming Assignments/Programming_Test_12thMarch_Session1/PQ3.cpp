    double operator()(){ return sqrt(re * re + im *im); }     // LINE-1

    Complex operator+(Complex& c) {                         // LINE-2

        Complex t;
        t.re = this->re + c.re;
        t.im = this->im + c.im;
        return t;
    }

    friend ostream& operator<<(ostream&, const Complex&);    // LINE-3

};

ostream& operator<<(ostream &output, const Complex &c) { // LINE-4 

int main(){
    double a, b, c;
    cin >> a >> b >> c;
    complex_num c1(a, b);
    complex_num c2 = c;                                     
    complex_num c3 = c1 + c2;
    double d = c3;
    cout << d;
    return 0;
}