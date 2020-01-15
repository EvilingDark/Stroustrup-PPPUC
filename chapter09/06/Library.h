#pragma once
#include <Header.h>
#include <Book.h>
#include <Patron.h>
#include <Date.h>

class Library
{
public:
	void new_patron(const Patron& p);
	void new_book(const Book& b);
	//������������
	string pat_name(int i) const { return patrons[i].name(); }		//���������� ��� ������������
	int pat_lib_code(int i) const { return patrons[i].lib_code(); }		//������������ ��� ������������
	bool pat_price_pay(int i) const { return patrons[i].price_pay(); }		//�������� ������� �������������
	Patron patron(int i) const { return patrons[i]; }		//��� ������ � ������������ �� ����������
	int size_patrons() const { return patrons.size(); }		//������ ������� patrons
	//�����
	bool book_in_stock(int i) const { return books[i].in_stock(); }		//������� ����� � ����������
	string book_ISBN(int i) const { return books[i].ISBN(); }		//��� ISBN �����
	void book_change_in_stock(int i) { books[i].change_in_stock(); return; }		//��������� ������� �����
	Book book(int i) const { return books[i]; }		//��� ������ � ����� �� ����������
	int size_books() const { return books.size(); }		//������ ������� books
	Library(Book b, Patron p);
	Library(Patron p);
	Library(Book b);
	Library() {}
	void pat_scroll() const;		//�������� ���� �������������
	void book_scroll() const;		//�������� ��� �����
private:
	vector<Book> books;
	vector<Patron> patrons;
};

