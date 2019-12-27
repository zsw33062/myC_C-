#include<iostream>
using namespace std;


//构造函数中 调用虚函数能发生多态吗
class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
		//print();
	}
	virtual void print()
	{
		cout << " I am Father" << endl;
	}
	virtual void print2()
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
		//print();
	}
	virtual void print()
	{
		cout << " I am Child" << endl;
	}

protected:
private:
	int b;
};
void HowToPlay(Parent &base)
{
	base.print();
	
}
void main03()
{
	Parent	p1;
	Child	c1;//定义一个 子类对象，在这个过层中 在父类构造函数中 调用虚函数 print
			//能发生多态吗？

	HowToPlay(p1);
	HowToPlay(c1);
	//c1.print();
	//1 要初始化 c1.vptr指针，初始化是 分步
	//2 当执行父类的构造函数的时候 ，c1.vptr 指向父类的虚函数表
	//	当父类的构造函数 运行完毕后，会把c1.vptr 指向 子类的虚函数表 
	//结论：子类 的c1.vptr指针分步完成
	cout<<"hello world"<<endl;
	system("pause");
}

