#include "Library.h"

vector<Book> books;
vector<Patron> patrons;

Library::Library(Book b, Patron p)
{
	books.push_back(b);
	patrons.push_back(p);
	return;
}

Library::Library(Patron p)
{
	patrons.push_back(p);
	return;
}

Library::Library(Book b)
{
	books.push_back(b);
	return;
}

void Library::new_patron(const Patron& p)
{
	for (int i = 0; i < patrons.size(); ++i)
	{
		if (p.lib_code() == patrons[i].lib_code())
			error("Пользователь уже существует.");
	}
	patrons.push_back(p);
	return;
}

void Library::new_book(const Book& b)
{
	for (int i = 0; i < books.size(); ++i)
	{
		if (b.ISBN() == books[i].ISBN())
			error("Книга уже существует");
	}
	books.push_back(b);
	return;
}

void Library::pat_scroll() const
{
	for (int i = 0; i < patrons.size(); ++i)
		cout << endl << "Пользователь: " << patrons[i].name() << endl << 
		"Библиотечный код: " <<patrons[i].lib_code()
		<< endl << check_pay(patrons[i]) << endl << endl;
}

void Library::book_scroll() const
{
	for (int i = 0; i < books.size(); ++i)
		cout << endl << "Название: " << books[i].name() << endl << 
		"Автор: " << books[i].author()
		<< endl << books[i].ISBN() << endl << books[i].genre()
		<< endl << check_book(books[i]) << endl << endl;
}