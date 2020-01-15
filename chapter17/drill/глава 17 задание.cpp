// глава 17 задание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

void print_array10(ostream& os, int* a)
{
	cout << endl;
	for (int i = 0; i < 10; ++i)
		os << a[i] << endl;
}

void print_array(ostream& os, int* a, int n)
{
	cout << endl;
	for (int i = 0; i < n; ++i)
		os << a[i] << endl;
}

void print_vector(const vector<int>& vc)
{
	cout << endl;
	for (auto p : vc)
		cout << p << endl;
}

int main()
{
	int* a = new int[10] { 0,1,2,3,4,5,6,7,8,9 };
	int* b = new int[10] { 100,101,102,103,104,105,106,107,108,109 };
	int* c = new int[11]{ 100,101,102,103,104,105,106,107,108,109,110 };
	int* d = new int[20]{ 100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119 };
	print_array10(cout, a);
	print_array10(cout, b);
	print_array(cout, c, 22);
	print_array(cout, d, 22);
	delete[] a;
	delete[] b;
	delete[] d;
	cout << endl << endl;
	vector<int> b1{ 100,101,102,103,104,105,106,107,108,109 };
	vector<int> c1{ 100,101,102,103,104,105,106,107,108,109,110 };
	vector<int> d1{ 100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119 };
	print_vector(b1);
	print_vector(c1);
	print_vector(d1);
	//////////////////////////////////////
	cout << endl << endl;
	int* i = new int{ 7 };
	int* p1 = i;
	cout << p1 << " " << *p1 << endl;
	int* i2 = new int[7]{ 1,2,4,8,16,32,64 };
	int* p2 = i2;
	cout << p2 << endl;
	print_array(cout, p2, 7);
	int* p3 = p2;
	p2 = p1;
	p2 = p3;
	cout << p1 << " " << p2;
	print_array10(cout, p1);
	print_array10(cout, p2);
	delete[] p1;
	delete[] p2;
	int* i3 = new int[10]{ 1,2,4,8,16,32,64,128,256,512 };
	p1 = i3;
	int* i4 = new int[10]{ 1,2,3,4,5,6,7,8,9,10 };
	p2 = i4;
	print_array10(cout, p1);
	print_array10(cout, p2);
	for (int i = 0; i < 10; ++i)
		p2[i] = p1[i];
	print_array10(cout, p2);
	vector<int> v1{ 1,2,4,8,16,32,64,128,256,512 };
	vector<int> v2{ 1,2,3,4,5,6,7,8,9,10 };
	print_vector(v1);
	print_vector(v2);
	v2 = v1;
	print_vector(v2);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
