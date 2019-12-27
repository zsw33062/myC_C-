#include<iostream>
using namespace std;
class Location
{
public:
	Location(int xx, int yy);
	Location(const Location &obj);
	~Location();
public:
	int GetX();
	int GetY();

private:
	int X;
	int Y;

};

Location::Location(int xx = 0, int yy = 0)
{
	X = xx;
	Y = yy;
	cout << "Constructor Object." << endl;
}
//copy���캯�� ��ɶ���ĳ�ʼ��
Location::Location(const Location &obj)//
{
	X = obj.X;
	Y = obj.Y;
	//cout << "Object destroyed." << endl;
}
Location::~Location()
{
	cout << X << "," << Y << "  Object destroyed." << endl;
}
int Location::GetX()
{
	return X;
}
int Location::GetY()
{
	return Y;
}
//ҵ�� ����
void f(Location p)
{
	cout << p.GetX() << endl;
}
//����1�������� ����ֵ ��һ��Ԫ�أ��������͵ģ������ص���һ���µ������������Ի���������������copy���캯����
//���������ȥ����
//����ôд���룬��Ʊ������Ĵ�ţ��:
//�Ҿ͸��㷵��һ���¶���


//����2�� �й����������ȥ����
//������������� ��ʼ�� ��һ��ͬ���͵Ķ��� �������� ת����������
//������������� ��ֵ�� ��һ��ͬ���͵Ķ��� �������� ������
Location g()	//g ����  ����һ��Ԫ��
{
	Location A(1, 2);
	return A;
}
void objplay2()
{
	g();
}
void objplay4()
{
	//�����������ʼ��m����ʱC++������ ֱ�Ӱ���������ת��m��������  ������ת���������� m
	Location m2(1, 2);
	m2 = g();
	printf("��Ϊ����������=��m2�������������� \n");
	cout << m2.GetX() << endl;
}
void main61()
{
	//objplay2();
	//objplay3();
	objplay4();
	cout<<"hello world"<<endl;
	system("pause");
}