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
	//1 const д��ʲôλ�� û�й�ϵ
	//2 const ���ε���˭
	//2-1 const ���ε����β�a
	//2-2 const ���ε�������this->a this->b
	//2-3 const ���ε�������thisָ����ָ����ڴ�ռ�
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