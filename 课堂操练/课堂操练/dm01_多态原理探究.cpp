#include<iostream>
using namespace std;
//��̬��������������
//Ҫ�м̳� �麯����д ����ָ��ָ���������

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}
	virtual void print() //1 ���ֽ� д virtual�ؼ��� �����⴦��  //�麯����
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
	}
	virtual void print()
	{
		cout << " I am Child" << endl;
	}

protected:
private:
	int b;
};
void HowToPlay(Parent *base)
{
	base->print();//���ж�̬����  //2 ���ֽ� 
	//�������� ���� ִ�������print ���� ���� ������� ִ�� �����print ����
	//C++������ ��������Ҫ ���� ��������� ���Ǹ������
	//������� �� ������� �ֱ���vptr ָ�룬==���麯����==����������ڵ�ַ
	//�ٰ� �����е�ʱ�� ��C++��������ȥ�жϣ�
}
void main01()
{
	
	Parent	p1;		//3 ���ֽ����� ��������ʱ�� C++������ ���ڶ����� ���һ��vptr ָ��
	Child	c1;		//�������� Ҳ��һ��vptr ָ��
	HowToPlay(&p1);
	HowToPlay(&c1);
	cout<<"hello world"<<endl;
	system("pause");
}