// глава 8 упр 11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

void print(vector<string>& st)
{
	for (int i = 0; i < st.size(); ++i)
		cout << i + 1 << " элемент " << st[i] << "\n";
}

void print_until_s(vector<string> v, string quit)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == quit) return;
		cout << v[i] << '\n';
	}
}

void print_until_ss(vector<string> v, string quit)
{
	int count = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == quit)
		{
			++count;
				if (count == 2)
					return;
		}
		cout << v[i] << '\n';
	}
}

void enter_names(vector<string>& name)		//ввод имен
{
	cout << "Введите имя для записи в список.\n" << "Введите End для окончания ввода.\n";
	while (cin)
	{
		string s;
		cin >> s;
		if (s == "End")
			return;
		name.push_back(s);
	}
	return;
}

int main()
try
{
	setlocale(LC_ALL, "Russian");
	vector<string> v;
	string quit = "end";
	enter_names(v);
	cout << '\n';
	print_until_s(v, quit);
	cout << '\n';
	print_until_ss(v, quit);
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
