// глава 10 упр 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>
#include <Reading.h>

void fread_to_vector(vector<Reading>& read, string iname)
{
	ifstream ist{ iname };
	if (!ist)
		error("Невозможно открыть входной файл", iname);
	int hour;
	double temp;
	char ch;
	while (ist >> hour >> temp >> ch)
	{
		if (0 <= hour && 23 >= hour)
		{
			if (ch == 'f')
				read.push_back(Reading{ hour, temp, ch });
			else if (ch == 'c')
				read.push_back(Reading{ hour, temp * 9 / 5 + 32, 'f' });
			else
				error("Ошибка чтения файла");
		}
		else
			error("Некорректное время в файле ", iname);
		if (ist.eof()) {
			cout << "Достигнут конец файла" << iname << endl;
			return;
		}
	}
}

void write_to_file(const vector<Reading>& read, string oname)
{
	ofstream ost{ oname };
	if (!ost)
		error("Невозможно открыть выходной файл", oname);
	for (int i = 0; i < read.size(); ++i)
		ost << read[i].hour << ' ' << read[i].temperature << ' ' <<  read[i].grade << endl;
}

void enter(vector<Reading>& read) 
{
	cout << "Введите час и температуру 10 раз в формате h t g, где h - час, t - температура, g - единица измерения температуры" << endl;
	for (int i = 0; i < 10; ++i)
	{
		int hour;
		double temp;
		char ch;
		cin >> hour >> temp >> ch;
		if (0 <= hour && 23 >= hour)
			if (ch == 'c' || ch == 'f')
				read.push_back(Reading{ hour, temp, ch });
			else
				error("Неверный формат ввода");
		else
			error("Некорректное время");
	}
}

void print(const vector<Reading>& read)
{
	cout << endl;
	for (int i = 0; i < read.size(); ++i)
	{
		cout << read[i].hour << ' ' << read[i].temperature << ' ' << read[i].grade << endl;
	}
	cout << endl;
}

double sum(const vector<Reading>& read)
{
	double s = 0;
	for (int i = 0; i < read.size(); ++i)
		s += read[i].temperature;
	return s;
}

double mediana(const vector<Reading>& read_orig)
{
	vector<double> read;
	for (int i = 0; i < read_orig.size(); ++i)
		read.push_back(read_orig[i].temperature);
	sort(read.begin(), read.end());
	if (read.size() % 2 == 1)
		return read[(read.size() - 1) / 2];
	else
		return (read[read.size() / 2] + read[read.size() / 2 - 1]) / 2;
}

int main()
try
{
	setlocale(LC_ALL, "Russian");
	vector<Reading> raw_t;
	enter(raw_t);
	print(raw_t);
	write_to_file(raw_t, "raw_temps.txt");
	vector<Reading> work_t;
	fread_to_vector(work_t, "raw_temps.txt");
	print(work_t);
	cout << "Среднее " << sum(work_t) / work_t.size() << endl;
	cout << "Медиана " << mediana(work_t) << endl;
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
