#include<iostream>
using namespace std;
class test
{
public:
	test();
	~test();

private:

};

test::test()
{
}

test::~test()
{
}
class B
{
public:
	int b;
	B()
	{
		cout << "B构造函数执行" << endl;
	}
protected:
private:
};
class B1 :virtual  public B
{
public:
	int b1;
};
class B2 :  public B
{
public:
	int b2;
};
class C :public B1,public B2
{
public:
	int b2;
protected:
private:
};
void main1101()
{
	C c1;
	cout<<"hello world"<<endl;
	system("pause");
}
class D1
{
public:
	int k;
protected:
private:
};
class D2
{
public:
	int k;
protected:
private:
};
class E :virtual public  D1, virtual public D2
{
public:
	
private:

};

void main1102()
{
	E e1;
	/*e1.k;*/
	e1.D1::k = 100;
	e1.D2::k = 200;
	system("pause");
}
void main1104()
{
	cout <<"B:"<< sizeof(B) << endl;
	cout << "B1:"<<sizeof(B1) << endl;//加上virtual关键字 后，C++编译器会给变量偷偷的增加属性
	cout << "B2:"<<sizeof(B2) << endl;
	cout << "test:" << sizeof(test) << endl;
	//cout << sizeof(B) << endl;
	system("pause");
}