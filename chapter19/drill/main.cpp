#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
struct S {
    S(T v)
        : val { v }
    {
    }
    T& get();
    const T& get() const;
    void set(T v);
    S<T>& operator=(const T& a);
    void read_val();
    //ostream& S<std::vector<T>>::operator<<(const S<std::vector<T>>& v);
    //istream& S<std::vector<T>>::operator>>(const S<std::vector<T>>& v);

private:
    T val;
};

template <typename T>
T& S<T>::get()
{
    return val;
}

template <typename T>
const T& S<T>::get() const
{
    return val;
}

template <typename T>
void S<T>::set(T v)
{
    val = v;
}

template <typename T>
S<T>& S<T>::operator=(const T& a)
{
    val = a;
    return *this;
}

template <typename T>
void read_val(T& v)
{
    cin >> v;
}

template <typename T>
void S<T>::read_val()
{
    cin >> val;
}

/*template <typename T>
ostream& S<std::vector<T>>::operator<<(const S<std::vector<T>>& v)
{
    for (int i = 0; i < v.val.size(); ++i)
        ostream << v.val[i] << " ";
}

template <typename T>
istream& S<std::vector<T>>::operator>>(const S<std::vector<T>>& v)
{
    T num;
    while (istream) {
        istream >> num;
        v.val.push_back(num);
    }
}*/

template <typename T>
ostream& operator<<(ostream& os, const S<vector<T>>& v)
{
    for (int i = 0; i < v.get().size(); ++i)
        os << v.get()[i] << " ";
    return os;
}

template <typename T>
istream& operator>>(istream& is, S<vector<T>>& v)
{
    T num;
    while (is) {
        is >> num;
        v.get().push_back(num);
    }
    return is;
}

int main()
{
    S<int> int0(10);
    S<char> char0('c');
    S<double> double0(10.5);
    S<string> str0("str");
    int0.set(12.5);
    int0 = 14;
    S<vector<int>> vec0 { vector<int>() };
    cin >> vec0;
    cout << vec0;
    //string st;
    //read_val(st);
    //cout << st << endl;
    //double d;
    //read_val(d);
    //cout << d << endl;
    int0.read_val();
    char0.read_val();
    double0.read_val();
    str0.read_val();
    S<vector<int>> vec(vector<int> { 10, 20, 30 });
    cout << int0.get() << " " << char0.get() << " " << double0.get() << " "
         << endl
         << str0.get() << " " << vec.get()[0] << " " << vec.get()[1] << " "
         << vec.get()[2] << endl;
    return 0;
}
