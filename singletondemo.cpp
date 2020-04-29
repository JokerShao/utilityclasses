#include <iostream>
#include <string>
#include "singleton.h"


class A {
public:
	A() {}
	~A() {}

	void print() { std::cout << "A print.\n"; }
};

class B {
public:
	B() {}
	~B() {}

	void print() { std::cout << "B print.\n"; }
};

class C {
public:
	C() {}
	~C() {}

	void print() { std::cout << "C print.\n"; }
};


int singleton_demo()
{
	// 等同于入口函数int main()
	auto aa0 = Singleton<A>::GetInstance();
	auto aa1 = Singleton<A>::GetInstance();
	auto aa2 = Singleton<A>::GetInstance();

	auto bb0 = Singleton<B>::GetInstance();
	auto bb1 = Singleton<B>::GetInstance();
	auto bb2 = Singleton<B>::GetInstance();

	auto cc0 = Singleton<C>::GetInstance();
	auto cc1 = Singleton<C>::GetInstance();
	auto cc2 = Singleton<C>::GetInstance();

	std::cout << "aa0 addr: " << aa0 << "\n";
	std::cout << "aa1 addr: " << aa1 << "\n";
	std::cout << "aa2 addr: " << aa2 << "\n\n";

	std::cout << "bb0 addr: " << bb0 << "\n";
	std::cout << "bb1 addr: " << bb1 << "\n";
	std::cout << "bb2 addr: " << bb2 << "\n\n";

	std::cout << "cc0 addr: " << cc0 << "\n";
	std::cout << "cc1 addr: " << cc1 << "\n";
	std::cout << "cc2 addr: " << cc2 << "\n\n";

	return 0;
}

