// глава 11 упр 16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

int main()
try
{
	setlocale(LC_ALL, "Russian");
	string iname = "1.txt";
	ifstream ifst(iname);
	if (!ifst) error("Невозможно открыть входной файл", iname);
	string oname = "2.txt";
	ofstream ofst(oname);
	if (!ofst) error("Невозможно открыть выходной файл", iname);
	vector<int> iv;
	for (int i = 0; ifst >> i;)
		iv.push_back(i);
	sort(iv.begin(), iv.end());
	int current = 0, previous = 0, count = 0;
	for (int i = 0; i < iv.size(); ++i)
	{
		current = iv[i];
		if (current > previous)
		{
			for (int j = i; j < iv.size(); ++j)
				if (iv[i] == iv[j])
					++count;
			ofst << iv[i];
			if (count > 1)
				ofst << ' ' << count;
			ofst << endl;
			count = 0;
			previous = current;
		}
		else if (i==0)
		{
			for (int j = i; j < iv.size(); ++j)
				if (iv[i] == iv[j])
					++count;
			ofst << iv[i];
			if (count > 1)
				ofst << ' ' << count;
			ofst << endl;
			count = 0;
			previous = current;
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
