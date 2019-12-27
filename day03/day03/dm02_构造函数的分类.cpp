#include<iostream>
using namespace std;
class Test4
{
public:
	Test4()
	{
		cout << "无参构造函数" << endl;
	}
	Test4(int a)
	{
		m_a = a;
		cout << "无参构造函数" << endl;
	}
	Test4(int a, int b)//有参构造函数	//3种
	{
		m_a = a;
		m_b = b;
	}
	//赋值构造函数（copy构造函数）
	Test4(const Test4&obj)
	{
		cout << "我也是构造函数" << endl;
	}
public:
	void printP()
	{
		cout << "普通成员函数"<<endl;
	}
protected:
private:
	int m_a;
	int m_b;
};
void main21()
{
	Test4 t1;	//调用无参构造函数
	//1 括号法
	//Test2 t1(12,2); //调用参数构造函数 C++编译器自动的调用构造函数
	//t1.printP();
	//
	//
	////2 =号法
	//Test2 t2 = (3, 4,5,6,7,8,9);//C++对等号 符增强 C++编译器自动的调用构造函数
	//Test2 t3 = 5;
	
	//3 直接调用构造函数
	Test4 t4 = Test4(1, 2);//匿名对象（匿名对象的去和留）抛转。。。
	t1 = t4;//把 t4 copy 给t1 //赋值操作
	//对象的初始化 和对象的赋值是两个不同的概念
	cout<<"hello world"<<endl;
	system("pause");
}