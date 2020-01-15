// глава 11 упр 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

void fread(string iname)
{
	ifstream ifst{ iname };
	if (!ifst)
		error("Невозможно открыть входной файл", iname);
	string s;
	int count = 1;
	while (getline(ifst, s))
	{
		cout << "Строка " << count << ':' << endl;
		for (char ch : s)
		{
			string outs{ "Символ " };
			string feature;
			outs = outs + ch + " является";
			if (isspace(ch))
			{
				feature = ", пробельным символом";
				outs += feature;
			}
			if (isalpha(ch))
			{
				feature = ", буквой";
				outs += feature;
			}
			if (isdigit(ch))
			{
				feature = ", десятичной цифрой";
				outs += feature;
			}
			if (isxdigit(ch))
			{
				feature = ", шестнадцатиричной цифрой";
				outs += feature;
			}
			if (isupper(ch))
			{
				feature = ", буквой верхнего регистра";
				outs += feature;
			}
			if (islower(ch))
			{
				feature = ", буквой нижнего регистра";
				outs += feature;
			}
			if (isalnum(ch))
			{
				feature = ", буквой или десятичной цифрой";
				outs += feature;
			}
			if (iscntrl(ch))
			{
				feature = ", управляющим символом";
				outs += feature;
			}
			if (ispunct(ch))
			{
				feature = ", не является ни буквой, ни цифрой, ни разделителем, ни управляющим символом";
				outs += feature;
			}
			if (isprint(ch))
			{
				feature = ", выводится на печать";
				outs += feature;
			}
			if (isgraph(ch))
			{
				feature = ", isalpha() или isdigit() или ispunct()";
				outs += feature;
			}
			cout << outs << endl;
		}
		++count;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	fread("1.txt");
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
