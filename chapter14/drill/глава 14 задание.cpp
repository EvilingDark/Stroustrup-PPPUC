// глава 14 задание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <std_lib_facilities.h>

struct B1 {
	virtual void vf() const {
		cout << "B1::vf()" << endl;
	}
	void f() const {
		cout << "B1::f()" << endl;
	}
	virtual void pvf() const {
		cout << "B1::pvf()" << endl;
	}
};

struct D1 : B1 {
	void vf() const {
		cout << "D1::vf()" << endl;
	}
	void f() const {
		cout << "D1::f()" << endl;
	}
};

struct D2 : D1 {
	void pvf() const {
		cout << "D2::pvf()" << endl;
	}
};

struct B2 {
	virtual void pvf() const {
		cout << "B2::pvf()" << endl;
	}
};

struct D21 : B2 {
	string s;
	void pvf() const {
		cout << s << endl;
	}
};

struct D22 : B2 {
	int i;
	void pvf() const {
		cout << i << endl;
	}
	void f(B2& bb) {
		bb.pvf();
	}
};

int main()
{
	D1 dd;
	dd.vf();
	dd.f();
	dd.pvf();
	cout << endl;
	B1& bb = dd;
	bb.vf();
	bb.f();
	bb.pvf();
	cout << endl;
	D2 ddd;
	ddd.vf();
	ddd.f();
	ddd.pvf();
	cout << endl;
	D21 dddd;
	dddd.s = "D21";
	D22 ddddd;
	ddddd.i = 22;
	ddddd.f(dddd);
	ddddd.f(ddddd);
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
