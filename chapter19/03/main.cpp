#include <iostream>
#include <string>

using namespace std;

template <class T, class U>
struct Pair {
    Pair();
    Pair(T Key, U Val)
        : key { Key }
        , val { Val }
    {
    }
    void make_pair(T Key, U Val)
    {
        key = Key;
        val = Val;
    }

    T get_key() { return key; }
    U get_val() { return val; }

private:
    T key;
    U val;
};

template <class T, class U>
ostream& operator<<(ostream& os, Pair<T, U> p)
{
    return os << p.get_key() << " " << p.get_val();
}

int main()
{
    Pair p0("str", 19.5);
    string s { "str0" };
    double d = 20.5;
    Pair p1(s, d);
    cout << p0 << " " << p1;
    //    cout << "Hello World!" << endl;
    return 0;
}
