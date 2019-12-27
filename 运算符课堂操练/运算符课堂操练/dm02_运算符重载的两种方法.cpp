
#include<iostream>
using namespace std;

class Complex
{
private:
	int a;
	int b;
	//全局函数  重载 + 运算符
	friend Complex	operator+(Complex &c1, Complex &c2);
	//重载 前置++
	friend Complex& operator++(Complex &c1);
	//重载 后置++
	friend Complex operator++ (Complex c1, int);
	//friend Complex& operator--();
public:
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout << a << " + " << b << "i" << endl;
	}
	//成员函数 实现 - 运算符
	Complex operator-(Complex &c2)
	{
		Complex tmp(this->a-c2.a, this->b-c2.b);
		return tmp;
	}
	//成员函数 实现 -- 运算符
	//前置 --
	Complex& operator--()
	{
		this->a--;
		this->b--;
		return *this;
	}
	//后置 --
	Complex operator--(int)//占位符
	{
		Complex tmp = *this;
		this->a--;
		this->b--;
		return tmp;

	}
protected:
private:
};
Complex	operator + (Complex &c1, Complex &c2)
{
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}
//前置 ++
Complex& operator++(Complex &c1)
{
	c1.a++;
	c1.b++;
	return c1;
}
//后置 ++
Complex operator++ (Complex c1,int)
{
	//先使用 再 让c1加加
	//return c1
	Complex tmp = c1;
	c1.a++;
	c1.b++;
	return tmp;
}
void main0201()
{

	Complex c1(1, 2), c2(3, 4);
	Complex c3 = c1 + c2;
	c3.printCom();
	//1  全局函数法 实现 + 运算符重载
	//Complex	coperator +(Complex &c1, Complex &c2)
	//2   成员函数方法 实现 + 运算符 重载
	//c1.operator-(this,c2)
	//Complex operator-(Complex &c2)

	Complex c4 = c1 - c2;
	c4.printCom();

	//前置 ++操作符 用全局函数实现
	++c1;
	c1.printCom();
	
	//前置 ++操作符 用成员函数实现
	--c1;
	c1.printCom();
	
	//后置 ++操作符 用全局函数实现
	c1++;
	c1.printCom();

	//后置 --操作符 用成员函数实现
	c1--;
	c1.printCom();
	//c1.operator--()
	//Complex operator--();

	//Complex operator++ (Complex c1);
	//c1.operator--();
	//Complex &operator--();
	//Complex operator++(Complex &c1);
	cout << "hello world" << endl;
	system("pause");
}