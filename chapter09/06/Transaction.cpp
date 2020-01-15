#include "Transaction.h"

vector<Library> t_lib;

void Transaction::add_patron(const Patron& p)		//�������� ������ ������������ � t_lib
{
	t_lib.push_back(Library(p));
	return;
}

void Transaction::add_book(int t_lib_i, int book_i, Library& lib)		//�������� ����� ����� � t_lib
{
	if (lib.book_in_stock(book_i) == false)
		error("����� ������ �� ����");
	t_lib[t_lib_i].new_book(lib.book(book_i));		//��������� ����� 
	lib.book_change_in_stock(book_i);		//�������� ������� �����
	return;
}

void Transaction::give_out_book(Library& lib)
{
	cout << "������� ������������ ��� ������������\n";
	int code, num_patron = -1, num_ISBN = -1;
	string ISBN;
	cin >> code;
	if (code < 0 || code > 100000)
		error("��������� ������������ ��� ��� ���������� ��������� ��������.");
	cout << "������� ��� ISBN �����\n";
	cin >> ISBN;
	for (int i = 0; i < lib.size_patrons(); ++i)		//���� ������������ � ����������
		if (code == lib.pat_lib_code(i))
			num_patron = i;
	if (num_patron == -1)
		error("������������ �� ������");
	for (int i = 0; i < lib.size_books(); ++i)		//���� ����� � ����������
		if (ISBN == lib.book_ISBN(i))
			num_ISBN = i;
	if (num_ISBN == -1)
		error("����� �� �������");
	if (t_lib.size() == 0)		//��������� ������� ������������ ���� ������ ����
		add_patron(lib.patron(num_patron));
	int t_lib_patron = -1;
	for (int i = 0; i < t_lib.size(); ++i)		//���� ������������ � t_lib
		if (code == t_lib_code(i))
			t_lib_patron = i;
	if (t_lib_patron == -1)		//������� ������ ������������ � t_lib ���� �� �� ������
		add_patron(lib.patron(num_patron));
	add_book(t_lib.size() - 1, num_ISBN, lib);		//��������� ����� � t_lib
	return;
}

void Transaction::print_t_lib()
{
	for (int i = 0; i < t_lib.size(); ++i)
	{
		t_lib[i].pat_scroll();
		cout << "����� �������� ������������:\n";
		t_lib[i].book_scroll();
	}
	return;
}