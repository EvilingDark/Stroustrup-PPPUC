// глава 10 упр 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>
#include <Reading.h>
#include <Day.h>
#include <Month.h>
#include <Year.h>

void print_year(ofstream& ofs, const Year& yy)
{
	ofs << "{ year " << yy.year << " ";
	for (int i = 0; i < 12; ++i)
	{
		if (yy.month[i].month != not_a_month)
		{
			ofs << "{ month " << int_to_month(i) << " ";
			for (int x = 0; x < 32; ++i)
				for (int z = 0; z < 24; ++z)
					if (yy.month[i].day[x].hour[z] != not_a_reading)
						ofs << "( " << x << " " << z << " " << yy.month[i].day[x].hour[z] << " ) ";
			ofs << "} ";
		}		
	}
	ofs << "}" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	//открываем файл ввода
	cout << "Введите имя входного файла\n";
	string iname;
	cin >> iname;
	ifstream ifs(iname);
	if (!ifs) error("Невозможно открыть входной файл ", iname);
	//генерация исключения в случае состояния bad()
	ifs.exceptions(ifs.exceptions() | ios_base::badbit);
	//открываем файл вывода
	cout << "Введите имя выходного файла\n";
	string oname;
	cin >> oname;
	ofstream ofs(oname);
	if (!ofs) error("Невозможно открыть выходной файл ", oname);
	//чтение количества лет
	vector<Year> ys;
	while (true)
	{
		Year y;
		if (!(ifs >> y)) break;
		ys.push_back(y);
	}
	cout << "Считано " << ys.size() << " годичный записей\n";
	for (Year& y : ys) print_year(ofs, y);
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
