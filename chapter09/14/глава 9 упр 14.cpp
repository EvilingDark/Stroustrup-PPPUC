// глава 9 упр 14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//программа работает с валютами, умеет сохранять введенные значения, складывать, умножать и делить на число

#include <Header.h>
#include <Money.h>

void flush_stdin()
{
	cin.clear();
	while (cin.get() != '\n');
}

void enter_m(vector<Cash_t::Money>& mon)
{
	cout << endl << "Введите сумму в виде 'Nx.yy', где N - валюта, x - сумма, yy - двузначное число центов" << endl;
	cout << "> ";
	char ch;
	string num;
	string val;
	do {
		cin.get(ch);
		if (isdigit(ch))
			num += ch;
		else if (ch == '$' || isalpha(ch))
			val += ch;
		else if (ch == ',' || ch == '.')
		{
			for (int i = 0; i < 2; ++i)
			{
				cin.get(ch);
				if (isdigit(ch))
					num += ch;
				else
					error("Ошибка ввода");
			}
			cin.get(ch);
			if (ch != '\n')
				error("Ошибка ввода, ожидался конец строки");
		}
	} while (ch != '\n');
	Cash_t::Money m{ stoi(num), val };
	mon.push_back(m);
}

void enter_num(int& one, int& two, const vector<Cash_t::Money>& mon)
{
	cout << "Введите номер первого числа" << endl;
	cin >> one;
	if (one > mon.size() - 1)
		error("Первого числа не существует");
	cout << "Введите номер второго числа" << endl;
	cin >> two;
	if (two > mon.size() - 1)
		error("Второго числа не существует");
	return;
}

void plus_m(const vector<Cash_t::Money>& mon)
{
	int one, two;
	enter_num(one, two, mon);
	Cash_t::Money print = Cash_t::sum(mon[one], mon[two]);
	cout << endl << "Ответ: " << print << endl;
	return;
}

void minus_m(const vector<Cash_t::Money>& mon)
{
	int one, two;
	enter_num(one, two, mon);
	Cash_t::Money print = Cash_t::dif(mon[one], mon[two]);
	cout << endl << "Ответ: " << print << endl;
	return;
}

void multiply_m(const vector<Cash_t::Money>& mon)
{
	int one;
	cout << "Введите номер числа" << endl;
	cin >> one;
	if (one > mon.size() - 1)
		error("Числа не существует");
	double d;
	cout << "Введите множитель" << endl;
	cin >> d;
	Cash_t::Money print = Cash_t::prod(mon[one], d);
	cout << endl << "Ответ: " << print << endl;
	return;
}

void division_m(const vector<Cash_t::Money>& mon)
{
	int one;
	cout << "Введите номер числа" << endl;
	cin >> one;
	if (one > mon.size() - 1)
		error("Числа не существует");
	double q;
	cout << "Введите делитель" << endl;
	cin >> q;
	Cash_t::Money print = Cash_t::quot(mon[one], q);
	cout << endl << "Ответ: " << print << endl;
	return;
}

void print_m(const vector<Cash_t::Money>& mon)
{
	cout << "Список чисел:" << endl;
	for (int i = 0; i < mon.size(); ++i)
	{
		cout << i << " " << mon[i] << endl;
	}
	return;
}

int menu(vector<Cash_t::Money>& mon)
{
	try
	{
		while (cin)
		{
			cout << "Выбирите действие: " << endl << "1 - ввод нового числа"
				<< endl << "2 - сложение валют" << endl << "3 - разность валют" << endl
				<< "4 - умножение на число" << endl << "5 - деление на число" << endl
				<< "6 - список чисел" << endl;
			int ch;
			cin >> ch;
			switch (ch)
			{
			case(1):
				flush_stdin();
				enter_m(mon);
				break;
			case(2):
				flush_stdin();
				plus_m(mon);
				break;
			case(3):
				flush_stdin();
				minus_m(mon);
				break;
			case(4):
				flush_stdin();
				multiply_m(mon);
				break;
			case(5):
				flush_stdin();
				division_m(mon);
				break;
			case(6):
				flush_stdin();
				print_m(mon);
				break;
			default:
				cout << "Действие не известно." << endl;
				break;
			}
			flush_stdin();
		}
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<Cash_t::Money> mon;
	while (true)
	{
		menu(mon);
	}
	return 0;
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
