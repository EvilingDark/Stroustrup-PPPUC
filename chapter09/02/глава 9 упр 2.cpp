// глава 9 упр 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

class Name_pairs {
public:
	void read_names();
	void read_ages();
	void print();
	void sort();

private:
	vector<string> name;
	vector<double> age;
};

void Name_pairs::read_names()
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

void Name_pairs::read_ages()
{
	if (name.size() == 0)
		error("Список не содержит имен");
	cout << "Введите возраст для соответствующего имени.\n";
	for (int i = 0; i < name.size(); ++i)
	{
		cout << name[i] << " ";
		double num = 0;
		cin >> num;
		age.push_back(num);
	}
	return;
}

void Name_pairs::sort()		//сортировка списка по имени
{
	vector<string> s_name = name;
	vector<double> s_age;
	std::sort(s_name.begin(), s_name.end());
	for (int i = 0; i < s_name.size(); ++i)
		for (int j = 0; j < name.size(); ++j)
			if (s_name[i] == name[j])
				s_age.push_back(age[j]);
	name = s_name;
	age = s_age;
	return;
}

void Name_pairs::print()		//печатает вектор
{
	cout << '\n';
	for (int i = 0; i < name.size(); ++i)
		cout << i + 1 << " элемент " << name[i] << " " << age[i] << "\n";
	cout << '\n';
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Name_pairs scroll;
	scroll.read_names();
	scroll.read_ages();
	scroll.print();
	scroll.sort();
	scroll.print();
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
