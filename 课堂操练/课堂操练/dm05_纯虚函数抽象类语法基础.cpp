#include<iostream>
using namespace std;
//���ͳ����� ��̣�����һ�� Ԥ�ȶ���õĵĽӿڱ�̣�

//����ϡ����� ģ��Ļ���
class Figure	//������
{
	//Լ��һ��ͳһ�Ľ��棨�ӿڣ���������ʹ�ã����������ȥʵ��
public:
	virtual int getArea() = 0;	//���麯��
protected:
private:
};
class Circle : public Figure
{
public:
	Circle(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual int getArea()
	{
		cout << "Բ�ε����:" << 3.14*a*a << endl;
		return 0;
	}
protected:
private:
	int a;
	int b;
};
class Tri : public Figure
{
public:
	Tri(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual int getArea()
	{
		cout << "�����ε����:" <<a*b/2 << endl;
		return 0;
	}
protected:
private:
	int a;
	int b;
};
class Square : public Figure
{
public:
	Square(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual int getArea()
	{
		cout << "�ı��ε����:" << a*b << endl;
		return 0;
	}
protected:
private:
	int a;
	int b;
};
void objplay(Figure *base)
{
	base->getArea();
}
void main05()
{
	
	//Figure f;//�����಻�ܱ�ʵ����
	Figure *base = NULL;
	//objplay(base);
	Circle	c1(10, 20);
	Tri		t1(20, 30);
	Square	s1(30, 40);

	//���ͳ����� ��̣�����һ�� Ԥ�ȶ���õĵĽӿڱ�̣�
	objplay(&c1);
	objplay(&t1);
	objplay(&s1);

	//c1.getArea();
	cout<<"hello world"<<endl;
	system("pause");
}