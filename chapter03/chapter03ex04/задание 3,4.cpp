// ������� 3,4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "������� ���� ���\n";
	string first_name;
	string second_name;
	char friend_sex = '0';
	int age = 0;
//	double age = 0;
//	cin >> first_name >> second_name >> age;
	cin >> first_name;
	cout << "������, " << first_name << "\n" << "����� ��� ��������\n";
	cin >> second_name;
	cout << "������� ��� �������� m - �������, f - �������\n";
	cin >> friend_sex;
	cout << "\n";
	cout << "������� " << first_name << "\n" << "\n" << "��� ����? � ���� ��� ������. � ������ �� ����. ����� �� �� �������� " << second_name << "?\n";

	if (friend_sex == 'm')
		cout << "���� ������� " << second_name << ", ����������, ������� ��� ����������� ���.\n";
	if (friend_sex == 'f')
		cout << "���� ������� " << second_name << ", ����������, ������� �� ����������� ���.\n";
	
	cout << "\n������ ��� �������\n";
	cin >> age;
	if (age > 0 && age < 110)
	{
		cout << "� ������, �� ������ ��� ������� ���� �������� � ���� ����������� " << age << " ���.\n";
		if (age < 12)
			cout << "�� ��������� ��� ���� ���������� " << age+1 << " ���.\n\n";
		if (age == 17)
			cout << "� ��������� ���� �� ������� ����������.\n\n";
		if (age > 70)
			cout << "� �������, ��� �� �� �������� �� ������.\n\n";
	}
	else
		cout << "�� ������.\n\n";
	cout << "�������� ����\n\n" << "����\n";




//	cout << first_name << " " << second_name << " " << age*12 << " ������" << "\n";
	system ("pause");
	return 0;
}

