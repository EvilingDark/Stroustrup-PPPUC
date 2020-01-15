// глава 11 упр 14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

void fread(string iname)
{
	ifstream ifst{ iname };
	if (!ifst)
		error("Невозможно открыть входной файл", iname);
	string s;
	int space = 0, alpha = 0, digit = 0, xdigit = 0, upper = 0, lower = 0, alnum = 0, cntrl = 0, punct = 0, print = 0, graph = 0;
	while (getline(ifst, s))
	{
		for (char ch : s)
		{
			if (isspace(ch))
				++space;
			if (isalpha(ch))
				++alpha;
			if (isdigit(ch))
				++digit;
			if (isxdigit(ch))
				++xdigit;
			if (isupper(ch))
				++upper;
			if (islower(ch))
				++lower;
			if (isalnum(ch))
				++alnum;
			if (iscntrl(ch))
				++cntrl;
			if (ispunct(ch))
				++punct;
			if (isprint(ch))
				++print;
			if (isgraph(ch))
				++graph;
		}
	}
	ofstream ofst("2.txt");
	if (!ofst) error("Невозможно открыть выходной файл");
	ofst << space << " пробельных символов" << endl
		<< alpha << " букв" << endl
		<< digit << " десятичных цифр" << endl
		<< xdigit << " шестнадцатиричных цифр" << endl
		<< upper << " букв верхнего регистра" << endl
		<< lower << " букв нижнего регистра" << endl
		<< alnum << " букв или десятичных цифр" << endl
		<< cntrl << " управляющих символов" << endl
		<< punct << " не являетюся ни буквой, ни цифрой, ни разделителем, ни управляющим символом" << endl
		<< print << " выводятся на печать" << endl
		<< graph << " isalpha() или isdigit() или ispunct()" << endl;
}

int main()
try
{
	setlocale(LC_ALL, "Russian");

	fread("1.txt");
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
