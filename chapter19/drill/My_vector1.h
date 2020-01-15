#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#endif // MY_VECTOR_H

#include <std_lib_facilities.h>

template <typename T, typename A = allocator<T>>
class My_vector {
    int sz; //размер
    double* elem; //указатель на элементы
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
        , elem { new double[s] }
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

    void resize(int newsize);
    void push_back(double d);
    void reserve(int newalloc);
};

void My_vector::resize(int newsize)
{
}
