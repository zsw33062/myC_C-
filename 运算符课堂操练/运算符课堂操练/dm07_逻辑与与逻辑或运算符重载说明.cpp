#include<iostream>
#include <cstdlib>

using namespace std;
class Test
{
public:
	int i;
public:
	Test(int i)
	{
		this->i = i;
	}
	Test operator+(const Test&obj)
	{
		Test ret(0);
		cout << "ִ�� + �����غ���" << endl;
		ret.i = obj.i;
		return ret;
	}
	bool operator&&(const Test& obj)
	{
		cout << "ִ�� && ���غ���" << endl;
		return i&&obj.i;
	}
protected:
private:
	//int i;
};
//&& ��������
void main0701()
{
	int a1 = 0;
	int a2 = 1;

	cout << "ע�⣺&&�������Ľ��˳���Ǵ�������" << endl;

	if (a1 && (a1 + a2))
	{
		cout << "��һ���Ǽ٣�����ִ����һ�����ʽ�ļ���" << endl;
	}

	Test t1 = 0;
	Test t2 = 1;

	//if (t1 && (t1 + t2))
	//{
	//	//t1.operator&&(t1.operator+(t2))
	//	cout << "������������ָ���ˣ���������ִ���� + " << endl;
	//}
	//1   && || �������� ������� ��·Ч��
	if ((t1 + t2) && t1)
	{
		//t1.operator&&(t1.operator+(t2))
		cout << "������������ָ���ˣ���������ִ���� + " << endl;
	}
	//2   &&  ������Ľ����
	//������ �߼��� ��һ���ʱ�򣬲�ȥ̸������Ľ����
	//������
	//if ((t1 + t2) && t1 && t2)
	{
		//t1.operator&&(t1.operator+(t2))
		cout << "������������ָ���ˣ���������ִ���� + " << endl;
	}

	cout<<"hello world"<<endl;
	system("pause");
}