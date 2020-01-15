#pragma once
#include <Header.h>

class Patron
{
public:
	void enter();		//ввод нового пользователя
	string name() const { return pr_name; }		//возвращает имя 
	int lib_code() const { return pr_lib_code; }		//возвращает библиотечный код
	double price() const { return pr_price; }		//возвращает цену доступа
	bool price_pay() const { return pr_price_pay; }		//возвращает подтверждение оплаты
private:
	string pr_name;
	int pr_lib_code;
	double pr_price;
	bool pr_price_pay;
	void en_name();
	void en_lib_code();
	void en_price();
	void en_price_pay();
};

void pay_enter(Patron& p);
string check_pay(const Patron& p);
ostream& operator<<(ostream& os, const Patron& p);