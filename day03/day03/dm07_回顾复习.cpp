#include<iostream>
using namespace std;
void objplaymain();

class Test
{
public:
	Test()
	{
		a = 0;
		b = 1;
		cout << "�޲������캯�� �Զ�������" << endl;
	}
	Test(int _a)
	{
		a = _a;
		b = 0;
	}
	Test(const Test & obj)	//copy ���캫�� ���ã���һ�������ʼ����һ������
	{
		a = obj.a + 100;
		b = obj.b + 100;
	}
	void printP()
	{
		cout << "a:" << a << "  b:" << b << endl;
	}
	~Test()
	{
		cout << "������������ �����������ڽ���ʱ �ᱻC++�������Զ�����" << endl;
	}
protected:
private:
	int a;
	int b;
};
//������ ����ʱ��
void printTest(Test t)
{
	;
}
//1��2
void objplaymain72()
{
	//
	Test t1(1);	//ok
	Test t2(t1);
	Test t3 = t1;//�����copy ���캯��
	printTest(t3);
}//copy ���캯�������ֵ���ʱ��
//����һ��Ԫ�� ��������
Test getTestObj()
{
	Test tmp(1);
	return tmp;
}

void TestNoName()
{
	Test myt1 = getTestObj(); //���������� ��ʼ������һ������
	Test myt2(1);
	myt2 = getTestObj();	//���������� �� ��һ������ ��ֵ �������� ������
}
void main71()
{
	objplaymain();
	objplaymain72();
	cout << "hello..." << endl;
	system("pause");
}
void objplaymain()
{
	Test t1;
	//Test t2();  �����޲ι��캯�� �� ����ķ���
	//t2.printP();
	Test t3(1);				//C++�������Զ��ĵ��ù��캯��
	Test t4 = 4;			//C++�������Զ��ĵ��ù��캯��
	Test t5 = Test(5);		//����Ա�ֹ��ĵ��ù��캯��

	Test T6 = t1;
	cout << "hello world" << endl;
	system("pause");
}