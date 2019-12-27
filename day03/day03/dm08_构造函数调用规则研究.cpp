#include<iostream>
using namespace std;
void objplaymain();

class Test
{
public:
	
	void printP()
	{
		cout << "a:" << a << "  b:" << b << endl;
	}
	
protected:
private:
	int a;
	int b;
};
//第三种 调用时机
void printTest(Test t)
{
	;
}
//1和2

Test getTestObj()
{
	Test tmp(1);
	return tmp;
}

void TestNoName()
{
	Test myt1 = getTestObj(); //用匿名对象 初始化另外一个对象
	Test myt2(1);
	myt2 = getTestObj();	//用匿名对象 给 另一个对象 赋值 匿名对象 被析构
}
void main71()
{
	objplaymain(); 
	objplaymain72();
	cout << "hello..." << endl;
	system("pause");
}
void objplaymain()
{
	Test t1;
	//Test t2();  调用无参构造函数 的 错误的方法
	//t2.printP();
	Test t3(1);				//C++编译器自动的调用构造函数
	Test t4 = 4;			//C++编译器自动的调用构造函数
	Test t5 = Test(5);		//程序员手工的调用构造函数

	Test T6 = t1;
	cout << "hello world" << endl;
	system("pause");
}