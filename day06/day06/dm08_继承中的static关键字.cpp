#include<iostream>
using namespace std;
class A
{

//���� ���캯��Ĭ����˽�е�
public:
	A()
	{
	cout << "A�Ĺ��캯��";
	}
public:
	static int a;
	int b;
public:
	void get()
	{
		cout << "b:" << b << endl;
	}
	void print()
	{
		cout << "AAAAA" << endl;
	}
protected:

private:

};
int A::a = 100;//��仰 ���Ǽ򵥵ı�����ֵ ����Ҫ���Ǹ���C++������
				//��Ҫ���ҷ����ڴ棬���ڼ̳����� �õ���a ��Ȼ�ᱨ��...
class B :private A
{
	/*B()
	{
	cout << "B�Ĺ��캯��" << endl;
	}*/
public: 
	int b;
	int c;
public:
	void get_child()
	{
		cout << "b:" << b << endl;
		cout << a << endl;
	}
	void print()
	{
		cout << "BBBBB" << endl;
	}
protected:
private:
};

//1  static �ؼ��� ���� ��������ʿ��ƹ���
//2  //��仰 ���Ǽ򵥵ı�����ֵ ����Ҫ���Ǹ���C++������
//��Ҫ���ҷ����ڴ棬���ڼ̳����� �õ���a ��Ȼ�ᱨ��...
//3 A������ӹ��캯�� A��Ĺ��캯���� A��Ĺ��캯�� ��˽�е�
//�������̳�ҪС��
//�������� UML
void main02()
{
	//A a1;
	//a1.print();
	
	//B b1;
	//b1.get_child();
	system("pause");
}
void main01()
{
	//B b1;
	//b1.a = 200;

	system("pause");
}
////ͬ����Ա����
//void main71()
//{
//	A a1;
//	B b1;
//	b1.b = 1;
//	b1.get_child();
//	b1.A::b = 100;//�޸ĸ����b
//	b1.B::b = 200;//�޸������b
//	//Ĭ������������
//	b1.get();
//	cout<<"hello world"<<endl;
//	system("pause");
//}