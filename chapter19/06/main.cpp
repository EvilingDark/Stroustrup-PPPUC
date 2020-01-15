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
    Int& operator%(const Int& b)
    {
        i %= b.i;
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

template <class T, class U>
Int<T> sum(const Int<T>& a, const Int<U>& b)
{
    return a.i + T(b.i);
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
    Int d0 { 12.567 };
    Int d1 { 5 };
    Int d2 = sum(d0, d1);

    cout << d2 << endl;

    return 0;
}
