#include<iostream>
using namespace std;

// 1
// malloc free
//new delete������ C++ ���﷨
// 2
//�����Ա��� ����������� �������
//3
// 
//�����������
void main1401()
{
	//
	int *p1 = (int *)malloc(sizeof(int));
	*p1 = 10;
	delete p1;
	//free(p1);
	int *p2 = new int;
	*p2 = 20;
	free(p2);

	//
	int *p3 = new int(30);
	printf("*p3:%d\n", *p3);
	//delete p3;
	free(p3);
	cout << "hello world" << endl;
	system("pause");
}
void main1402()
{
	//C���Է�������
	int *p1 = (int *)malloc(sizeof(int)* 10);//int array[10]
	p1[0] = 1;
	//free(p1);
	delete [] p1;
	//C++��������
	int *pArray = new int[10];
	pArray[1] = 2;
	//delete[] pArray;//���鲻Ҫ��[] ����
	free(pArray);
	//char *pArray2 = new char[25];//char buf[25]
	//delete[] pArray2;

	cout << "hello world" << endl;
	system("pause");
}
class Test
{
public:
	Test(int _a)
	{
		cout << "���캯��ִ��" << endl;
		a = _a;
	}
	~Test()
	{
		cout << "��������ִ��" << endl;
	}
protected:
private:
	int a;
};
//������� new delete 
//
//��ͬ�Ͳ�ͬ�ĵط�  new�Զ��ĵ������͵Ĺ��캯�� 
//delete ������ ��ִ�������������

//malloc free ���� C
//new delete �������� C++�Ĺؼ���
//���ۣ�

//malloc ���������Ĺ��캯��
//free ������������������
void main1403()
{
	//C����
	Test *pT1 = (Test *)malloc(sizeof(Test));
	//free(pT1);
	delete pT1;
	//C++
	Test *pT2 = new Test(10);
	//delete pT2;
	free(pT2);
	cout << "hello world" << endl;
	system("pause");
}