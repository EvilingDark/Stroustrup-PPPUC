#include "Transaction.h"

vector<Library> t_lib;

void Transaction::add_patron(const Patron& p)		//добавить нового пользователя в t_lib
{
	t_lib.push_back(Library(p));
	return;
}

void Transaction::add_book(int t_lib_i, int book_i, Library& lib)		//добавить новую книгу в t_lib
{
	if (lib.book_in_stock(book_i) == false)
		error("Книга выдана на руки");
	t_lib[t_lib_i].new_book(lib.book(book_i));		//добавляем книгу 
	lib.book_change_in_stock(book_i);		//изменяем наличие книги
	return;
}

void Transaction::give_out_book(Library& lib)
{
	cout << "Введите библиотечный код пользователя\n";
	int code, num_patron = -1, num_ISBN = -1;
	string ISBN;
	cin >> code;
	if (code < 0 || code > 100000)
		error("Введенный библиотечный код вне возможного диапозона значений.");
	cout << "Введите код ISBN книги\n";
	cin >> ISBN;
	for (int i = 0; i < lib.size_patrons(); ++i)		//ищем пользователя в библиотеке
		if (code == lib.pat_lib_code(i))
			num_patron = i;
	if (num_patron == -1)
		error("Пользователь не найден");
	for (int i = 0; i < lib.size_books(); ++i)		//ищем книгу в библиотеке
		if (ISBN == lib.book_ISBN(i))
			num_ISBN = i;
	if (num_ISBN == -1)
		error("Книга не найдена");
	if (t_lib.size() == 0)		//присвоить первого пользователя если вектор пуст
		add_patron(lib.patron(num_patron));
	int t_lib_patron = -1;
	for (int i = 0; i < t_lib.size(); ++i)		//ищем пользователя в t_lib
		if (code == t_lib_code(i))
			t_lib_patron = i;
	if (t_lib_patron == -1)		//создаем нового пользователя в t_lib если он не найден
		add_patron(lib.patron(num_patron));
	add_book(t_lib.size() - 1, num_ISBN, lib);		//добавляем книгу в t_lib
	return;
}

void Transaction::print_t_lib()
{
	for (int i = 0; i < t_lib.size(); ++i)
	{
		t_lib[i].pat_scroll();
		cout << "Книги выданные пользователю:\n";
		t_lib[i].book_scroll();
	}
	return;
}