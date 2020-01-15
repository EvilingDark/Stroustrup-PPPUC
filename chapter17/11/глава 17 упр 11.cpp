// глава 17 упр 11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <std_lib_facilities.h>

class Link {
public:
	Link(const string& v, Link* p = nullptr, Link* s = nullptr)
		:value{ v }, prev{ p }, succ{ s } {}

	Link* insert(Link* n);  //вставка n перед данным объектом
	Link* add(Link* p);		//вставка p после данного объекта
	Link* erase();
	Link* find(const string& s);
	//const Link* find(const string* s) const;
	Link* _advance(int n) const;
	Link* next() const { return succ; }
	Link* previous() const { return prev; }
	string print_val() const { return value; }
	void set_val(string& s) { value = s; }
private:
	string value;
	Link* prev;
	Link* succ;
};

Link* Link::insert(Link* n)
{
	Link* p = this;
	if (n == nullptr) return p;
	if (p == nullptr) return n;
	n->succ = p;
	if (p->prev) p->prev->succ = n;
	n->prev = p->prev;
	p->prev = n;
	return n;
}

Link* Link::add(Link* p)
{
	Link* n = this;
	if (n == nullptr) return p;
	if (p == nullptr) return n;
	if (n->succ)
	{
		p->succ = n->succ;
		n->succ->prev = p;
	}
	n->succ = p;
	p->prev = n;
	return n;
}

Link* Link::erase()
{
	if (this == nullptr) return nullptr;
	Link* p = this;
	if (p->succ)p->succ->prev = p->prev;
	if (p->prev)p->prev->succ = p->succ;
	return p->succ;
}

Link* Link::find(const string& s)
{
	Link* p = this;
	while (p)
	{
		if (p->value == s) return p;
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
	else if (n < 0)
	{
		while (n++)
		{
			if (p->prev == nullptr) return nullptr;
			p = p->prev;
		}
	}
	return p;
}

void print_all(Link* p)
{
	cout << "{ ";
	while (p)
	{
		cout << p->print_val();
		if (p = p->next()) cout << ", ";
	}
	cout << " }" << endl;
}

int main()
{
	Link* gods = new Link{ "Thor" };
	print_all(gods);
	gods->add(new Link{ "Odin" });
	print_all(gods);
	gods->_advance(1)->add(new Link{ "Freia" });
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
