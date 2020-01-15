#include <std_lib_facilities.h>

using namespace std;

void print(double d2)
{
    double a2 = 0, b2 = 0, c2 = 0;
    double* a3 = &a2;
    double* b3 = &b2;
    double* c3 = &c2;
    double* d3 = &d2;
    cout << &a3 << " " << &b3 << " " << &c3 << " "
         << &d3 << endl
         << endl;
    char* ch3 = new char[2000];
    for (int i = 0; i < 2000; ++i)
        ch3[i] = 'j';
    char* j00 = &ch3[0];
    char* j05 = &ch3[5];
    char* j14 = &ch3[14];
    char* j32 = &ch3[32];
    char* j55 = &ch3[55];
    char* j74 = &ch3[74];
    char* j89 = &ch3[89];
    cout << &j00 << " " << &j05 << " " << &j14 << " " << &j32
         << " " << &j55 << " " << &j74 << " " << &j89 << endl
         << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, x = 0, y = 0, z = 0;
    char ch[] { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'x', 'y', 'z' };
    char* ch2 = new char[1000];
    for (int i = 0; i < 1000; ++i)
        ch2[i] = 'f';
    double* a1 = &a;
    double* d1 = &d;
    double* g1 = &g;
    double* z1 = &z;
    double* b1 = &b;
    double* x1 = &x;
    cout << "Static data:" << &a1 << " " << &d1 << " " << &g1
         << " " << &z1 << " " << &b1 << " " << &x1 << endl
         << endl;
    char* a10 = &ch[0];
    char* a11 = &ch[1];
    char* a12 = &ch[2];
    char* a13 = &ch[3];
    char* a14 = &ch[4];
    char* a15 = &ch[5];
    char* a17 = &ch[7];
    char* a19 = &ch[9];
    cout << &a10 << " " << &a11 << " " << &a12 << " " << &a13 << " "
         << &a14 << " " << &a15 << " " << &a17 << " " << &a19 << endl
         << endl;
    char* s00 = &ch2[0];
    char* s05 = &ch2[5];
    char* s10 = &ch2[10];
    char* s17 = &ch2[17];
    char* s23 = &ch2[23];
    cout << "Free store: " << &s00 << " " << &s05 << " " << &s10
         << " " << &s17 << " " << &s23 << endl
         << endl;
    print(a);
    return 0;
}
