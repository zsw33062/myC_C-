#include<iostream>
using namespace std;


//���캯���� �����麯���ܷ�����̬��
class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
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
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b = b;
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
void main03()
{
	Parent	p1;
	Child	c1;//����һ�� ������������������ �ڸ��๹�캯���� �����麯�� print
			//�ܷ�����̬��

	HowToPlay(p1);
	HowToPlay(c1);
	//c1.print();
	//1 Ҫ��ʼ�� c1.vptrָ�룬��ʼ���� �ֲ�
	//2 ��ִ�и���Ĺ��캯����ʱ�� ��c1.vptr ָ������麯����
	//	������Ĺ��캯�� ������Ϻ󣬻��c1.vptr ָ�� ������麯���� 
	//���ۣ����� ��c1.vptrָ��ֲ����
	cout<<"hello world"<<endl;
	system("pause");
}

