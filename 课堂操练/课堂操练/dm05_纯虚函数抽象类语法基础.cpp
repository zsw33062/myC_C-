#include<iostream>
using namespace std;
//面型抽象类 编程（面向一套 预先定义好的的接口编程）

//解耦合。。。 模块的划分
class Figure	//抽象类
{
	//约定一个统一的界面（接口），让子类使用，让子类必须去实现
public:
	virtual int getArea() = 0;	//纯虚函数
protected:
private:
};
class Circle : public Figure
{
public:
	Circle(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual int getArea()
	{
		cout << "圆形的面积:" << 3.14*a*a << endl;
		return 0;
	}
protected:
private:
	int a;
	int b;
};
class Tri : public Figure
{
public:
	Tri(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual int getArea()
	{
		cout << "三角形的面积:" <<a*b/2 << endl;
		return 0;
	}
protected:
private:
	int a;
	int b;
};
class Square : public Figure
{
public:
	Square(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual int getArea()
	{
		cout << "四边形的面积:" << a*b << endl;
		return 0;
	}
protected:
private:
	int a;
	int b;
};
void objplay(Figure *base)
{
	base->getArea();
}
void main05()
{
	
	//Figure f;//抽象类不能被实例化
	Figure *base = NULL;
	//objplay(base);
	Circle	c1(10, 20);
	Tri		t1(20, 30);
	Square	s1(30, 40);

	//面型抽象类 编程（面向一套 预先定义好的的接口编程）
	objplay(&c1);
	objplay(&t1);
	objplay(&s1);

	//c1.getArea();
	cout<<"hello world"<<endl;
	system("pause");
}