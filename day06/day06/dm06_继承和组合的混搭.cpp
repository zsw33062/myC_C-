#include<iostream>
using namespace std;
//�� ���ø��๹�캯�� �ٵ������๹�캯��
//������˳�� �͹����෴
class Object
{
public:
	Object(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "object���캯�� ִ��" << "a"  << a << " b" << b << endl;
	}
	~Object()
	{
		cout << "object����������" << endl;
	}
protected:
	int a;
	int b;
private:
};
class Parent :public Object
{
public:
	Parent(char *p) :Object(1,2)
 	{
		cout << "����Ĺ��캯�� " << p << endl;
	}
	~Parent()
	{
		cout << "�������Ĺ�����" << endl;
	}
	void printP(int a, int b)
	{		
		cout << "���ǵ� " << endl;
	}
protected:
	char *p;
};
class child :public Parent
{
public:
	child(char *p) :Parent(p), obj1(3, 4), obj2(5, 6)
	{
		this->myp = p;
		cout << "����Ĺ��캯�� " << myp << endl;
	}
	~child()
	{
		cout << "������������� " << myp << endl;
	}
	void printC()
	{
		cout << "���Ƕ���" << endl;
	}
protected:
	char *myp;
	Object obj1;
	Object obj2;

};

void objplay()
{
	child c1("�̳в���");
}
void main06()
{
	objplay();
	cout << "hello world" << endl;
	system("pause");
}