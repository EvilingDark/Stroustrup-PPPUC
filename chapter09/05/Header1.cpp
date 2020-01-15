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
		cout << "������� ���������� ����� � ����������.\n";
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
	cout << "������� �������� �����.\n";
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
	cout << "������� ������ �����.\n";
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
	cout << "������� ��� ISBN �����.\n"
		<< "� ������� n-n-n-x, ��� n - ����� �����, x - ����� ��� �����\n";
	string code;
	int check = 0;		//������� ����� ������� 3 '-'
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
				error("ISBN ������ �������");
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
			error("ISBN ������ �������");
	}
}

void Book::en_Date()
{
	cout << "������� ���� ����������� ��������� ����.\n"
		<< "� ������� dd.mm.yyyy\n";
	string time;
	int check = 0;  //������� ����� ������� 2 '.'
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
				error("���� ������ �������.");
			if (check == 1 && (i < 1 || i > 12))
				error("����� ������ �������.");
			if (check == 2 && i < 0)
				error("��� ������ �������.");
			time += to_string(i);
		}
		else
			error("���� ������� �������.");
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
			error("���� ������� �������.");
	}
}

void Book::en_in_stock()
{
	cout << "����� ��������� � ����������?\n" << "y - ��/n - ���\n";
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
		error("����������� �����");
	}
}