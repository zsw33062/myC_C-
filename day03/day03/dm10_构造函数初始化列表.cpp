#include<iostream>
using namespace std;
class A
{
public:
	A(int _a)
	{
		a = _a;
		cout << "A�Ĺ��캯��" << "a:" << a << endl;
	}
	~A()
	{
		cout << "A����������" << "a:" << a << endl;
	}
protected:
private:
	int a;
};
//���캯���ĳ�ʼ���б�  ��� ����B������� һ��A�����A������˹��캯����
//���ݹ��캯���ĵ��ù���  д��A��Ĺ��캯�� ����Ҫ��;û�г�ʼ��A
//�µ��﷨
class B
{
public:
	B(int _b1, int _b2) :a1(1), a2(2)
	{

	}
	B(int _b1, int _b2, int m, int n) :a1(m), a2(n) , c(0)
	{
		b1 = _b1;
		b2 = _b2;
		cout << "B�Ĺ��캯��" << endl;

	}
	~B()
	{
		cout << "B����������" << endl;
	}
protected:
private:
	int b1;
	int b2;
	A a1;
	A a2;
	const int c;
};
//2 ��ִ�� ����϶���Ĺ��캯��
//�����϶����ж�������ն���˳�򣬶����ǳ�ʼ���б�˳��
//�����������͹��캯���ĵ���˳�� �෴

//3 ����϶���Ĺ���˳�� �붨���˳���й�ϵ�����ʼ���б��˳��û�й�ϵ
//4 ��ʼ���б� ���� �� const ���Ը�ֵ
void obj10play()
{
	//A a1(10);
	//B objB1(1,2);

	// 1 ��������
	B objB2(1, 2, 3, 4);
	// 2 ����˳��

	
}
void main101()
{


	obj10play();

	cout << "hello world" << endl;
	system("pause");
}