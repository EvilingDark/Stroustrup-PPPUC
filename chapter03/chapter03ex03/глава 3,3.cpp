// ����� 3,3.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	double d = 0;
	while (cin>>d) {   // ��������� ����������� ����������
						// ���� �������� �����
		int i = d; // ������� �������� dou� e � i n t

		char � = i ; // ������� �������� i n t � cha r
		int i2 = � ; // �������� ����� ��� ����� ���� cha r
		cout << " d== " << d // �������� ��� ����� ���� d����
		<< " i== " << i
		<< " i2== " << i2
		// ������� �������� � ��� ����� i n t
		// ������������� ��� ����� cha r
		<< " char(" << � << ")\n"; // ������
	}
	system ("pause");
	return 0;
}
