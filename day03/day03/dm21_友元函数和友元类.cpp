#include<iostream>
using namespace std;
class A
{
public:
	friend class B;//B���� A��ĺ����ѣ���B�п��Է���A���˽�г�Ա��˽�к���
	//������λ�� �� public privateû�й�ϵ
	friend void modifyA(A *pA,int _a);//����modifyA ���� A�ĺ�����
	A(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	int getA()
	{
		cout << "a: " << a << endl;
		return 0;
	}
protected:
private:
	int a;
	int b;
};
class B
{
public:
	void Set(int a)
	{
		Aobject.a = a;
	}
	void printB()
	{
		cout << "Aobject.a:" << Aobject.a << endl;
	}
protected:
private:
	A Aobject;
};

void modifyA(A *pA,int _a)
{
	pA->a = _a;
}
//Ϊʲô��� ��Ԫ����
//1  1.java --> 1.class(�ֽ���)  ==>������Ʒ���1.class�ҵ������ֱ���޸����˽�����ԡ�����
//������� ��Ϊһ�ֱ�׼������ jdk������sum���ɱ�׼ jdk ��api�������������� AOP
//AOP
//2  1.cpp==>
//Ԥ���� ���� ���� ���� ����gcc -e //gcc -s //gcc -
//gcc -o 1.exe 1.c
//��� ���� �ҡ��������ѡ�����
//3  ����һ�����š����� frien

void main()
{
	B b1;
	b1.Set(300);
	b1.printB();
	system("pause");
}
void main2101()
{
	A a1(1, 2);
	a1.getA();
	modifyA(&a1, 300);
	a1.getA();
	cout<<"hello world"<<endl;
	system("pause");
}