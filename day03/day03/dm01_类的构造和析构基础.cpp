#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Test
{
public:
	Test()//�޲��� ���캯��
	{
		a=10;//���� ��� �����Եĳ�ʼ������
		p = (char *)malloc(100);
		strcpy(p, "aaaaaaf");
		cout << "���ǹ��캯�� ��ִ����" << endl;
	}
	void printP()
	{
		cout << p << endl;
		cout << a << endl;
	}
	~Test()//��������
	{
		if (p==NULL)
		{
			cout << "aaa";
			free(p);
		}
		cout << "������������ ��ִ����" << endl;
	}
protected:
private:
	int a;
	char *p;
};
//������һ����̨���о��������Ϊ
void objplay()
{
	Test t1;
	t1.printP();

	cout << "�ָ���"<<endl;

	Test t2;
	t2.printP();
}
//�ȴ����Ķ��� ���ͷ�
void main11()
{
	objplay();
	cout<<"hello world"<<endl;
	system("pause");
}