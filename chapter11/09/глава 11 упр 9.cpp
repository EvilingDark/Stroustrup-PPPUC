// глава 11 упр 9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

void fread_to_fbinary(string iname, string oname)
{
	ifstream ifs{ iname };
	if (!ifs) error("Невозиожо ОТ!ЫЬ входной фа ", iname);
	ofstream ofs{ oname , ios_base::binary };
	if (!ofs) error("Невозиожо ОТ!ЫЬ выодной фа ", oname);
	char ch;
	vector<char> cv;
	while (ifs.get(ch))
		cv.push_back(ch);
	for (char c : cv)
		ofs.write(as_bytes(c), sizeof(char));
}

void fbread_to_char(string iname, string oname)
{
	ifstream ifs{ iname , ios_base::binary };
	if (!ifs) error("Невозиожо ОТ!ЫЬ входной фа ", iname);
	ofstream ofs{ oname };
	if (!ofs) error("Невозиожо ОТ!ЫЬ выодной фа ", oname);
	vector<char> cv;
	for (char ch; ifs.read(as_bytes(ch), sizeof(char));)
		cv.push_back(ch);
	for (int i=0;i<cv.size();++i)
		ofs << cv[i];
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введте имя файла для ввода\n";
	string iname;
	cin >> iname;
	cout << "Введте имя первого файл для вывода\n";
	string oname;
	cin >> oname;
	cout << "Введте имя второго файл для вывода\n";
	string oname2;
	cin >> oname2;
	fread_to_fbinary(iname, oname);
	fbread_to_char(oname, oname2);
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
