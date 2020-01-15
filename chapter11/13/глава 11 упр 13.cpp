// глава 11 упр 13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	setlocale(LC_ALL, "Russian");
	string whitelist{ ".;,&-" };
	string iname = "1.txt";
	ifstream ifst(iname);
	if (!ifst) error("Невозможно открыть входной файл", iname);
	string s;
	char ch;
	while (ifst.get(ch))
		s += ch;
	vector<string> sp = wsplit(s, whitelist);
	string oname = "2.txt";
	ofstream ofst(oname);
	if (!ofst) error("Невозможно открыть выходной файл", iname);
	for (int i = sp.size() - 1; i >= 0; --i)
		ofst << sp[i] << ' ';
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
