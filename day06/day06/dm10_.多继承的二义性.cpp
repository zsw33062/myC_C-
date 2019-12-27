#include<iostream>
using namespace std;
class B
{
public:
	int b;
protected:
private:
};
class B1:virtual public B
{
public:
	int b1;
protected:
private:

};
class B2 :virtual public B
{
public:
	int b2;
protected:
private:

};
class C :public B1,public B2
{
public:
	int c;
protected:
private:

};
void main01()
{
	C c1;
	c1.b1 = 100;
	c1.b2 = 200;
	c1.c = 300;

	c1.b = 500;//集成的二义性 和 虚继承二义性
	cout<<"hello world"<<endl;
	system("pause");
}