// глава 4,0.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

//программа для перевода валюты в доллары по обменному курсу
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите требуемое количество валюты и знак валюты для перевода в доллары\n" << "E - евро, G - фунты, P - рубли, T - тенге, Y - юани\n";
	double val = 0;
	char s = ' ';
	cin >> val >> s;
	switch (s)
	{
	case 'E':
		cout << val << " евро = " << val/1.1142 << " долларов\n";
		break;
	case 'G':
		cout << val << " фунтов = " << val/0.8031 << " долларов\n";
		break;
	case 'P':
		cout << val << " рублей = " << val/63.1162 << " долларов\n";
		break;
	case 'T':
		cout << val << " тенге = " << val/384.5547 << " долларов\n";
		break;
	case 'Y':
		cout << val << " юаней = " << val/6.8748 << " долларов\n";
		break;
	default:
		cout << val << "Ошибка\n";
		break;
	}




	system ("pause");
	return 0;
}

