// ����� 3,10.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;
//��������� ���������� ������ �����
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "������� ����� ����� �� 0 �� 4 �������\n";
	string s = " ";
	cin >> s;
//	cout << s << "\n";
	if (s == "zero")
		cout << 0 << "\n";
	else if (s == "one")
		cout << 1 << "\n";
	else if (s == "two")
		cout << 2 << "\n";
	else if (s == "three")
		cout << 3 << "\n";
	else if (s == "four")
		cout << 4 << "\n";
	else
		cout << "� �� ���� ������ �����!\n";

	system ("pause");
	return 0;
}

