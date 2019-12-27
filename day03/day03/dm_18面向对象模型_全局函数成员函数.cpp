#include<iostream>
using namespace std;
class Test
{
public:
	int a;
	int b;
public:
	void printT()
	{
		cout << "a" << a << "  b:" << b << endl;
	}
public:
	Test(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	~Test()
	{
		
		cout << "a" << a << "  b:" << b ;
		cout << "析构函数自动被调用" << endl;
	}
public:
	//t3 = t1.TestAdd(t1);
	Test TestAdd(Test &t2)
	{
		Test tmp(this->a + t2.a, this->b + t2.b);
		return tmp;
	}
	//函数返回值 不是函数重载的一个标准
	//返回一个 引用 相当于返回 自身
	//返回t1 这个元素 this 就是&t1 的地址
	////t1=t1+t2;
	//t1.TestAdd2(t2);
	Test& TestAdd2(Test &t2)
	{
		this->a = this->a + t2.a;
		this->b = this->b + t2.b;


		return *this;  //把*（&t1） 又回到了t1 元素
	}
protected:
private:
};

//全局函数的方法
//全局函数 转成 成员函数 少了一个参数
Test TestAdd(Test &t1, Test &t2)
{
	Test tmp;
	return tmp;
}
//把成员函数 转成 全局函数多了一个参数
void printT(Test *pT)
{
	cout << "a" << pT->a << "  b:" << pT->b;
}
void main1801()
{
	Test t1(1, 2);
	Test t2(3, 4);
	Test t3;
	//全局函数方法

	t3 =  TestAdd(t1, t2);
	
	{//成员函数方法
		//先把测试案例写出来
		Test t4 = t1.TestAdd(t1);//匿名对象直接转化成t4
		t4.printT();
		Test t5;				//匿名对象复制给 t5
		t5 = t1.TestAdd(t2);
		t5.printT();
	}
	cout<<"hello world"<<endl;
	system("pause");
}
void main()
{
	Test t1(1, 2);
	Test t2(3, 4);

	//t1=t1+t2;
	t1.TestAdd2(t2);
	t1.printT();
	cout << "hello world" << endl;
	system("pause");
}