#include<iostream>
using namespace std;
class Parent
{
public:
	Parent(int a = 0)
	{
		//this->a = a;
		//print();
	}
	virtual void print()
	{
		cout << " I am Father" << endl;
	}
	virtual void print2()
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
	//Child(int b = 0) :Parent(0)
	//{
	//	this->b = b;
	//	//print();
	//}
	Child(int a = 0, int b = 0) :Parent(a)
	{
		//this->b = b;
		//print();
	}
	virtual void print()
	{
		cout << " I am Child" << endl;
	}

protected:
private:
	int b;
};
void HowToPlay(Parent &base)
{
	base.print();

}
//һ��żȻ�ĳɹ�����Ȼ��ʧ��
//����
//��̬ ���ø���ָ�� ָ�� ������� �� ���� ����++����������ͬ�ĸ���
void main04()
{
	Child		*pC = NULL;
	Parent		*pP = NULL;

	Child array[] = { Child(1), Child(2), Child(3)};
	//����͸����ָ�벽�� ��һ��������
	//��̬ ���ø���ָ�� ָ�� ������� �� ���� ����++����������ͬ�ĸ���
	pP = array;
	pC = array;
	

	pP->print();//��̬����
	pC->print();

	pP++;
	pC++;
	pP->print();//��̬����
	pC->print();


	pP++;
	pC++;
	pP->print();//��̬����
	pC->print();

	cout<<"hello world"<<endl;
	system("pause");
}