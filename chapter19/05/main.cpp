#include <std_lib_facilities.h>

using namespace std;

template <class T>
struct Int {
    T i;
    Int(T n)
        : i { n }
    {
    }
    Int& operator=(const Int& b)
    {
        i = b.i;
    }
    Int& operator+(const Int& b)
    {
        i += b.i;
    }
    Int& operator-(const Int& b)
    {
        i -= b.i;
    }
    Int& operator*(const Int& b)
    {
        i *= b.i;
    }
    Int& operator/(const Int& b)
    {
        i /= b.i;
    }
};

template <class T>
ostream& operator<<(ostream& os, const Int<T>& a)
{
    return os << a.i;
}

template <class T>
istream& operator>>(istream& is, Int<T>& a)
{
    return is >> a.i;
}

int main()
{
    Int a { 10 };
    cout << a << endl;
    Int b { 15 };
    a = b;
    cout << a << endl;
    a = a + b;
    cout << a << endl;
    a = a - b;
    cout << a << endl;
    a = a / b;
    cout << a << endl;
    a = a * b * b;
    cout << a << endl;
    cin >> a;
    cout << a << endl;

    return 0;
}
