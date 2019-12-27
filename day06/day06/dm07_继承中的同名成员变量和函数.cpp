#include<iostream>
using namespace std;
class A
{
public:
	int a;
	int b;
public:
	void get()
	{
		cout << "b:"<<b<<endl;
	}
	void print()
	{
		cout << "AAAAA"<<endl;
	}
protected:

private:

};
class B :public A
{
public:
	int b;
	int c;
public:
	void get_child()
	{
		cout << "b:" << b << endl;
	}
	void print()
	{
		cout << "BBBBB"<<endl;
	}
protected:
private:
};
void main72()
{
	B b1;
	b1.print();
	b1.B::print();
	b1.A::print();
	cout << endl;
	system("pause");
}
////同名成员变量
//void main71()
//{
//	A a1;
//	B b1;
//	b1.b = 1;
//	b1.get_child();
//	b1.A::b = 100;//修改父类的b
//	b1.B::b = 200;//修改子类的b
//	//默认情况是子类的
//	b1.get();
//	cout<<"hello world"<<endl;
//	system("pause");
//}