// ����� 3,9.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	cout << "������� ����� �����\n";
	int val = 0;
	cin >> val;
	if (val%2 == 0)
		cout << "����� " << val << " �������� ������\n";
	else 
		cout << "����� " << val << " �� �������� ������\n";
	system ("pause");
	return 0;
}
