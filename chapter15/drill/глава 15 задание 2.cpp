// глава 15 задание 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Window.cpp>
#include <Simple_window.h>
#include <Graph.cpp>
#include <Point.h>
#include <GUI.cpp>
#include <std_lib_facilities.h>

struct Person {
	Person(string first, string second, int a) {
		if (a < 0 || a>150)
			error("Ошибка в возрасте");
		string blacklist{ ":;.,\'\"[]*&^%$#@!" };
		for (auto ch : first)
			for (auto ch1 : blacklist)
				if (ch == ch1)
					error("Имя содержит запрещенные символы");
		for (auto ch : second)
			for (auto ch1 : blacklist)
				if (ch == ch1)
					error("Имя содержит запрещенные символы");
		pf_name = first;
		ps_name = second;
		p_age = a;
	}
	Person() {}
	string first_name() { return pf_name; }
	string second_name() { return ps_name; }
	int age() { return p_age; }
	void set_first_name(string n) { 
		string blacklist{ ":;.,\'\"[]*&^%$#@!" };
		for (auto ch : n)
			for (auto ch1 : blacklist)
				if (ch == ch1)
					error("Имя содержит запрещенные символы");
		pf_name = n; }
	void set_second_name(string n) {
		string blacklist{ ":;.,\'\"[]*&^%$#@!" };
		for (auto ch : n)
			for (auto ch1 : blacklist)
				if (ch == ch1)
					error("Имя содержит запрещенные символы");
		ps_name = n;
	}
	void set_age(int a) { 
		if (a < 0 || a>150)
			error("Ошибка в возрасте");
		p_age = a; }
private:
	string pf_name;
	string ps_name;
	int p_age;
};

ostream& operator<<(ostream& ost, Person& per) {
	return ost << per.first_name() << " " << per.second_name() << " " << per.age() << endl;
}

istream& operator>>(istream& ist, Person& per) {
	string s0;
	string s1;
	int a;
	ist >> s0 >> s1 >> a;
	per.set_first_name(s0);
	per.set_second_name(s1);
	per.set_age(a);
	return ist;
}

int main()
try
{
	using namespace Graph_lib;
	setlocale(LC_ALL, "Russian");
	vector<Person> vper;
	while(true) {
		string first_name;
		string second_name;
		int age;
		cin >> first_name;
		if (first_name == "PRINT") {
			for (Person p : vper)
				cout << p;
			cin.clear();
		}
		else {
			cin >> second_name >> age;
			vper.push_back(Person(first_name,second_name, age));
		}
	}
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
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
