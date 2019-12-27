
#include<iostream>
using namespace std;

class Complex
{
private:
	int a;
	int b;
	//ȫ�ֺ���  ���� + �����
	friend Complex	operator+(Complex &c1, Complex &c2);
	//���� ǰ��++
	friend Complex& operator++(Complex &c1);
	//���� ����++
	friend Complex operator++ (Complex c1, int);
	//friend Complex& operator--();
public:
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout << a << " + " << b << "i" << endl;
	}
	//��Ա���� ʵ�� - �����
	Complex operator-(Complex &c2)
	{
		Complex tmp(this->a-c2.a, this->b-c2.b);
		return tmp;
	}
	//��Ա���� ʵ�� -- �����
	//ǰ�� --
	Complex& operator--()
	{
		this->a--;
		this->b--;
		return *this;
	}
	//���� --
	Complex operator--(int)//ռλ��
	{
		Complex tmp = *this;
		this->a--;
		this->b--;
		return tmp;

	}
protected:
private:
};
Complex	operator + (Complex &c1, Complex &c2)
{
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}
//ǰ�� ++
Complex& operator++(Complex &c1)
{
	c1.a++;
	c1.b++;
	return c1;
}
//���� ++
Complex operator++ (Complex c1,int)
{
	//��ʹ�� �� ��c1�Ӽ�
	//return c1
	Complex tmp = c1;
	c1.a++;
	c1.b++;
	return tmp;
}
void main0201()
{

	Complex c1(1, 2), c2(3, 4);
	Complex c3 = c1 + c2;
	c3.printCom();
	//1  ȫ�ֺ����� ʵ�� + ���������
	//Complex	coperator +(Complex &c1, Complex &c2)
	//2   ��Ա�������� ʵ�� + ����� ����
	//c1.operator-(this,c2)
	//Complex operator-(Complex &c2)

	Complex c4 = c1 - c2;
	c4.printCom();

	//ǰ�� ++������ ��ȫ�ֺ���ʵ��
	++c1;
	c1.printCom();
	
	//ǰ�� ++������ �ó�Ա����ʵ��
	--c1;
	c1.printCom();
	
	//���� ++������ ��ȫ�ֺ���ʵ��
	c1++;
	c1.printCom();

	//���� --������ �ó�Ա����ʵ��
	c1--;
	c1.printCom();
	//c1.operator--()
	//Complex operator--();

	//Complex operator++ (Complex c1);
	//c1.operator--();
	//Complex &operator--();
	//Complex operator++(Complex &c1);
	cout << "hello world" << endl;
	system("pause");
}