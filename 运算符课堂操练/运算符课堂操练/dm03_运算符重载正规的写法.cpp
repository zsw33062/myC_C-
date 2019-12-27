
#include<iostream>
using namespace std;
//class ostream
//{
//public:
//protected:
//private:
//};
class Complex
{
private:
	int a;
	int b;
	//friend void operator<<(ostream &out, Complex c1);
	friend ostream& operator<<(ostream &out, const Complex &c1);
public:
	//ʵ�� + ����� ����
	Complex	operator + ( Complex &c2)
	{
		Complex tmp(this->a + c2.a, this->b + c2.b);
		return tmp;
	}
	//ǰ�� ++
	Complex& operator++()
	{
		this->a++;
		this->b++;
		return *this;
	}
	//���� ++
	Complex operator++ (int)
	{
		//��ʹ�� �� ��c1�Ӽ�
		//return c1
		Complex tmp = *this;
		this->a++;
		this->b++;
		return tmp;
	}
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
		Complex tmp(this->a - c2.a, this->b - c2.b);
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
void main0301()
{

	Complex c1(1, 2), c2(3, 4);
	//1  ��Ա������ ʵ�� + ���������

	Complex c3 = c1 + c2;	//4 + 6i
	c3.printCom();
	//Complex	coperator +(Complex &c1, Complex &c2)
	//2   ��Ա�������� ʵ�� + ����� ����
	//c1.operator-(this,c2)
	//Complex operator-(Complex &c2)

	Complex c4 = c1 - c2;	//-2 + -2i
	c4.printCom();			

	//ǰ�� ++������ �ó�Ա����ʵ��
	++c1;
	c1.printCom();			//2 + 3i

	//ǰ�� ++������ �ó�Ա����ʵ��
	--c1;
	c1.printCom();		//1 +2i

	//���� ++������ �ó�Ա����ʵ��
	c1++;	
	c1.printCom();		//2 + 3i

	//���� --������ �ó�Ա����ʵ��
	c1--;
	c1.printCom();		//1 + 2i
	//c1.operator--()
	//Complex operator--();

	//Complex operator++ (Complex c1);
	//c1.operator--();
	//Complex &operator--();
	//Complex operator++(Complex &c1);
	cout << "hello world" << endl;
	system("pause");
}
/*void operator<<(ostream &out, Complex c1)
{
	//������������
	out << c1.a << " + " << c1.b << "i" << endl;
}*/
ostream& operator<<(ostream &_out, const Complex &c1)
{
	//������������
	_out << c1.a << " + " << c1.b << "i" << endl;
	return _out;
}
void main0302()
{
	int a = 10;
	Complex c1(1, 2), c2(3, 4);
	cout << a << endl;	//������������
	// 1
	cout << c1 << "aaabbbb" << endl;
	//��������� ���˳�� ������
	//cout.operator<<(c1).operator<<("aabbcb");
	//void.operator<<("aabbcb");

	//2 ostream ����� ��Ա����
	//cout.operator<<(c1);
	//���ȳ������Ʋ����� ��һ����������
	//void operator<<(ostream &out,Complex c1);
	//cout.operator �ò��� ostream ��Դ�� ֻ������Ԫ�����ķ���
	cout << "hello world" << endl;
	system("pause");
}
//��ԣ�ostream & operator <<(ostream & os, const ClassType &object)
//˵�����㣺
//1.��һ���β�Ϊ��ostream��������ã��ڸö����Ͻ����������ostreamΪ��const����Ϊд�뵽����ı�����״̬�����β���һ�����ã���Ϊ���ܸ���ostream������c++�ж���ı�׼�����������istream��ostream�����п������캯���͸�ֵ����������������������private���֣���ֻ��������û�ж��壩��
//2.�ڶ����β�һ��Ӧ�Ƕ�Ҫ����������͵����ã����β���һ�������Ա��⸴��ʵ�Σ�����һ�ο���������Ϊconst����Ϊ���һ�㲻��ı�ö�����Ϊconst�Ϳ����������const����ͷ�const����
//3.����������һ��ostream���ã�����ֵͨ���������������������ostream����������Ϊostream�����ܸ��ƣ����Ա��������ã�������ÿ�����һ�ο��������Ч�ʣ����Ϊ�����������ԣ�ʵ������������ﵽ�ö���������������һ��ostream�����Ч��������������ã����򷵻ص�ʱ��ͻ������µ���ʱ����Ҳ����˵������������ << ������ʵ��������Բ�ͬ����ģ���ͺñ�cout << a << b; ��cout << a; cout << b; ������
//PS : ���ظ�ֵ��������������ֵ���Բ���������
//	 ���ؼӷ���������������Ӳ��ܷ�������