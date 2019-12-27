#include<iostream>
using namespace std;


class Parent
{
public:
	void printP()
	{
		cout << "我是爹" << endl;
	}
protected:
private:
	int a;
};
class Child : public Parent
{
public:
	void printC()
	{
		cout << "我是儿子" << endl;
	}
	

private:

};

//C++编译器是不会报错的
void howToPrint(Parent *base)
{
	base->printP();
}
void howToPrint2(Parent &base)
{
	base.printP();
}

void main04()
{
	Parent p1;
	p1.printP();
	Child c1;
	c1.printC();
	c1.printP();

	//赋值兼容性原则
	//1-2 基类指针（引用） 指向子类对象
	Parent *p = NULL;
	p = &c1;
	p->printP();
	
	//1-2指针做函数参数

	howToPrint(&p1);
	howToPrint(&c1);

	//1-3引用
	howToPrint2(p1);
	howToPrint2(c1);

	//第二层含义
	//可以用父类对象 初始化 子类对象
	//子类就是一种特殊的父类
	Parent p3 = c1; 
	cout<<"hello world"<<endl;
	system("pause");
}