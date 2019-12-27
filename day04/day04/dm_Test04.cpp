#include<iostream>
using namespace std;
class Test
{
public:
	Test(int a, int b)//--->Test(Test *this,int a,int b)
	{
		this->a = a;
		this->b = b;
	}
	void printT()
	{
		cout << "a:" << a << endl;
		cout << "b:" << this->b << endl;
	}
	//1 const 写在什么位置 没有关系
	//2 const 修饰的是谁
	//2-1 const 修饰的是形参a
	//2-2 const 修饰的是属性this->a this->b
	//2-3 const 修饰的是属性this指针所指向的内存空间
	void  OpVar(int a, int b) const //==> void  OpVar(const Test *this,int a, int b) const
	{//==> void  OpVar(const Test *const  this,int a, int b) const
		a = 100;
		this->a = 100;
		this->a = 100;
		cout << "a:" << a << endl;
		cout << "b:" << this->b << endl;
	}
	
protected:
private:
	int a;
	int b;
};
void maint()
{
	Test t1(1, 2);
	t1.printT();//printT(&t1)
	cout << "hello world" << endl;
	system("pause");
}