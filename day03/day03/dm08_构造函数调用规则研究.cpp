#include<iostream>
using namespace std;
void objplaymain();

class Test
{
public:
	
	void printP()
	{
		cout << "a:" << a << "  b:" << b << endl;
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