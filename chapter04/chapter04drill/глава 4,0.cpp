// ����� 4,0.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

//��������� ��� �������� ������ � ������� �� ��������� �����
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "������� ��������� ���������� ������ � ���� ������ ��� �������� � �������\n" << "E - ����, G - �����, P - �����, T - �����, Y - ����\n";
	double val = 0;
	char s = ' ';
	cin >> val >> s;
	switch (s)
	{
	case 'E':
		cout << val << " ���� = " << val/1.1142 << " ��������\n";
		break;
	case 'G':
		cout << val << " ������ = " << val/0.8031 << " ��������\n";
		break;
	case 'P':
		cout << val << " ������ = " << val/63.1162 << " ��������\n";
		break;
	case 'T':
		cout << val << " ����� = " << val/384.5547 << " ��������\n";
		break;
	case 'Y':
		cout << val << " ����� = " << val/6.8748 << " ��������\n";
		break;
	default:
		cout << val << "������\n";
		break;
	}




	system ("pause");
	return 0;
}

