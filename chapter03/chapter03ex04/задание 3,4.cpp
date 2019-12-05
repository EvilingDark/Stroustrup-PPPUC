// задание 3,4.cpp: определяет точку входа для консольного приложения.
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

	cout << "Введите ваше имя\n";
	string first_name;
	string second_name;
	char friend_sex = '0';
	int age = 0;
//	double age = 0;
//	cin >> first_name >> second_name >> age;
	cin >> first_name;
	cout << "Привет, " << first_name << "\n" << "Введи имя адресата\n";
	cin >> second_name;
	cout << "Введите пол адресата m - мужчина, f - женщина\n";
	cin >> friend_sex;
	cout << "\n";
	cout << "Дорогой " << first_name << "\n" << "\n" << "Как дела? У меня все хорошо. Я скучаю по тебе. Давно ли ты встречал " << second_name << "?\n";

	if (friend_sex == 'm')
		cout << "Если увидишь " << second_name << ", пожалуйста, попроси его перезвонить мне.\n";
	if (friend_sex == 'f')
		cout << "Если увидишь " << second_name << ", пожалуйста, попроси ее перезвонить мне.\n";
	
	cout << "\nВедите ваш возраст\n";
	cin >> age;
	if (age > 0 && age < 110)
	{
		cout << "Я слышал, ты только что отметил день рождения и тебе исполнилось " << age << " лет.\n";
		if (age < 12)
			cout << "На следующий год тебе исполнится " << age+1 << " лет.\n\n";
		if (age == 17)
			cout << "В следующем году ты сможешь голосовать.\n\n";
		if (age > 70)
			cout << "Я надеюсь, что ты не скучаешь на пенсии.\n\n";
	}
	else
		cout << "Ты шутишь.\n\n";
	cout << "Искренне твой\n\n" << "Олег\n";




//	cout << first_name << " " << second_name << " " << age*12 << " мес¤цев" << "\n";
	system ("pause");
	return 0;
}

