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
	int as_int() const;									//���������� �������� ������� ����� � ���� int
	Roman_int(string s);
	Roman_int() {}
private:
	string roman;
};

ostream& operator<<(ostream& os, Roman_int& r);
istream& operator>>(istream& is, Roman_int& r);
bool is_same_ch(const string& s, int i, char ch);		//��������� ��������� ������, ���� ����� �� ���������� ���
int reiteration(const string& s, int i);				//���������� ���������� ���������� ������ ������� i � s
void repeat(const string& s);							//��������� �� ���������� � s, ���� ������ 3 ������ ������
bool is_Roman(const string& s);							//��������� �������� �� s ������� ������
int search_pr(const char& ch);							//���������� ��������� ������� �����
bool next_high_pr(const string& s, int i);				//��������� ��������� ��������� �����, ���� ������ ���
Roman_int to_Roman(int i);

