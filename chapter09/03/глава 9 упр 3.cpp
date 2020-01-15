// глава 9 упр 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

class Name_pairs {
public:
	void read_names();
	void read_ages();
	void sort();
	int size() const { return names.size(); }
	string name(int i) const { return names[i]; }
	double age(int i) const { return ages[i]; }
private:
	vector<string> names;
	vector<double> ages;
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
		names.push_back(s);
	}
	return;
}

void Name_pairs::read_ages()
{
	if (names.size() == 0)
		error("Список не содержит имен");
	cout << "Введите возраст для соответствующего имени.\n";
	for (int i = 0; i < names.size(); ++i)
	{
		cout << names[i] << " ";
		double num = 0;
		cin >> num;
		ages.push_back(num);
	}
	return;
}

void Name_pairs::sort()		//сортировка списка по имени
{
	vector<string> s_name = names;
	vector<double> s_age;
	std::sort(s_name.begin(), s_name.end());
	for (int i = 0; i < s_name.size(); ++i)
		for (int j = 0; j < names.size(); ++j)
			if (s_name[i] == names[j])
				s_age.push_back(ages[j]);
	names = s_name;
	ages = s_age;
	return;
}

ostream& operator<<(ostream& os, const Name_pairs& np)		//печатает вектор
{
	os << '\n';
	for (int i = 0; i < np.size(); ++i)
		os << i + 1 << " элемент " << np.name(i) << " " << np.age(i) << "\n";
	return os << '\n';
}

bool operator==(const Name_pairs& a, const Name_pairs& b)
{
	int count = 0;
	if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); ++i)
		{
			if (a.name(i) == b.name(i) || a.age(i) == b.age(i))
				++count;
		}
	}
	if (count == a.size())
		return true;
	return false;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
	return !(a == b);
}



int main()
{
	setlocale(LC_ALL, "Russian");
	Name_pairs scroll, scroll_2;
	scroll.read_names();
	scroll.read_ages();
	cout << scroll;
	scroll.sort();
	cout << scroll;
	scroll_2.read_names();
	scroll_2.read_ages();
	int i = scroll == scroll_2;
	int j = scroll != scroll_2;
	cout << i << " " << j << endl;
	scroll_2.sort();
	i = scroll == scroll_2;
	j = scroll != scroll_2;
	cout << i << " " << j << endl;
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
