// глава 8 упр 9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

void print(const vector<int>& vs)
{
	cout << '\n';
	for (int i = 0; i < vs.size(); ++i)
		cout << i + 1 << " элемент " << vs[i] << "\n";
	cout << '\n';
}

void fibonacci(int x, int y, vector<int>& fib, int n)
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

int maxv(const vector<int>& vs)
{
	vector<int> st = vs;
	sort(st.begin(), st.end());
	return st[st.size() - 1];
}

void min_max_med(const vector<int>& vs, int& min, int& max, int& med, int& average)
{
	vector<int> st = vs;
	sort(st.begin(), st.end());
	print(st);
	max = st[st.size() - 1];
	min = st[0];
	long long int sum = 0;
	for (int i = 0; i < st.size(); ++i)
		sum += st[i];
	average = sum / st.size();
	if (st.size() % 2 == 1)
		med = st[st.size() / 2];
	else med = (st[st.size() / 2 - 1] + st[st.size() / 2]) / 2;
	return;
}

int main()
try
{
	setlocale(LC_ALL, "Russian");
	vector<int> v;
	fibonacci(1, 2, v, 60);
	int min = 0, max = 0, med = 0, average = 0;
	min_max_med(v, min, max, med, average);
	cout << "Минимум: " << min << "\nМаксимум: " << max <<
		"\nСреднее: " << average << "\nМедиана: " << med << '\n';
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
