#include<iostream>
using namespace std;



class Test3
{
public:
	void init(int _a, int _b)
	{
		_a = a;
		_b = b;
	}
	Test3();
	~Test3();

private:
	int a;
	int b;

};

Test3::Test3()
{
}

Test3::~Test3()
{
}
void main31()
{
	Test3 t1;//��û���ṩ���캯����C++���������Զ������ṩһ��Ĭ�ϵĹ��캯��
			//��û���ṩ���캯�� copy���캯����C++���������Զ�������Ա�ṩһ�� Ĭ�ϵ�copy ���캯�� =
	int a = 10;
	int b = 20;
	t1.init(a, b);
	Test3 t21;
	Test3 t22;
	Test3 t23;
	//�����ֳ���֮�� ��ʾ�ĳ�ʼ������ �Եú�����

	Test3 tArray2[3] = { t21, t22, t23 };

	//�����ֳ���֮�� ���㲻��  �����Ҫ

//	Test3 tArray2[1999] = { t21, t22, t23 };

	//Test3 tArray[3];

	
	/*tArray[0].init(1, 2);
	tArray[1].init(1, 2);
	tArray[2].init(1, 2);*/
	cout<<"hello world"<<endl;
	system("pause");
}