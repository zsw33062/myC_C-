#include<iostream>
using namespace std;
class Interface1
{
public:
	virtual int add(int a, int b) = 0;
	virtual void print() = 0;
protected:
private:
};
class Interface2
{
public:
	virtual int mult(int a, int b) = 0;
	virtual void print() = 0;
protected:
private:
};
class Parent
{
public:
	int getA()
	{
		a = 0;
		return a;
	}
protected:
private:
	int a;
};
class Child : public Parent, public Interface1, public Interface2
{
public:
	virtual int add(int a, int b) 
	{
		cout << "Child: print()�Ѿ�ִ��\n";
		return a + b;
	}
	virtual void print()
	{
		cout << "Child: print()�Ѿ�ִ��\n";
	}
	virtual int mult(int a, int b)
	{
		cout << "Child: print()�Ѿ�ִ��\n";
		return a*b;
	}

protected:
private:
};
void main0701()
{
	Child c1;
	c1.print();

	Interface1 *it1 = &c1;
	it1->add(1, 2);

	Interface2 *it2 = &c1;
	it2->mult(2, 3);
	cout<<"hello world"<<endl;
	system("pause");
}