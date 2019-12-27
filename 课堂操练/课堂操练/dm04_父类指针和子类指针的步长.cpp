#include<iostream>
using namespace std;
class Parent
{
public:
	Parent(int a = 0)
	{
		//this->a = a;
		//print();
	}
	virtual void print()
	{
		cout << " I am Father" << endl;
	}
	virtual void print2()
	{
		cout << " I am Father" << endl;
	}


protected:
private:
	int a;
};
class Child : public Parent
{
public:
	//Child(int b = 0) :Parent(0)
	//{
	//	this->b = b;
	//	//print();
	//}
	Child(int a = 0, int b = 0) :Parent(a)
	{
		//this->b = b;
		//print();
	}
	virtual void print()
	{
		cout << " I am Child" << endl;
	}

protected:
private:
	int b;
};
void HowToPlay(Parent &base)
{
	base.print();

}
//一次偶然的成功，必然的失败
//结论
//多态 是用父类指针 指向 子类对象 和 父类 步长++，是两个不同的概念
void main04()
{
	Child		*pC = NULL;
	Parent		*pP = NULL;

	Child array[] = { Child(1), Child(2), Child(3)};
	//子类和父类的指针步长 不一样的问题
	//多态 是用父类指针 指向 子类对象 和 父类 步长++，是两个不同的概念
	pP = array;
	pC = array;
	

	pP->print();//多态发生
	pC->print();

	pP++;
	pC++;
	pP->print();//多态发生
	pC->print();


	pP++;
	pC++;
	pP->print();//多态发生
	pC->print();

	cout<<"hello world"<<endl;
	system("pause");
}