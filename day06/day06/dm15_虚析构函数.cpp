#include<iostream>
using namespace std;
//����������
class A
{
public:
	A()
	{
		p = new char[20];
		strcpy(p, "obja");
		printf("A()\n");
	}
	/*virtual*/  ~A()
	{
		delete [] p;
		printf("~A()\n");
	}
protected:
private:
	char *p;
};
class B :public A
{
public:
	B()
	{
		p = new char[20];
		strcpy(p, "objb");
		printf("B()\n");
	}
	/*virtual*/ ~B()
	{
		printf("~B()\n");
		delete[] p;
	}
protected:
private:
	char *p;
};
class C :public B
{
public:
	C()
	{
		p = new char[20];
		strcpy(p, "objc");
		printf("C()\n");
	}
	/*virtual*/ ~C()
	{
		printf("~C()\n");
		delete[] p;
	}
protected:
private:
	char *p;
}; 
//ִֻ���˸������������
//��ͨ������ָ�� �� ���е����������������� ��ִ��һ��
void howToDelete(A *base)
{
	delete base;	//��仰������ֳ� ��̬��������
}
void main()
{
	
	C *myC = new C;//new delete ƥ��
	//howToDelete(myC);
	delete myC;		//ֱ��ͨ����������ͷ���Դ ����Ҫдvirtual
	cout<<"hello world"<<endl;
	system("pause");
}