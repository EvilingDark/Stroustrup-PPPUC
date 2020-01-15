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
	//пользователи
	string pat_name(int i) const { return patrons[i].name(); }		//возвращает имя пользователя
	int pat_lib_code(int i) const { return patrons[i].lib_code(); }		//библиотечный код пользователя
	bool pat_price_pay(int i) const { return patrons[i].price_pay(); }		//проверка отплаты пользователем
	Patron patron(int i) const { return patrons[i]; }		//все данные о пользователе из библиотеки
	int size_patrons() const { return patrons.size(); }		//размер вектора patrons
	//книги
	bool book_in_stock(int i) const { return books[i].in_stock(); }		//наличие книги в библиотеке
	string book_ISBN(int i) const { return books[i].ISBN(); }		//код ISBN книги
	void book_change_in_stock(int i) { books[i].change_in_stock(); return; }		//изменение наличия книги
	Book book(int i) const { return books[i]; }		//все данные о книге из библиотеке
	int size_books() const { return books.size(); }		//размер вектора books
	Library(Book b, Patron p);
	Library(Patron p);
	Library(Book b);
	Library() {}
	void pat_scroll() const;		//печатает всех пользователей
	void book_scroll() const;		//печатает все книги
private:
	vector<Book> books;
	vector<Patron> patrons;
};

