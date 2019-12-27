#include<iostream>
using namespace std;
//先 调用父类构造函数 再调用子类构造函数
//析构的顺序 和构造相反
class Object
{
public:
	Object(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "object构造函数 执行" << "a"  << a << " b" << b << endl;
	}
	~Object()
	{
		cout << "object的析构函数" << endl;
	}
protected:
	int a;
	int b;
private:
};
class Parent :public Object
{
public:
	Parent(char *p) :Object(1,2)
 	{
		cout << "父类的构造函数 " << p << endl;
	}
	~Parent()
	{
		cout << "父类析的构函数" << endl;
	}
	void printP(int a, int b)
	{		
		cout << "我是爹 " << endl;
	}
protected:
	char *p;
};
class child :public Parent
{
public:
	child(char *p) :Parent(p), obj1(3, 4), obj2(5, 6)
	{
		this->myp = p;
		cout << "子类的构造函数 " << myp << endl;
	}
	~child()
	{
		cout << "子类的析构函数 " << myp << endl;
	}
	void printC()
	{
		cout << "我是儿子" << endl;
	}
protected:
	char *myp;
	Object obj1;
	Object obj2;

};

void objplay()
{
	child c1("继承测试");
}
void main06()
{
	objplay();
	cout << "hello world" << endl;
	system("pause");
}