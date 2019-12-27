#include<iostream>
using namespace std;
class Location
{
public:
	Location(int xx,int yy);
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
	cout << "Object destroyed." << endl;
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
void playobj()
{
	//�������������� ������������������
	Location a(1, 2);
	Location b = a;
	cout << "b  ���� �Ѿ���ʼ�����" << endl;
	//	cout << p.GetX() << endl;
	f(b);//b ʵ��ȡ��ʼ���β�p �����copy ���캯��
}

void main51()
{
	
	
	playobj();//b ʵ��ȡ��ʼ���β� p�������copy���캯��
	
	cout<<"hello world"<<endl;
	system("pause");
}