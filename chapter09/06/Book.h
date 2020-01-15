#pragma once
#include <Header.h>

enum class Genre {
	Magical_Realism=1, History, Fantasy, Romance, Horror_Triller, Competitiv_Sports, Sci_fi, Eastern_Fantasy, Video_Games, ACG, Realistic_Fiction, War_Military, Martial_Arts
};

class Book
{
public:
	void enter();		//���� ����� �����
	string name() const { return p_name; }		//���������� ��������
	string author() const { return p_author; }		//������
	string genre() const;						//����
	string ISBN() const { return p_ISBN; }		//��� ISBN
	string Date() const { return p_Date; }		//���� �������� ��������� ����
	bool in_stock() const { return p_in_stock; }		//������� ����� � ����������
	void change_in_stock();						//������ ������� ����� � ����������
private:
	string p_name{ "123" };
	string p_author{ "123" };
	Genre p_genre{ Genre::Magical_Realism };
	string p_ISBN{ "123" };
	string p_Date{ "123" };
	bool p_in_stock{ true };
	void en_name();
	void en_author();
	void en_genre();
	void en_ISBN();
	void en_Date();
	void en_in_stock();
};

bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
ostream& operator<<(ostream& os, const Book& b);
Genre int_to_genre(int i);
string check_book(const Book& b);
