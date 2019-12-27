#include<iostream>
using namespace std;
class Location
{
public:
	Location(int xx,int yy);
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
	cout << "Object destroyed." << endl;
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
void playobj()
{
	//创建了三个对象 调用了三次析构函数
	Location a(1, 2);
	Location b = a;
	cout << "b  对象 已经初始化完毕" << endl;
	//	cout << p.GetX() << endl;
	f(b);//b 实参取初始化形参p 会调用copy 构造函数
}

void main51()
{
	
	
	playobj();//b 实参取初始化形参 p，会调用copy构造函数
	
	cout<<"hello world"<<endl;
	system("pause");
}