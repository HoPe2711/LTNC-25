#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;
public:

    Fraction(int _numerator, int _denominator)
    {
        assert(_denominator != 0);
        numerator = _numerator;
        denominator = _denominator;
    }

    void simplify()
    {
        int tempt = __gcd(denominator, numerator);
        numerator /= tempt;
        denominator /= tempt;
    }

    void print()
    {
        if(numerator == denominator) cout << 1;
        else if(numerator == -denominator) cout << -1;
        else if(denominator == 1) cout << numerator;
        else
            cout << numerator << "/" << denominator << endl;
    }

    Fraction operator+(const Fraction& other) const
    {
        assert(denominator != 0 && other.denominator != 0);
        int bcln = denominator * other.denominator;
        int n_num = numerator * (bcln / denominator) + other.numerator * (bcln / other.denominator);

        Fraction sum(n_num, bcln);
        sum.simplify();

        return sum;
    }

    Fraction operator-(const Fraction& other) const
    {
        assert(denominator != 0 && other.denominator != 0);

        int bcln = denominator * other.denominator;
        int n_num = numerator * (bcln / denominator) - other.numerator * (bcln / other.denominator);

        Fraction Minus(n_num, bcln);
        Minus.simplify();

        return Minus;
    }

    Fraction operator*(const Fraction& other) const
    {
        assert(denominator != 0 && other.denominator != 0);

        Fraction multiply(numerator * other.numerator, denominator * other.denominator);
        multiply.simplify();

        return multiply;
    }

    Fraction operator/(const Fraction& other) const
    {
        assert(denominator != 0 && other.denominator != 0);

        Fraction tempt(other.denominator, other.numerator);
        Fraction divide(numerator * tempt.numerator, denominator * tempt.denominator);

        divide.simplify();
        return divide;
    }

    bool operator>(const Fraction& other) const
    {
        int bcln = denominator * other.denominator;
        int n_num = numerator * (bcln / denominator) - other.numerator * (bcln / other.denominator);
        if (n_num>= 0) return true;
        return false;
    }

    bool operator<(const Fraction& other) const
    {
        int bcln = denominator * other.denominator;
        int n_num = numerator * (bcln / denominator) - other.numerator * (bcln / other.denominator);
        if (n_num <= 0) return true;
        return false;
    }
    friend Fraction get_max(Fraction a, Fraction b);
    friend ostream& operator <<(ostream& s, const Fraction& v);
    friend istream& operator >>(istream& s, Fraction& v);
};

Fraction get_max(Fraction a, Fraction b)
{
    Fraction c = a - b;
    if (c.numerator * c.denominator >=0) return a;
    return b;
}

ostream& operator <<(ostream& s, const Fraction& v)
{
    if(v.numerator == v.denominator) s << 1;
        else if(v.numerator == -v.denominator) s << -1;
        else if(v.denominator == 1) s << v.numerator;
        else
            s << v.numerator << "/" << v.denominator;
    return s;
}

istream& operator >>(istream& s, Fraction& v)
{
    s >> v.numerator >> v.denominator;
    assert(v.denominator != 0);
    return s;
}


int main()
{
    Fraction x(2, 3);
    Fraction y(10, 5);
//    cout << (y>x) << endl;
//    Fraction y(10, 0);
    Fraction t = get_max(x,y);
//    Fraction t = min(x,y);
//    Fraction t = max (x,y);
    Fraction z = x + y + t;
//    Fraction z = x - y;
//    Fraction z = x * y;
//    Fraction z = x / y;
//    cout << t << endl;
//   cin >> t;
    t.print();
//    z.print();
    cout << z;
    return 0;
}
