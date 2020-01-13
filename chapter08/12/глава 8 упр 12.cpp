// глава 8 упр 12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// программа записывает имена, сортирует и печатает по лексикографии, сортирует и печатает по длине

#include <Header.h>

void print_lsort(vector<string>& name);

void print(const vector<string>& vs)		//печатает вектор
{
	cout << '\n';
	for (int i = 0; i < vs.size(); ++i)
		cout << i + 1 << " элемент " << vs[i] << "\n";
	cout << '\n';
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

vector<int> lenght_vs(const vector<string>& name)		//возвращает вектор длин строк
{
	vector<int> lenght;
	for (int i = 0; i < name.size(); ++i)
		lenght.push_back(name[i].length());
	return lenght;
}

void print_nsort(const vector<string>& name)		//лексикографически сортирует
{
	vector<string> s_name = name;
	sort(s_name.begin(), s_name.end());
	cout << "Лексикографически первая строка: " << s_name[0] << '\n'
		<< "Лексикографически последняя строка: " << s_name[s_name.size() - 1] << '\n';
	print_lsort(s_name);
	return;
}

void print_lsort(vector<string>& name)		//сортирует по длине строки
{
	vector<string> s_name;
	vector<int> s_lenght = lenght_vs(name);
	sort(s_lenght.begin(), s_lenght.end());
	for (int i = 0; i < s_lenght.size(); ++i)
		for (int j = 0; j < name.size(); ++j)
			if (s_lenght[i] == name[j].length())
			{
				s_name.push_back(name[j]);
				name.erase(name.begin() + j);
				j = name.size();
			}
	cout << "Самое короткое слово: " << s_name[0] << " длина " << s_lenght[0] << " символов.\n"
		<< "Самое длинное слово: " << s_name[s_name.size() - 1] << " длина " << s_lenght[s_lenght.size() - 1] << " символов.\n";
	return;
}

int main()
try
{
	setlocale(LC_ALL, "Russian");
	vector<string> name;
	enter_names(name);
	vector<int> lenght = lenght_vs(name);
	cout << '\n';
	for (int i = 0; i < name.size(); ++i)
		cout << name[i] << " длина " << lenght[i] << " символов.\n";
	cout << '\n';
	print_nsort(name);
	return 0;
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
