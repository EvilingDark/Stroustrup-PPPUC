// глава 9 упр 13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//программа работает с рацианальными числами

#include <Header.h>
#include <Rational.h>

void enter_m(vector<Rational>& rat)
{
	cout << "Введите рациональное число в виде x/x, где x - целое число" << endl;
	char ch;
	int num, den;
	cin >> num >> ch >> den;
	if (ch != '/')
		error("Ошибка ввода");
	if (den <= 0)
		error("Знаменатель не может быть отрицательным или равнятся нулю");
	rat.push_back(Rational(num, den));
	return;
}

void enter_num(int& one, int& two,const vector<Rational>& rat)
{
	cout << "Введите номер первого числа" << endl;
	cin >> one;
	if (one > rat.size() - 1)
		error("Первого числа не существует");
	cout << "Введите номер второго числа" << endl;
	cin >> two;
	if (two > rat.size() - 1)
		error("Второго числа не существует");
	return;
}

void plus_m(const vector<Rational>& rat)
{
	int one, two;
	enter_num(one, two, rat);
	Rational print = r_plus(rat[one], rat[two]);
	cout << endl << "Ответ: " << print << endl;
	return;
}

void minus_m(const vector<Rational>& rat)
{
	int one, two;
	enter_num(one, two, rat);
	Rational print = r_minus(rat[one], rat[two]);
	cout << endl << "Ответ: " << print << endl;
	return;
}

void multiply_m(const vector<Rational>& rat)
{
	int one, two;
	enter_num(one, two, rat);
	Rational print = multiply(rat[one], rat[two]);
	cout << endl << "Ответ: " << print << endl;
	return;
}

void division_m(const vector<Rational>& rat)
{
	int one, two;
	enter_num(one, two, rat);
	Rational print = division(rat[one], rat[two]);
	cout << endl << "Ответ: " << print << endl;
	return;
}

void equally_m(const vector<Rational>& rat)
{
	int one, two;
	enter_num(one, two, rat);
	bool print = equally(rat[one], rat[two]);
	switch (print)
	{
	case (true):
		cout << "Числа равны" << endl;
		break;
	case(false):
		cout << "Числа не равны" << endl;
		break;
		return;
	}
}

void print_m(const vector<Rational>& rat)
{
	cout << endl << "Список доступных рациональных чисел:";
	for (int i = 0; i < rat.size(); ++i)
	{
		cout << endl << i << "  " << rat[i] << endl;
	}
}

int menu(vector<Rational>& rat)
{
	try
	{
		while (cin)
		{
			cout << "Выбирите действие: " << endl << "1 - ввод нового рационального числа"
				<< endl << "2 - сложение" << endl << "3 - вычитание" << endl <<
				"4 - умножение" << endl << "5 - деление" << endl << "6 - равенство" << endl
				<< "7 - список рациональных чисел" << endl;
			int ch;
			cin >> ch;
			switch (ch)
			{
			case(1):
				enter_m(rat);
				break;
			case(2):
				plus_m(rat);
				break;
			case(3):
				minus_m(rat);
				break;
			case(4):
				multiply_m(rat);
				break;
			case(5):
				division_m(rat);
				break;
			case(6):
				equally_m(rat);
				break;
			case(7):
				print_m(rat);
				break;
			default:
				cout << "Действие не известно." << endl;
				break;
			}
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
	vector<Rational> rat;
	while (true)
	{
		menu(rat);
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
