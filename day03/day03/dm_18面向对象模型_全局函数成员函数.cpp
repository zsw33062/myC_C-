#include<iostream>
using namespace std;
class Test
{
public:
	int a;
	int b;
public:
	void printT()
	{
		cout << "a" << a << "  b:" << b << endl;
	}
public:
	Test(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	~Test()
	{
		
		cout << "a" << a << "  b:" << b ;
		cout << "���������Զ�������" << endl;
	}
public:
	//t3 = t1.TestAdd(t1);
	Test TestAdd(Test &t2)
	{
		Test tmp(this->a + t2.a, this->b + t2.b);
		return tmp;
	}
	//��������ֵ ���Ǻ������ص�һ����׼
	//����һ�� ���� �൱�ڷ��� ����
	//����t1 ���Ԫ�� this ����&t1 �ĵ�ַ
	////t1=t1+t2;
	//t1.TestAdd2(t2);
	Test& TestAdd2(Test &t2)
	{
		this->a = this->a + t2.a;
		this->b = this->b + t2.b;


		return *this;  //��*��&t1�� �ֻص���t1 Ԫ��
	}
protected:
private:
};

//ȫ�ֺ����ķ���
//ȫ�ֺ��� ת�� ��Ա���� ����һ������
Test TestAdd(Test &t1, Test &t2)
{
	Test tmp;
	return tmp;
}
//�ѳ�Ա���� ת�� ȫ�ֺ�������һ������
void printT(Test *pT)
{
	cout << "a" << pT->a << "  b:" << pT->b;
}
void main1801()
{
	Test t1(1, 2);
	Test t2(3, 4);
	Test t3;
	//ȫ�ֺ�������

	t3 =  TestAdd(t1, t2);
	
	{//��Ա��������
		//�ȰѲ��԰���д����
		Test t4 = t1.TestAdd(t1);//��������ֱ��ת����t4
		t4.printT();
		Test t5;				//���������Ƹ� t5
		t5 = t1.TestAdd(t2);
		t5.printT();
	}
	cout<<"hello world"<<endl;
	system("pause");
}
void main()
{
	Test t1(1, 2);
	Test t2(3, 4);

	//t1=t1+t2;
	t1.TestAdd2(t2);
	t1.printT();
	cout << "hello world" << endl;
	system("pause");
}