// ����� 3,2.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	string previous = " ";

	string current;
	while (cin>>current)
	{
		if (previous == current)
												// ���������� previous ;
												// ���������������� "�� ������"
												// ������� �����
												// ������� �� ����� ����
												// ��������� ����������
												// � ���������� ������
			cout << "������������� ����� : " << current << '\n' ;
		previous = current ;
	}
	system ("pause");
	return 0;
}

