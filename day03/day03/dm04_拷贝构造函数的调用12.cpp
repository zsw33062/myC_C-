#include<iostream>
using namespace std;
class Test4
{
public:
	Test4()
	{
		cout << "�޲ι��캯��" << endl;
	}
	Test4(int a)
	{
		m_a = a;
		cout << "�޲ι��캯��" << endl;
	}
	Test4(int a, int b)//�вι��캯��	//3��
	{
		m_a = a;
		m_b = b;
	}
	//��ֵ���캯����copy���캯����
	Test4(const Test4&obj)
	{
		cout << "��Ҳ�ǹ��캯��" << endl;
		m_b = obj.m_b + 100;
		m_a = obj.m_a + 100;
	}
public:
	void printP()
	{
		cout << "��ͨ��Ա����" << endl;
		cout << "m_a" << m_a << "m_b" << m_b << endl;
		
	}
protected:
private:
	int m_a;
	int m_b;
};
void main41()
{ 
	Test4 t1(1, 2);
	Test4 t0(1, 2);
	//Test4 t2 = t1;//��t1 ����ʼ��t2
	t0 = t1;	//��t1�� t0 ��ֵ  ���� �ͳ�ʼ�� ��������ͬ�ĸ���

	//��һ�ֵ��÷���
	Test4 t2 = t1;//��t1 ����ʼ��t2
	t2.printP();
	
	cout<<"hello world"<<endl;
	system("pause");
}
void main42()
{
	Test4 t1(1, 2);
	Test4 t0(1, 2);

	//��ֵ =�ȺŲ��� �᲻����ù��캯��
	//operator=()
	Test4 t2(t1);	//��t1���� ��ʼ�� t2 ����
	t2.printP();
	cout << "hello world" << endl;
	system("pause");
}