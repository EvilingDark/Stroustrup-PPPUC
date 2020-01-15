﻿// глава 11 упр 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

void fread_to_vector(vector<string>& read, string whitelist, string iname)
{
	ifstream ifst{ iname };
	if (!ifst)
		error("Невозможно открыть входной файл", iname);
	string s;
	while (getline(ifst, s))
	{
		for (int i=0;i<s.length();++i)
			for (char chw : whitelist)
			{
				if (s[i] == chw)
				{
					s.erase(s.begin() + i);
				}
				for (char chw : whitelist)
					if (s[i] == chw)
						s.erase(s.begin() + i);
			}
		istringstream ist(s);
		string word, outs;
		while (ist >> word) {
			outs = outs + ' ' + word;
		}
		read.push_back(outs);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string whitelist{ "eyuioaEYUIOA" };
	vector<string> st;
	fread_to_vector(st, whitelist, "1.txt");
	for (string& s : st)
		cout << s << endl;
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
