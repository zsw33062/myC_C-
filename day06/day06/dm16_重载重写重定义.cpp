#include<iostream>
using namespace std;

//��д ���� �ض���
//��д������2����֮��
//���ر�����һ����֮��

//��д��Ϊ2��
//1 �麯����д ��������̬
//2 ���麯����д ���ض��壩


class Parent
{
	//�����������������ع�ϵ
public:
	void abc()
	{
		printf("abc\n");
	}
	/*virtual void abc()
	{
		cout << "abc do" << endl;
	}*/
	virtual void func()
	{
		cout << "func() do..." << endl;
	}
	virtual void func(int i)
	{
		cout << "func() do..." << i << endl;
	}

	virtual void func(int i, int j,int m,int n)
	{
		cout << "func() do...m n" << i << j << endl;
	}
protected:
private:
};
class Child :public Parent
{
	//����
public:
	void abc()
	{
		printf("child abc\n");
	}
	virtual void abc(int a)
	{
	cout << "abc do" << endl;
	}
	virtual void func(int i, int j)
	{
		cout << "fun(int i,int j) do..." << i << j << endl;
	}
	virtual void func(int i, int j,int k)
	{
		cout << "fun(int i,int j,int k) do..." << i << j << endl;
	}
protected:
private:
};
void main()
{
	//error C2661:"Child :: func":û�����غ��� ���� 0������
	Child c1;
	c1.Parent::fun(); 
	//c1.func()
	//�����޷����ظ���ĺ���������ͬ�������������Ƹ���

	//������ͬһ��֮��
	//1  C++������ ����func ���֣����������Ѿ������ˡ�����C++����ȥ�Ҹ����4��������func����
	//2  C++������ֻ���������У�����func �������ҵ�������func��һ����2�������ģ�һ����3��������
	//3  C++��������ʼ���� �������� error C2661����Child::func��:û�����غ�������4������
	//4   ������ø����func��ֻ�ܼ�ʢ���������.. ����ȥ����..
	c1.func(1,2,3,4);

	//c1.fun();
	//func ���������֣��������з��������Ƹ��ǣ�����ĺ��������֣�ռ���˸���ĺ��������ֵ�λ��
	//��Ϊ������������func���ֵ�������ʽ������
	//��������ʼ����������func����������������û��0��������func����
	cout<<"hello world"<<endl;
	system("pause");
}