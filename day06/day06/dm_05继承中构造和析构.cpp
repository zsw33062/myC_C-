#include<iostream>
using namespace std;
//先 调用父类构造函数 再调用子类构造函数
//析构的顺序 和构造相反
class Parent
{
public:
	Parent(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "父类构造函数..." << endl;
	}
	~Parent()
	{
		cout << "父类析构函数..." << endl;
	}
	void printP(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "我是爹" << endl;
	}
private:
	int a;
	int b;

};
class child :public Parent
{
public:
	child(int a,int b,int c) :Parent(a,b)
	{
		this->c = c;
		cout << "子类的构造函数" << endl;
	}
	~child()
	{
		cout << "子类的析构函数" << endl;
	}
protected:
private:
	int c;
};
//class child :public Parent
//{
//public:
//	child(int c)
//	{
//		this->c = c;
//	}
//	void printC()
//	{
//		cout << "我是儿子" << endl;
//	}
//protected:
//private:
//	int c;
//};
void playObj()
{
	child c1(1, 2, 3);
}
void main05()
{
	//child c1(1, 2, 3);
	playObj();
	cout<<"hello world"<<endl;
	system("pause");
}