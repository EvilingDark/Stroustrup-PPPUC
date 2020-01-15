// глава 18 упр 8.cpp : Этот файл содержит функцию "main". Здесь начинается и
// заканчивается выполнение программы.
//

#include <std_lib_facilities.h>

using namespace std;

void print_char(const char* st)
{
    while (*st) {
        cout << *st;
        ++st;
    }
    cout << endl;
}

int strlen1(const char* st)
{
    int i = 0;
    while (*st) {
        ++st;
        ++i;
    }
    return i;
}

char* cat_dot(const char* s1, const char* s2, const char* dot)
{
    int l_s1 = strlen1(s1);
    int l_s2 = strlen1(s2);
    int l_dot = strlen1(dot);
    int length = l_s1 + l_s2 + l_dot;
    char* cat = new char[length + 1];
    char* p = cat;
    while (*s1) {
        *p = *s1;
        ++p;
        ++s1;
    }
    while (*dot) {
        *p = *dot;
        ++p;
        ++dot;
    }
    while (*s2) {
        *p = *s2;
        ++p;
        ++s2;
    }
    *p = 0;
    return cat;
}

string s_reverse(const string& s)
{
    string st;
    for (int i = s.size() - 1; i >= 0; --i)
        st.push_back(s[i]);
    //cout << st << endl;
    return st;
}

bool is_palindrome(const string& s)
{
    string str = s_reverse(s);
    if (str == s)
        return true;
    return false;
}

char* ch_reverse(const char* ch, int n)
{
    char* ch1 = new char[n + 1];
    char* p = ch1;
    ch1[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        *ch1 = ch[i];
        ++ch1;
    }
    //print_char(p);
    return p;
}

bool is_polindrome_array(const char* s, int n)
{
    char* str = ch_reverse(s, n);
    for (int i = 0; i < n; ++i)
        if (s[i] != str[i])
            return false;
    delete[] str;
    return true;
}

void reverse_pointers(const char*& begin, const char*& end)
{
    int count = 0;
    const char* p = begin;
    while (begin != end) {
        ++begin;
        ++count;
    }
    const char* first = new char[count];
    char* reverse = const_cast<char*>(first);
    while (p != end) {
        *reverse = *end;
        ++reverse;
        --end;
    }
    begin = first;
    end = reverse;
}

bool is_polindrome_pointers(const char* first, const char* last)
{
    const char* begin = first;
    const char* end = last;
    reverse_pointers(begin, end);
    while (first != last) {
        if (*first != *begin)
            return false;
        ++first;
        ++begin;
    }
    return true;
}

int main()
{
    string s { "hooh" };
    cout << s << " is";
    if (!is_palindrome(s))
        cout << " not";
    cout << " a polindrome" << endl
         << endl;
    char ch[] { "hooh" };
    cout << ch << " is";
    if (!is_polindrome_array(ch, 4))
        cout << " not";
    cout << " a polindrome" << endl;
    char ch2[] { "hoyyoh" };
    cout << ch2 << " is";
    if (!is_polindrome_pointers(&ch2[0], &ch2[strlen(ch2) - 1]))
        cout << " not";
    cout << " a polindrome" << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и
//   другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый
//   элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий
//   элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" >
//   "Открыть" > "Проект" и выберите SLN-файл.
