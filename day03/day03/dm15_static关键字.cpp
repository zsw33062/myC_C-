#include<iostream>
using namespace std;
class BB
{
public:
	int printC()
	{
		printf("c:%d\n",c);
		return 0;
	}
	int AddC()
	{
		c = c + 1;
		return 0;
	}
	static void getC()	//静态成员函数
	{
		printf("c:%d\n", c);
	//请问 在静态成员中，能调用普通成员属性 或者 普通成员函数吗？			

		// printf("a:%d\n", a);//错误	1	error C2597: 对非静态成员“BB::a”的非法引用	e:\users\zsw\documents\visual studio 2013\projects\day03\day03\dm15_static关键字.cpp	21	1	day03

	}
protected:
private:
	int a;
	int b;
	static int c;	//静态成员变量
};

//静态函数中 不能使用 普通成员变量 普通成员函数
int BB::c = 10;
void main1501()
{
	BB b1, b2, b3;
	b1.printC();	//10
	b2.AddC();		//11
	b3.printC();	//11

	//静态函数的调用方法
//	b3.getC;	//用对象
	BB::getC();	//类::


	cout<<"hello world"<<endl;
	system("pause");
}