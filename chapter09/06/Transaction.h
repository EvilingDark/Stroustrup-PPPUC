#pragma once
#include <Library.h>

struct Transaction
{
	void give_out_book(Library& lib);
	int t_lib_code(int i) const { return t_lib[i].pat_lib_code(0); }		//возвращает библиотечный код пользователя
	bool t_price_pay(int i) const { return t_lib[i].pat_price_pay(0); }		//возвращает подтверждение отплаты пользователя
	string t_pat_name(int i) const { return t_lib[i].pat_name(0); }		//возвращает имя пользователя
	void add_patron(const Patron& p);		//добавляет нового пользователя в t_lib
	void add_book(int t_lib_i, int book_i, Library& lib);		//добавляет новую книгу в t_lib
	void print_t_lib();		//печатает t_lib
private:
	vector<Library> t_lib;
};

