// глава 8 упр 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

void print(const vector<int>& vs)		//печатает вектор
{
	cout << '\n';
	for (int i = 0; i < vs.size(); ++i)
		cout << i + 1 << " элемент " << vs[i] << "\n";
	cout << '\n';
}

void fibonacci(int x, int y, vector<int>& fib, int n)		//добавляет в вектор последовательность фибоначи, x - первый элемент, y - второй, n - количество элементов
{
	fib.push_back(x);
	fib.push_back(y);
	for (int i = 0; n > fib.size(); ++i)
	{
		int temp = fib[i] + fib[i + 1];
		fib.push_back(temp);
	}
	print(fib);
}

void v_reverce_copy(const vector<int>& first_vec)		//создает копию вектора в обратном порядке
{
	vector<int> second_vec;
	for (int i = first_vec.size() - 1; i >= 0; --i)
	{
		second_vec.push_back(first_vec[i]);
	}
	print(second_vec);
}

void v_reverce(vector<int>& vec)		//изменяет порядок элементов на противоположный
{
	
	int i = vec.size() / 2 - 1;
	int count = i + 1;
	if (vec.size() % 2 == 1) 
		++count;
	for (; i >= 0; --i)
	{
		swap(vec[i], vec[count]);
		++count;
	}
	print(vec);
}

int main()
try
{
	setlocale(LC_ALL, "Russian");
	vector<int> v;
	fibonacci(1, 2, v, 12);
	v_reverce_copy(v);
	v_reverce(v);
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
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
