#include <Book.h>

string p_name;
string p_author;
Genre p_genre;
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
		en_genre();
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
	cin.clear();
	while (cin.get() != '\n');
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

bool operator==(const Book& a, const Book& b)
{
	if (a.ISBN() == b.ISBN())
		return true;
	else
		return false;
}

bool operator!=(const Book& a, const Book& b)
{
	return !(a == b);
}

ostream& operator<<(ostream& os, const Book& b)		//печатает название книги, автора, код isbn, жанр
{
	return os << endl << b.name() << endl << b.author()
		<< endl << b.ISBN() << endl << b.genre() << endl;
}

Genre int_to_genre(int i)
{
	if (i < int(Genre::Magical_Realism) || int(Genre::Martial_Arts) < i)
		error("Жанр указан неверно.\n");
	return Genre(i);
}

void Book::en_genre()
{
	cout << "Введите число указывающее на жанр книги.\n"
		<< "Magical_Realism - 1, History - 2, Fantasy - 3, Romance - 4, Horror_Triller - 5\n"
		<< "Competitiv_Sports - 6, Sci_fi - 7, Eastern_Fantasy - 8, Video_Games - 9, ACG - 10\n"
		<< "Realistic_Fiction - 11, War_Military - 12, Martial_Arts - 13\n";
	int i;
	cin >> i;
	p_genre = int_to_genre(i);
	return;
}

string check_book(const Book& b)
{
	switch (b.in_stock())
	{
	case(true):
		return "Книга находится в библиотеке";
	case(false):
		return "Книга выдана на руки";
	default:
		break;
	}
}

string Book::genre() const
{
	string s;
	if (int(p_genre) == 1)
		s = "Magical_Realism";
	if (int(p_genre) == 2)
		s = "History";
	if (int(p_genre) == 3)
		s = "Fantasy";
	if (int(p_genre) == 4)
		s = "Romance";
	if (int(p_genre) == 5)
		s = "Horror_Triller";
	if (int(p_genre) == 6)
		s = "Competitiv_Sports";
	if (int(p_genre) == 7)
		s = "Sci_fi";
	if (int(p_genre) == 8)
		s = "Eastern_Fantasy";
	if (int(p_genre) == 9)
		s = "Video_Games";
	if (int(p_genre) == 10)
		s = "ACG";
	if (int(p_genre) == 11)
		s = "Realistic_Fiction";
	if (int(p_genre) == 12)
		s = "War_Military";
	if (int(p_genre) == 13)
		s = "Martial_Arts";
	return s;
}

void Book::change_in_stock()
{
	p_in_stock = !p_in_stock;
	return;
}