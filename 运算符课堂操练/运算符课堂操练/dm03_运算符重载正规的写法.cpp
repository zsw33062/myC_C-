
#include<iostream>
using namespace std;
//class ostream
//{
//public:
//protected:
//private:
//};
class Complex
{
private:
	int a;
	int b;
	//friend void operator<<(ostream &out, Complex c1);
	friend ostream& operator<<(ostream &out, const Complex &c1);
public:
	//实现 + 运算符 重载
	Complex	operator + ( Complex &c2)
	{
		Complex tmp(this->a + c2.a, this->b + c2.b);
		return tmp;
	}
	//前置 ++
	Complex& operator++()
	{
		this->a++;
		this->b++;
		return *this;
	}
	//后置 ++
	Complex operator++ (int)
	{
		//先使用 再 让c1加加
		//return c1
		Complex tmp = *this;
		this->a++;
		this->b++;
		return tmp;
	}
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
		Complex tmp(this->a - c2.a, this->b - c2.b);
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
void main0301()
{

	Complex c1(1, 2), c2(3, 4);
	//1  成员函数法 实现 + 运算符重载

	Complex c3 = c1 + c2;	//4 + 6i
	c3.printCom();
	//Complex	coperator +(Complex &c1, Complex &c2)
	//2   成员函数方法 实现 + 运算符 重载
	//c1.operator-(this,c2)
	//Complex operator-(Complex &c2)

	Complex c4 = c1 - c2;	//-2 + -2i
	c4.printCom();			

	//前置 ++操作符 用成员函数实现
	++c1;
	c1.printCom();			//2 + 3i

	//前置 ++操作符 用成员函数实现
	--c1;
	c1.printCom();		//1 +2i

	//后置 ++操作符 用成员函数实现
	c1++;	
	c1.printCom();		//2 + 3i

	//后置 --操作符 用成员函数实现
	c1--;
	c1.printCom();		//1 + 2i
	//c1.operator--()
	//Complex operator--();

	//Complex operator++ (Complex c1);
	//c1.operator--();
	//Complex &operator--();
	//Complex operator++(Complex &c1);
	cout << "hello world" << endl;
	system("pause");
}
/*void operator<<(ostream &out, Complex c1)
{
	//返回他的自身
	out << c1.a << " + " << c1.b << "i" << endl;
}*/
ostream& operator<<(ostream &_out, const Complex &c1)
{
	//返回他的自身
	_out << c1.a << " + " << c1.b << "i" << endl;
	return _out;
}
void main0302()
{
	int a = 10;
	Complex c1(1, 2), c2(3, 4);
	cout << a << endl;	//按照数据类型
	// 1
	cout << c1 << "aaabbbb" << endl;
	//座椅运算符 结合顺序 从左到右
	//cout.operator<<(c1).operator<<("aabbcb");
	//void.operator<<("aabbcb");

	//2 ostream 中添加 成员函数
	//cout.operator<<(c1);
	//首先承认左移操作符 是一个函数名字
	//void operator<<(ostream &out,Complex c1);
	//cout.operator 拿不到 ostream 的源码 只能用友元函数的方法
	cout << "hello world" << endl;
	system("pause");
}
//针对：ostream & operator <<(ostream & os, const ClassType &object)
//说明几点：
//1.第一个形参为对ostream对象的引用，在该对象上将产生输出，ostream为非const，因为写入到流会改变流的状态；该形参是一个引用，因为不能复制ostream对象（在c++中定义的标准输入输出流类istream和ostream，其中拷贝构造函数和赋值操作符函数都被放置在了private部分，且只有声明，没有定义）。
//2.第二个形参一般应是对要输出的类类型的引用，该形参是一个引用以避免复制实参，减少一次拷贝；它设为const，因为输出一般不会改变该对象，设为const就可以用来输出const对象和非const对象。
//3.返回类型是一个ostream引用，它的值通常是输出操作符所操作的ostream对象，首先因为ostream对象不能复制，所以必须是引用；其次引用可以少一次拷贝，提高效率；最后，为了体现连续性，实现连续输出，达到用多个输出操作符操作一个ostream对象的效果，如果不是引用，程序返回的时候就会生成新的临时对象，也就是说，连续的两个 << 操作符实际上是针对不同对象的，这就好比cout << a << b; 与cout << a; cout << b; 的区别。
//PS : 重载赋值操作符，连续赋值可以不返回引用
//	 重载加法操作符，连续相加不能返回引用