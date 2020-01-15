#include <Header1.h>

string p_name;
string p_author;
string p_ISBN;
string p_Date;
bool p_in_stock;

void Book::enter()
{
	try
	{
		cout << "Функция добавления книги в библиотеку.\n";
		en_name();
		en_author();
		en_ISBN();
		en_Date();
		en_in_stock();
		return;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		keep_window_open();
		return;
	}
}

void Book::en_name()
{
	cout << "Введите название книги.\n";
	string title;
	while (cin) {
		string s;
		char ch;
		cin >> s;
		title += s;
		cin.get(ch);
		if (ch == '\n')
		{
			p_name = title;
			return;
		}
		if (isspace(ch))
			title += ' ';
		cin.unget();
	}
}

void Book::en_author()
{
	cout << "Введите автора книги.\n";
	string creator;
	while (cin) {
		string s;
		char ch;
		cin >> s;
		creator += s;
		cin.get(ch);
		if (ch == '\n')
		{
			p_author = creator;
			return;
		}
		if (isspace(ch))
			creator += ' ';
		cin.unget();
	}
}

void Book::en_ISBN()
{
	cout << "Введите код ISBN книги.\n"
		<< "В формате n-n-n-x, где n - целое число, x - цифра или буква\n";
	string code;
	int check = 0;		//счетчик чтобы считать 3 '-'
	while (cin) {
		char ch;
		if (check < 3)
		{
			cin.get(ch);
			if (isdigit(ch))
			{
				cin.unget();
				int i;
				cin >> i;
				code += to_string(i);
			}
			else
				error("ISBN введен неверно");
		}
		cin.get(ch);
		if (ch == '-')
		{
			code += '-';
			check++;
		}
		else if (isalpha(ch) && check == 3)
		{
			code += ch;
			p_ISBN = code;
			return;
		}
		else if (isdigit(ch) && check == 3)
		{
			code += ch;
			p_ISBN = code;
			return;
		}
		else
			error("ISBN введен неверно");
	}
}

void Book::en_Date()
{
	cout << "Введите дату регистрации авторских прав.\n"
		<< "В формате dd.mm.yyyy\n";
	string time;
	int check = 0;  //счетчик чтобы считать 2 '.'
	cin.clear();
	while (cin.get() != '\n');
	while (cin)
	{
		char ch;
		cin.get(ch);
		if (isdigit(ch))
		{
			cin.unget();
			int i;
			cin >> i;
			if (check == 0 && (i < 1 || i > 31))
				error("День введен неверно.");
			if (check == 1 && (i < 1 || i > 12))
				error("Месяц введен неверно.");
			if (check == 2 && i < 0)
				error("Год введен неверно.");
			time += to_string(i);
		}
		else
			error("Дата введена неверно.");
		cin.get(ch);
		if (ch == '\n')
		{
			p_Date = time;
			return;
		}
		else if (ch == '.')
		{
			time += '.';
			check++;
		}
		else
			error("Дата введена неверно.");
	}
}

void Book::en_in_stock()
{
	cout << "Книга находится в библиотеке?\n" << "y - да/n - нет\n";
	char ch;
	cin >> ch;
	switch (ch)
	{
	case('y'):
		p_in_stock = true;
		return;
	case('n'):
		p_in_stock = false;
		return;
	default:
		error("Неизвестный ответ");
	}
}