// глава 4,3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

//программа для цензурирования
int main()
{
	setlocale(LC_ALL, "Russian");
	
	cout << "Введите слова с большой буквы\n";
	vector<string> words;
	vector<string> b_words;
	b_words.push_back("Oleg");
	b_words.push_back("Dasha");
	b_words.push_back("Sasha");
	b_words.push_back("Pasha");
	b_words.push_back("Dima");
	b_words.push_back("Anna");
	for (string temp; cin >> temp;)
	{
		if (temp == "break")
			break;
		words.push_back(temp);
	}
	for (int i = 0; i < words.size(); ++i)
	{
		for (int i2 = 0; i2 < b_words.size(); ++i2)
		{
			//cout << words[i] << " " << b_words[i2] << "\n";
			if (words[i] == b_words[i2])
				words[i] = "BLEEP";
			//cout << i << " " << i2 << "\n";
		}
		//cout << words[i] << "\n";
	}
	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << " ";
	cout << "\n";


/*	vector<string> words ;
	for (string temp ; cin>>temp;)
		words.push_back(temp);
	cout << "Количество слов: " << words.size() << '\n';
	sort(words); // Сортировка слов
	for (int i = 0 ; i<words . size ( ) ; ++i )
		if ( i==0 || words[i-1] !=words [i] ) // Это новое слово ?
			cout << words[i] << "\n";*/

	system ("pause");
	return 0;
}

