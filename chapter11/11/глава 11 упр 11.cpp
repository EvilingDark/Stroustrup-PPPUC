// глава 11 упр 11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

vector<string> split(const string& s)
{
	vector<string> spl;
	string sp;
	istringstream ist(s);
	while (ist >> sp)
		spl.push_back(sp);
	return spl;
}

vector<string> wsplit(const string& s, const string& w)
{
	string st = s;
	for (char& ch : st)
		for (char chw : w)
			if (ch == chw)
				ch = ' ';
	vector<string> spl;
	string sp;
	istringstream ist(st);
	while (ist >> sp)
		spl.push_back(sp);
	return spl;
}

int main()
{
	string s = "The car was introduced in two high-performance versions, the 670 horsepower Taycan Turbo and the 751 horsepower Taycan Turbo S.";
	string whitelist{ ".;,&-'" };
	vector<string> sp = split(s);
	for (string st : sp)
		cout << st << endl;
	cout << endl;
	sp = wsplit(s, whitelist);
	for (string st : sp)
		cout << st << endl;
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
