// ����� 3,5.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	cout << "������� ���������� ����\n";
	double miles = 0;
	cin >> miles;
	cout << miles << " ���� ��� " << miles*1.609 << " ����������\n";

	system ("pause");
	return 0;
}

