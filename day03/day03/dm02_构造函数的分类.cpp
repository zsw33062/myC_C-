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
	}
public:
	void printP()
	{
		cout << "��ͨ��Ա����"<<endl;
	}
protected:
private:
	int m_a;
	int m_b;
};
void main21()
{
	Test4 t1;	//�����޲ι��캯��
	//1 ���ŷ�
	//Test2 t1(12,2); //���ò������캯�� C++�������Զ��ĵ��ù��캯��
	//t1.printP();
	//
	//
	////2 =�ŷ�
	//Test2 t2 = (3, 4,5,6,7,8,9);//C++�ԵȺ� ����ǿ C++�������Զ��ĵ��ù��캯��
	//Test2 t3 = 5;
	
	//3 ֱ�ӵ��ù��캯��
	Test4 t4 = Test4(1, 2);//�����������������ȥ��������ת������
	t1 = t4;//�� t4 copy ��t1 //��ֵ����
	//����ĳ�ʼ�� �Ͷ���ĸ�ֵ��������ͬ�ĸ���
	cout<<"hello world"<<endl;
	system("pause");
}