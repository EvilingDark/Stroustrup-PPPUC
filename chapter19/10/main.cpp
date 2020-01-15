#include <iostream>
#include <string>

using namespace std;

struct God {
    God() {}
    God(const string& name, const string& country = "", const string& weapon = "")
        : value { name }
        , land { country }
        , gun { weapon }
    {
    }
    God(const God& g) //копирующий конструктор
        : value { g.value }
        , land { g.land }
        , gun { g.gun }
    {
    }
    God& operator=(const God& g)
    { //копирующее присваивание
        value = g.value;
        land = g.land;
        gun = g.gun;
        return *this;
    }
    ~God() {}
    string value;
    string land;
    string gun;
};

template <class T>
struct unique_ptr {
    unique_ptr(T* p)
    {
        ptr = p;
    }
    ~unique_ptr()
    {
        delete ptr;
    }
    T& operator*()
    {
        return *ptr;
    }
    T* operator->()
    {
        return ptr;
    }
    void release()
    {
        ptr = nullptr;
    }

private:
    T* ptr;
};

int main()
{
    God thor { "Thor" };
    int* a = new int { 5 };
    unique_ptr<int> p(a);
    unique_ptr<int> p1(new int { 10 });
    cout << *p << " " << *p1 << endl;
    unique_ptr<God> p2(new God { "Freiy" });
    cout << p2->value << endl;
    p2->value = "Thor";
    cout << p2->value;
    p2.release();
    return 0;
}
