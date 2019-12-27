#include<iostream>
using namespace std;

//重写 重载 重定义
//重写发生在2个类之间
//重载必须在一个类之间

//重写分为2类
//1 虚函数重写 将发生多态
//2 非虚函数重写 （重定义）


class Parent
{
	//这三个函数都是重载关系
public:
	void abc()
	{
		printf("abc\n");
	}
	/*virtual void abc()
	{
		cout << "abc do" << endl;
	}*/
	virtual void func()
	{
		cout << "func() do..." << endl;
	}
	virtual void func(int i)
	{
		cout << "func() do..." << i << endl;
	}

	virtual void func(int i, int j,int m,int n)
	{
		cout << "func() do...m n" << i << j << endl;
	}
protected:
private:
};
class Child :public Parent
{
	//重载
public:
	void abc()
	{
		printf("child abc\n");
	}
	virtual void abc(int a)
	{
	cout << "abc do" << endl;
	}
	virtual void func(int i, int j)
	{
		cout << "fun(int i,int j) do..." << i << j << endl;
	}
	virtual void func(int i, int j,int k)
	{
		cout << "fun(int i,int j,int k) do..." << i << j << endl;
	}
protected:
private:
};
void main()
{
	//error C2661:"Child :: func":没有重载函数 接受 0个参数
	Child c1;
	c1.Parent::fun(); 
	//c1.func()
	//子类无法重载父类的函数，父类同名函数将被名称覆盖

	//重载在同一类之间
	//1  C++编译器 看到func 名字，在子类中已经纯在了。所以C++不会去找父类的4个参数的func函数
	//2  C++编译器只会在子类中，查找func 函数，找到了两个func，一个是2个参数的，一个是3个参数的
	//3  C++编译器开始报错 。。。。 error C2661：“Child::func”:没有重载函数接受4各参数
	//4   若想调用父类的func，只能嘉盛父类的域名.. 这样去调用..
	c1.func(1,2,3,4);

	//c1.fun();
	//func 函数的名字，在子类中发生了名称覆盖；子类的函数的名字，占用了父类的函数的名字的位置
	//因为子类中已有了func名字的重载形式。。。
	//编译器开始在子类中找func函数。。。。但是没有0个参数的func函数
	cout<<"hello world"<<endl;
	system("pause");
}