
#include<iostream>
using namespace std;

class F
{
public:
	int operator()(int a, int b)
	{
		return a*a + b*b;
	}
protected:
private:
};

class F2
{
public:
	int MemFunc(int a, int b)
	{
		return a*a + b*b;
	}
protected:
private:
};
void main()
{

	F f;
	f(2, 4);

	F2 f2;
	f2.MemFunc(2, 4);

	//operator()(int a,int b)
	cout<<"hello world"<<endl;
	system("pause");
}