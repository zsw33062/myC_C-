#include<iostream>
using namespace std;
//�� ���ø��๹�캯�� �ٵ������๹�캯��
//������˳�� �͹����෴
class Parent
{
public:
	Parent(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "���๹�캯��..." << endl;
	}
	~Parent()
	{
		cout << "������������..." << endl;
	}
	void printP(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "���ǵ�" << endl;
	}
private:
	int a;
	int b;

};
class child :public Parent
{
public:
	child(int a,int b,int c) :Parent(a,b)
	{
		this->c = c;
		cout << "����Ĺ��캯��" << endl;
	}
	~child()
	{
		cout << "�������������" << endl;
	}
protected:
private:
	int c;
};
//class child :public Parent
//{
//public:
//	child(int c)
//	{
//		this->c = c;
//	}
//	void printC()
//	{
//		cout << "���Ƕ���" << endl;
//	}
//protected:
//private:
//	int c;
//};
void playObj()
{
	child c1(1, 2, 3);
}
void main05()
{
	//child c1(1, 2, 3);
	playObj();
	cout<<"hello world"<<endl;
	system("pause");
}