#include<iostream>
using namespace std;
class BB
{
public:
	int printC()
	{
		printf("c:%d\n",c);
		return 0;
	}
	int AddC()
	{
		c = c + 1;
		return 0;
	}
	static void getC()	//��̬��Ա����
	{
		printf("c:%d\n", c);
	//���� �ھ�̬��Ա�У��ܵ�����ͨ��Ա���� ���� ��ͨ��Ա������			

		// printf("a:%d\n", a);//����	1	error C2597: �ԷǾ�̬��Ա��BB::a���ķǷ�����	e:\users\zsw\documents\visual studio 2013\projects\day03\day03\dm15_static�ؼ���.cpp	21	1	day03

	}
protected:
private:
	int a;
	int b;
	static int c;	//��̬��Ա����
};

//��̬������ ����ʹ�� ��ͨ��Ա���� ��ͨ��Ա����
int BB::c = 10;
void main1501()
{
	BB b1, b2, b3;
	b1.printC();	//10
	b2.AddC();		//11
	b3.printC();	//11

	//��̬�����ĵ��÷���
//	b3.getC;	//�ö���
	BB::getC();	//��::


	cout<<"hello world"<<endl;
	system("pause");
}