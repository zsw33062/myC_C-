#include<iostream>
using namespace std;
class Location
{
public:
	Location(int xx, int yy);
	Location(const Location &obj);
	~Location();
public:
	int GetX();
	int GetY();

private:
	int X;
	int Y;

};

Location::Location(int xx = 0, int yy = 0)
{
	X = xx;
	Y = yy;
	cout << "Constructor Object." << endl;
}
//copy构造函数 完成对象的初始化
Location::Location(const Location &obj)//
{
	X = obj.X;
	Y = obj.Y;
	//cout << "Object destroyed." << endl;
}
Location::~Location()
{
	cout << X << "," << Y << "  Object destroyed." << endl;
}
int Location::GetX()
{
	return X;
}
int Location::GetY()
{
	return Y;
}
//业务 函数
void f(Location p)
{
	cout << p.GetX() << endl;
}
//结论1：函数的 返回值 是一个元素（复杂类型的），返回的是一个新的匿名对象（所以会调用匿名对象类的copy构造函数）
//匿名对象的去和留
//你这么写代码，设计编译器的大牛们:
//我就给你返回一个新对象


//结论2： 有关匿名对象的去和留
//如果用匿名对象 初始化 另一个同类型的对象 匿名对象 转成有名对象
//如果用匿名对象 赋值给 另一个同类型的对象 匿名对象 被析构
Location g()	//g 函数  返回一个元素
{
	Location A(1, 2);
	return A;
}
void objplay2()
{
	g();
}
void objplay4()
{
	//用匿名对象初始化m，此时C++编译器 直接把匿名对象转成m（扶正）  从匿名转成有名字了 m
	Location m2(1, 2);
	m2 = g();
	printf("因为用匿名对象=给m2，匿名对象被析构 \n");
	cout << m2.GetX() << endl;
}
void main61()
{
	//objplay2();
	//objplay3();
	objplay4();
	cout<<"hello world"<<endl;
	system("pause");
}