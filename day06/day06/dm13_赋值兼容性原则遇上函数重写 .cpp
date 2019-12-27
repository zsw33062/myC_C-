#include<iostream>
using namespace std;


class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
		cout << "Parent a:" << a << endl;
	}
	virtual void print()//virtual ����д�� virtual�������д�ɲ�д
						//һ��д�� ��Ŀ ��ʾ����ط��ж�̬
	{
		cout << "Parent ��ӡ" << a << endl;
	}
protected:
private:
	int a;
};
class Child :public Parent
{
public:
	Child(int b) :Parent(10)
	{
		this->b = b;
		cout << "Child b:" << b << endl;
	}
	virtual void print()
	{
		cout << "Child ��ӡ" << b << endl;
	}
protected:
private:
	int b;

};

void howToPrint(Parent *base)
{
	base->print();	//һ�ֵ������ �ж��ֱ�����̬...
}
void howToPrint2(Parent &base)
{
	base.print();
}
void main()
{
	Parent *base = NULL;
	Parent p1(20);
	Child c1(30);
	base = &p1;
	base->print();//ִ�и���Ĵ�ӡ����

	base=&c1;
	base->print();//ִ��˭�ĺ���

	{
		Parent base2 = p1;
		base2.print();

		Parent base3 = c1;//base3��c1�ı���
		base3.print();
	}
	//��������
	{
		cout << endl << endl;
		howToPrint(&p1);
		howToPrint(&c1);

		howToPrint2(p1);
		howToPrint2(c1);
	}
	cout<<"hello world"<<endl;
	system("pause");
}