#include<iostream>
using namespace std;


class Parent
{
public:
	void printP()
	{
		cout << "���ǵ�" << endl;
	}
protected:
private:
	int a;
};
class Child : public Parent
{
public:
	void printC()
	{
		cout << "���Ƕ���" << endl;
	}
	

private:

};

//C++�������ǲ��ᱨ���
void howToPrint(Parent *base)
{
	base->printP();
}
void howToPrint2(Parent &base)
{
	base.printP();
}

void main04()
{
	Parent p1;
	p1.printP();
	Child c1;
	c1.printC();
	c1.printP();

	//��ֵ������ԭ��
	//1-2 ����ָ�루���ã� ָ���������
	Parent *p = NULL;
	p = &c1;
	p->printP();
	
	//1-2ָ������������

	howToPrint(&p1);
	howToPrint(&c1);

	//1-3����
	howToPrint2(p1);
	howToPrint2(c1);

	//�ڶ��㺬��
	//�����ø������ ��ʼ�� �������
	//�������һ������ĸ���
	Parent p3 = c1; 
	cout<<"hello world"<<endl;
	system("pause");
}