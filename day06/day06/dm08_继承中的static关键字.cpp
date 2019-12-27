#include<iostream>
using namespace std;
class A
{

//单例 构造函数默认是私有的
public:
	A()
	{
	cout << "A的构造函数";
	}
public:
	static int a;
	int b;
public:
	void get()
	{
		cout << "b:" << b << endl;
	}
	void print()
	{
		cout << "AAAAA" << endl;
	}
protected:

private:

};
int A::a = 100;//这句话 不是简单的变量赋值 更重要的是告诉C++编译器
				//你要给我分配内存，我在继承类中 用到了a 不然会报错...
class B :private A
{
	/*B()
	{
	cout << "B的构造函数" << endl;
	}*/
public: 
	int b;
	int c;
public:
	void get_child()
	{
		cout << "b:" << b << endl;
		cout << a << endl;
	}
	void print()
	{
		cout << "BBBBB" << endl;
	}
protected:
private:
};

//1  static 关键字 遵守 派生类访问控制规则
//2  //这句话 不是简单的变量赋值 更重要的是告诉C++编译器
//你要给我分配内存，我在继承类中 用到了a 不然会报错...
//3 A类中添加构造函数 A类的构造函数中 A类的构造函数 是私有的
//被别的类继承要小心
//单例场景 UML
void main02()
{
	//A a1;
	//a1.print();
	
	//B b1;
	//b1.get_child();
	system("pause");
}
void main01()
{
	//B b1;
	//b1.a = 200;

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