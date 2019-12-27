#include<iostream>
using namespace std;

class Parent1
{
public:
	Parent1(int a = 0)
	{
		this->a = a;
	}
	void print()
	{
		cout << " I am Father" << endl;
	}

protected:
private:
	int a;
};
class Parent2
{
public:
	Parent2(int a = 0)
	{
		this->a = a;
	}
	virtual void print() 
	{
		cout << " I am Father" << endl;
	}

protected:
private:
	int a;
};
void main02()
{
	printf("sizeof(Parent1):%d\n", sizeof(Parent1));
	printf("sizeof(Parent2):%d\n", sizeof(Parent2));
	cout<<"hello world"<<endl;
	system("pause");
}