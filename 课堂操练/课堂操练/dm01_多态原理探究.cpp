#include<iostream>
using namespace std;
//多态成立的三个条件
//要有继承 虚函数重写 父类指针指向子类对象

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}
	virtual void print() //1 动手脚 写 virtual关键字 会特殊处理  //虚函数表
	{
		cout << " I am Father" << endl;
	}
	
protected:
private:
	int a;
};
class Child : public Parent
{
public:
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout << " I am Child" << endl;
	}

protected:
private:
	int b;
};
void HowToPlay(Parent *base)
{
	base->print();//会有多态发生  //2 动手脚 
	//传来子类 对象 执行子类的print 函数 传来 父类对象 执行 父类的print 函数
	//C++编译器 根本不需要 区分 是子类对象 还是父类对象
	//父类对象 和 子类对象 分别有vptr 指针，==》虚函数表==》函数的入口地址
	//迟绑定 （运行的时候 ，C++编译器才去判断）
}
void main01()
{
	
	Parent	p1;		//3 动手脚用类 定义对象的时候 C++编译器 会在对象中 添加一个vptr 指针
	Child	c1;		//子类里面 也有一个vptr 指针
	HowToPlay(&p1);
	HowToPlay(&c1);
	cout<<"hello world"<<endl;
	system("pause");
}