#include<iostream>
using namespace std;
class A
{
public:
	friend class B;//B类是 A类的好朋友，在B中可以访问A类的私有成员，私有函数
	//生命的位置 和 public private没有关系
	friend void modifyA(A *pA,int _a);//函数modifyA 是类 A的好朋友
	A(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	int getA()
	{
		cout << "a: " << a << endl;
		return 0;
	}
protected:
private:
	int a;
	int b;
};
class B
{
public:
	void Set(int a)
	{
		Aobject.a = a;
	}
	void printB()
	{
		cout << "Aobject.a:" << Aobject.a << endl;
	}
protected:
private:
	A Aobject;
};

void modifyA(A *pA,int _a)
{
	pA->a = _a;
}
//为什么设计 友元函数
//1  1.java --> 1.class(字节码)  ==>反射机制分析1.class找到类对象，直接修改类的私有属性。。。
//反射机制 成为一种标准。。。 jdk。。。sum做成标准 jdk 的api函数中有所体现 AOP
//AOP
//2  1.cpp==>
//预编译 编译 连接 生成 。。gcc -e //gcc -s //gcc -
//gcc -o 1.exe 1.c
//汇编 往回 找。。。很难。。。
//3  开了一个后门。。。 frien

void main()
{
	B b1;
	b1.Set(300);
	b1.printB();
	system("pause");
}
void main2101()
{
	A a1(1, 2);
	a1.getA();
	modifyA(&a1, 300);
	a1.getA();
	cout<<"hello world"<<endl;
	system("pause");
}