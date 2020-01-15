#include <std_lib_facilities.h>

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
struct Link {
    struct Node {
        T item;
        Node *next, *prev;
    };

private:
    Node* box;
    int length;

public:
    Link()
        : box { nullptr }
        , length { 0 }
    {
    }
    Link(T val)
        : length { 1 }
    {
        box = new Node;
        box->item = val;
        box->prev = nullptr;
        box->next = nullptr;
    }
    T& operator[](int n)
    {
        if (n < 0 || n > length)
            throw "out_of_range";
        Node* p = box;
        for (int i = 0; i < n; ++i)
            p = p->next;
        return p->item;
    }
    void push_back(T val)
    {
        Node* p = box;
        while (p->next != nullptr)
            p = p->next;
        Node* back_box = new Node;
        back_box->item = val;
        back_box->prev = p;
        p->next = back_box;
        ++length;
    }
    void push_front(T val)
    {
        Node* p = box;
        Node* front_box = new Node;
        front_box->item = val;
        front_box->prev = nullptr;
        front_box->next = p;
        p->prev = front_box;
        box = front_box;
        ++length;
    }
    void erase(int n)
    {
        if (n < 0 || n > length)
            throw "out_of_range";
        Node* p = box;
        for (int i = 0; i < n; ++i)
            p = p->next;
        Node* box_to_del = p;
        if (box_to_del->prev != nullptr) {
            p = box_to_del->prev;
            p->next = box_to_del->next;
        }
        if (box_to_del->next != nullptr) {
            p = box_to_del->next;
            p->prev = box_to_del->prev;
        }
        delete box_to_del;
        --length;
    }
    T operator=(T val)
    {
        box->item = val;
    }
    int size() const
    {
        return length;
    }
};

int main()
{
    //    int a { 10 };
    //    cout << a;
    God thor("Thor");
    God freiy("Freiy");
    Link<God> gods(thor);
    gods.push_back(freiy);
    gods.push_back(thor);
    cout << gods[0].value
         << " " << gods[1].value << " " << gods[2].value << endl;
    gods[1] = thor;
    cout << gods[0].value
         << " " << gods[1].value << " " << gods[2].value << endl;
    gods[1] = freiy;
    cout << gods[0].value
         << " " << gods[1].value << " " << gods[2].value << endl;
    gods.erase(1);
    cout << gods[0].value
         << " " << gods[1].value << endl;

    return 0;
}
