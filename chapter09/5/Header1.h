#pragma once
#include <Header.h>

class Book
{
public:
	void enter();
	string name() const { return p_name; }
	string author() const { return p_author; }
	string ISBN() const { return p_ISBN; }
	string Date() const { return p_Date; }
	bool in_stock() const { return p_in_stock; }
private:
	string p_name{ "123" };
	string p_author{ "123" };
	string p_ISBN{ "123" };
	string p_Date{ "123" };
	bool p_in_stock{ true };
	void en_name();
	void en_author();
	void en_ISBN();
	void en_Date();
	void en_in_stock();
};