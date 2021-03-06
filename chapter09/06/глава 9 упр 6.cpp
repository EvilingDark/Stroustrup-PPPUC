﻿// глава 9 упр 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Программа для учета выданных и доступных книг в библиотеке

#include <Header.h>
#include <Book.h>
#include <Patron.h>
#include <Library.h>
#include <Transaction.h>

void menu()
{	
	try
	{
		Transaction tr_lib;
		Library lib;
		while (cin) {
			cout << "Введите код требуемой операции: \n" << "1 - выдача книги пользователю" << endl
				<< "2 - ввод нового пользователя" << endl << "3 - ввод новой книги" << endl
				<< "4 - просмотр всех книг" << endl << "5 - просморт всех пользователей" << endl
				<< "6 - просмотр пользователей которым были выданы книги" << endl;
			char ch;
			cin >> ch;
			switch (ch)
			{
			case('1'):
				tr_lib.give_out_book(lib);
				break;
			case('2'):
			{
				Patron p;
				p.enter();
				lib.new_patron(p);
				break;
			}
			case('3'):
			{
				Book b;
				b.enter();
				lib.new_book(b);
				break;
			}
			case('4'):
				lib.book_scroll();
				break;
			case('5'):
				lib.pat_scroll();
				break;
			case('6'):
				tr_lib.print_t_lib();
				break;
			default:
				break;
			}
		}
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		keep_window_open();
		return;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	menu();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
