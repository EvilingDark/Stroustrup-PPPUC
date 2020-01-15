#pragma once
#include <Library.h>

struct Transaction
{
	void give_out_book(Library& lib);
	int t_lib_code(int i) const { return t_lib[i].pat_lib_code(0); }		//���������� ������������ ��� ������������
	bool t_price_pay(int i) const { return t_lib[i].pat_price_pay(0); }		//���������� ������������� ������� ������������
	string t_pat_name(int i) const { return t_lib[i].pat_name(0); }		//���������� ��� ������������
	void add_patron(const Patron& p);		//��������� ������ ������������ � t_lib
	void add_book(int t_lib_i, int book_i, Library& lib);		//��������� ����� ����� � t_lib
	void print_t_lib();		//�������� t_lib
private:
	vector<Library> t_lib;
};

