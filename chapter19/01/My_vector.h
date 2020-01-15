#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <std_lib_facilities.h>

namespace My_space {

template <typename T, typename A>
struct vector_base {
    A alloc;
    T* elem;
    int sz;
    int space;

    vector_base(const A& a, int n)
        : alloc { a }
        , elem { a.allocate(n) }
        , sz { n }
        , space { n }
    {
    }
    ~vector_base() { alloc.deallocate(elem, space); }
};

template <typename T, typename A = allocator<T>>
class My_vector {
    A alloc; //работает с памятью, выделяемой для элементов
    int sz; //размер
    T* elem; //указатель на элементы
    int space; //количество элементов + свободных слотов
public:
    My_vector()
        : sz { 0 }
        , elem { nullptr }
        , space { 0 }
    {
    }
    explicit My_vector(int s)
        : sz { s }
        , elem { new T[s]() }
        , space { s }
    {
        for (int i = 0; i < sz; ++i)
            elem[i] = 0;
    }
    //копирующий конструктор и присваивание
    My_vector(const My_vector*);
    My_vector& operator=(const My_vector&);

    //перемещающий конструктор и присваивание
    My_vector(const My_vector&&);
    My_vector& operator=(const My_vector&&);

    ~My_vector() { delete[] elem; } //деструктор

    //доступ к элементам с проверкой диапозона
    T& at(int n);
    const T& at(int n) const;

    //доступ к элементам без проверки
    T& operator[](int n);
    const T& operator[](int n) const;

    int size() const { return sz; }
    int capacity() const { return space; }

    void resize(int newsize, T num = T());
    void push_back(T d);
    void reserve(int newalloc);
};

template <typename T, typename A>
void My_vector<T, A>::reserve(int newalloc)
{
    if (newalloc <= space)
        return;
    T* p = alloc.allocate(newalloc); //выделение новой памяти
    for (int i = 0; i < sz; ++i)
        alloc.construct(&p[i], elem[i]); //копирование
    for (int i = 0; i < sz; ++i)
        alloc.destroy(&elem[i]); //уничтожение
    alloc.deallocate(elem, space); //освобождаем старую память
    elem = p;
    space = newalloc;
}

template <typename T, typename A>
void My_vector<T, A>::resize(int newsize, T num = T())
{
    reserve(newsize);
    if (newsize > 0) {
        for (int i = sz; i < newsize; ++i)
            alloc.construct(&elem[i], num);
        for (int i = newsize; i < sz; ++i)
            alloc.destroy(&elem[i]);
        sz = newsize;
    }
    if (newsize == 0) {
        for (int i = newsize; i < sz; ++i)
            alloc.destroy(&elem[i]);
        sz = newsize;
    }
}

template <typename T, typename A>
void My_vector<T, A>::push_back(const T val)
{
    if (space == 0)
        reserve(8);
    else if (sz == space)
        reserve(2 * space);
    alloc.construct(&elem[sz], val);
    ++sz;
}

template <typename T, typename A>
My_vector<T, A>& My_vector<T, A>::operator=(const My_vector<T, A>& a)
{
    if (this == &a)
        return *this;

    if (a.sz <= space) {
        for (int i = 0; i < a.sz; ++i)
            elem[i] = a.elem[i];
        sz = a.sz;
        return *this;
    }

    double* p = new double[a.sz];
    for (int i = 0; i < a.sz; ++i)
        p[i] = a.elem[i];
    delete[] elem;
    space = sz = a.sz;
    elem = p;
    return *this;
}

template <typename T, typename A>
T& My_vector<T, A>::operator[](int n)
{
    return elem[n];
}

template <typename T, typename A>
T& My_vector<T, A>::at(int n)
{
    if (n >= 0 && n < sz)
        throw Range_error(n);
    return elem[n];
}

}

#endif // MY_VECTOR_H
