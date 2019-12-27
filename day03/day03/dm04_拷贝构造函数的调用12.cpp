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
		m_b = obj.m_b + 100;
		m_a = obj.m_a + 100;
	}
public:
	void printP()
	{
		cout << "普通成员函数" << endl;
		cout << "m_a" << m_a << "m_b" << m_b << endl;
		
	}
protected:
private:
	int m_a;
	int m_b;
};
void main41()
{ 
	Test4 t1(1, 2);
	Test4 t0(1, 2);
	//Test4 t2 = t1;//用t1 来初始化t2
	t0 = t1;	//用t1给 t0 赋值  操作 和初始化 是两个不同的概念

	//第一种调用方法
	Test4 t2 = t1;//用t1 来初始化t2
	t2.printP();
	
	cout<<"hello world"<<endl;
	system("pause");
}
void main42()
{
	Test4 t1(1, 2);
	Test4 t0(1, 2);

	//赋值 =等号操作 会不会调用构造函数
	//operator=()
	Test4 t2(t1);	//用t1对象 初始化 t2 对象
	t2.printP();
	cout << "hello world" << endl;
	system("pause");
}