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
		cout << "B���캯��ִ��" << endl;
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
	cout << "B1:"<<sizeof(B1) << endl;//����virtual�ؼ��� ��C++�������������͵͵����������
	cout << "B2:"<<sizeof(B2) << endl;
	cout << "test:" << sizeof(test) << endl;
	//cout << sizeof(B) << endl;
	system("pause");
}