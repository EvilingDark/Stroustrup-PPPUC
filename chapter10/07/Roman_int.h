#pragma once
#include <Header.h>

const vector<char> Roman_priority{
	'I', 'V', 'X', 'L', 'C'
};

const vector<int> Roman_value{
	1, 5, 10, 50, 100
};

class Roman_int
{
public:
	string as_roman() const { return roman; }
	int as_int() const;									//возвращает значение римской цифры в виде int
	Roman_int(string s);
	Roman_int() {}
private:
	string roman;
};

ostream& operator<<(ostream& os, Roman_int& r);
istream& operator>>(istream& is, Roman_int& r);
bool is_same_ch(const string& s, int i, char ch);		//проверяет следующий символ, если такой же возвращает тру
int reiteration(const string& s, int i);				//возвращает количество повторений подряд символа i в s
void repeat(const string& s);							//проверяет на повторения в s, если больше 3 выдает ошибку
bool is_Roman(const string& s);							//проверяет является ли s римской цифрой
int search_pr(const char& ch);							//возвращает приоритет римской цифры
bool next_high_pr(const string& s, int i);				//проверяет приоритет следующей цифры, если больше тру
Roman_int to_Roman(int i);

