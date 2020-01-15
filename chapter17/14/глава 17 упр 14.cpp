// глава 17 упр 14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <std_lib_facilities.h>

class Link {
public:
	Link(const string& name, const string& country = "", const string& weapon = "", Link* s = nullptr)
		:value{ name }, land{ country }, gun{ weapon }, succ{ s } {}

	Link* insert(Link* n);  //вставка n перед данным объектом
	Link* add(Link* p);		//вставка p после данного объекта
	Link* erase(Link* to_del);
	Link* find(const string& s);
	//int find_num(Link* list, const string* s) const;
	Link* _advance(int n) const;
	Link* next() const { return succ; }
	string print_name() const { return value; }
	string print_country() const { return land; }
	string print_weapon() const { return gun; }
	void set_val(const string& name = "", const string& country = "", const string& weapon = "") { if (name != "") value = name; if (country != "") land = country; if (weapon != "") gun = weapon; }
private:
	string value;
	string land;
	string gun;
	Link* succ;
};

Link* Link::insert(Link* n)
{
	Link* p = this;
	if (n == nullptr) return p;
	if (p == nullptr) return n;
	n->succ = p;
	return n;
}

Link* Link::add(Link* p)
{
	Link* n = this;
	if (n == nullptr) return p;
	if (p == nullptr) return n;
	p->succ = n->succ;
	n->succ = p;
	return n;
}

Link* Link::erase(Link* to_del)
{
	if (this == nullptr) return nullptr;
	if (this == to_del) return this->succ;
	Link* n = this;
	while (n->succ!=to_del) n = n->succ;
	n->succ = n->succ->succ;
	return this;
}

Link* Link::find(const string& s)
{
	Link* p = this;
	while (p)
	{
		if (p->value == s || p->land == s || p->gun == s) return p;
		p = p->succ;
	}
	return nullptr;
}

Link* Link::_advance(int n) const
{
	if (this == nullptr) return nullptr;
	Link* p = const_cast<Link*>(this);
	if (0 < n)
	{
		while (n--)
		{
			if (p->succ == nullptr) return nullptr;
			p = p->succ;
		}
	}
	return p;
}

Link* add_ordered(Link* list, Link* added)
{
	if (list == nullptr) return list;
	if (added == nullptr) return added;
	Link* p = list->find(added->print_country());
	if (p)
	{
		p->add(added);
		return list;
	}
	else
	{
		list->insert(added);
		return added;
	}
}

int find_num(Link* list, const string& s)
{
	int counter = 0;
	while (counter++)
	{
		if (list->print_name() == s || list->print_country() == s || list->print_weapon() == s) return counter;
		list = list->next();
		if (list == nullptr) return -1;
	}
}

void print_all(Link* p)
{
	while (p)
	{
		cout << "{ " << p->print_name();
		if (p->print_country() != "") cout << ", " << p->print_country();
		if (p->print_weapon() != "") cout << ", " << p->print_weapon();
		cout << " }";
		if (p = p->next()) cout << " ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Link* gods = new Link{ "Тор", "Норвегия", "Копье Гунгнир" };
	gods = add_ordered(gods, new Link{ "Птах", "Египет", "Джед" });
	gods = add_ordered(gods, new Link{ "Фрея", "Норвегия", "Брисингамен" });
	gods = add_ordered(gods, new Link{ "Зевс", "Греция", "Молния Зевса" });
	gods = add_ordered(gods, new Link{ "Один", "Норвегия", "Молот Мьёльнир" });
	gods = add_ordered(gods, new Link{ "Аид", "Греция", "Скипетр Аида" });
	gods = add_ordered(gods, new Link{ "Гера", "Греция", "Скипетр с кукушкой" });
	gods = add_ordered(gods, new Link{ "Ра", "Египет", "Скипетр Уас" });
	gods = add_ordered(gods, new Link{ "Сешат", "Египет", "Калам" });
	/*gods->add(new Link{ "Птах", "Египет", "Джед" });
	gods->add(new Link{ "Фрея", "Норвегия", "Брисингамен" });
	gods->add(new Link{ "Зевс", "Греция", "Молния Зевса" });
	gods->add(new Link{ "Один", "Норвегия", "Молот Мьёльнир" });
	gods->add(new Link{ "Аид", "Греция", "Скипетр Аида" });
	gods->add(new Link{ "Гера", "Греция", "Скипетр с кукушкой" });
	gods->add(new Link{ "Птах", "Египет", "Джед" });
	gods->add(new Link{ "Ра", "Египет", "Скипетр Уас" });
	gods->add(new Link{ "Сешат", "Египет", "Калам" });*/
	print_all(gods);
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
