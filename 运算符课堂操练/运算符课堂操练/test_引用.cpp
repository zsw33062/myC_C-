#include<iostream>
using namespace std;
class A {
public:
	A() {
		cout << this << "--this is a constructor" << endl;
	}
	~A() {
		cout << this << "--this is a destructor" << endl;
	}
	A(const A & another) {
		cout << this << "--copy constructor from--" << &another << endl;
	}
	A & operator=(const A & other) {
		cout << this << "--assignment operator overloading from--" << &other << endl;
		return *this;
	}
};

A &func(A a) {
	return a;
}

int maintest() {
	A x;
	A t;
	t = func(x);
	system("pause");
	return 0;
}
