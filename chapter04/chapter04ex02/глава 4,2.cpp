// ����� 4,2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

int square_m(int x)
{
	int y = 0;
	for (int i = 0; i < x; ++i)
	{
		y += x;
		cout << y << "\n";

	}
	return y;
}

//��������� ��� ���������� � �������
int main()
{
	setlocale(LC_ALL, "Russian");
	
	cout << "������� ����� ��� ���������� � �������\n";
	int x = 0;
	cin >> x;
	cout << square_m(x) << "  " << x*x << "\n";

	system ("pause");
	return 0;
}

