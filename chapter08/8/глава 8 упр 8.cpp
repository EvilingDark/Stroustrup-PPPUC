// глава 8 упр 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// программа для вычисления суммы хранящихся на складе материалов

#include <Header.h>

void print(const vector<string>& name, const vector<double>& price, const vector<double>& weight)		//печатает вектор
{
	cout << '\n';
	for (int i = 0; i < name.size(); ++i)
		cout << name[i] << " цена за 1 кг: " << price[i] << " осталось кг: " << weight[i] << " цена остатка: " << price[i]*weight[i] << "\n";
	cout << '\n';
}

void enter_names(vector<string>& name)		//ввод имен
{
	cout << "Введите наименование товара.\n" << "Введите End для окончания ввода.\n";
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

void enter_price(vector<string>& name, vector<double>& price)		//ввод возраста для соответствующего имени
{
	cout << "Введите цену товара за 1кг.\n";
	for (int i = 0; i < name.size(); ++i)
	{
		cout << name[i] << " ";
		double num = 0;
		cin >> num;
		price.push_back(num);
	}
	return;
}

void enter_weight(vector<string>& name, vector<double>& weight)
{
	cout << "Введите массу товара в кг оставшуюся на складе.\n";
	for (int i = 0; i < name.size(); ++i)
	{
		cout << name[i] << " ";
		double num = 0;
		cin >> num;
		weight.push_back(num);
	}
	return;
}

void print_sort(const vector<string>& name, const vector<int>& age)		//печать сортированного списка по имени
{
	vector<string> s_name = name;
	vector<int> s_age;
	sort(s_name.begin(), s_name.end());
	for (int i = 0; i < s_name.size(); ++i)
		for (int j = 0; j < name.size(); ++j)
			if (s_name[i] == name[j])
				s_age.push_back(age[j]);
	for (int i = 0; i < s_name.size(); ++i)
		cout << s_name[i] << " " << s_age[i] << "\n";
	return;
}

int main()
try
{
	setlocale(LC_ALL, "Russian");
	vector<string> name;
	vector<double> price;
	vector<double> weight;
	enter_names(name);
	enter_price(name, price);
	enter_weight(name, weight);
	print(name, price, weight);
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
