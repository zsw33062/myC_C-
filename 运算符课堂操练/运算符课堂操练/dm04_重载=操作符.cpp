#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Name
{
public:
	Name(const char *myp)
	{
		m_len = strlen(myp);
		m_p = (char *)malloc(m_len + 1);
		strcpy(m_p, myp);
	}
	//����������ֹ��ı�д�������캯�� ʹ��ʲ����
	Name(const Name &obj1)
	{
		m_len = obj1.m_len;
		m_p = (char *)malloc(m_len + 1);
		strcpy(m_p, obj1.m_p);
	}
	Name& operator=(Name &obj1)//���ŵĶ�����ôд 0.0
	{
		//1  �ȰѾɵ� �ڴ��ͷ�
		if (this->m_p != NULL)
		{
			delete[] m_p;
			m_len = 0;
		}
		//2   ����obj1�����ڴ��С
		this->m_len = obj1.m_len;
		this->m_p = new char[m_len + 1];

		//��obj1����
		strcpy(m_p, obj1.m_p);
		return *this;
	}
	~Name()
	{
		if (m_p != NULL)
		{
			free(m_p);
			m_p = NULL;
			m_len = 0;
		}
	}
protected:
private:
	char *m_p;
	int m_len;
};


//����������ʱ�� ����coredump
void objplaymain()
{
	Name obj1("abcdefg");

	Name obj2 = obj1;//Ĭ�ϵ�copy���캯�� C++�������������ṩ��

	Name obj3("obj3");//ǳ����

	/*obj3.operator=(obj1);
	operator=(Name &obj1)*/
	obj3 = obj1;//�ȺŲ�������
	obj1 = obj2 = obj3;//�ȺŲ����� ��������
	//obj1 = void; ��֧����ʽ���
}
void main0401()
{
	objplaymain();
	cout << "hello world" << endl;
	system("pause");
	return;
}
//����
//1  ���ͷžɵ��ڴ�
//2	 ����һ������
/*Name& operator=(Name &obj1)//���ŵĶ�����ôд 0.0
	{
	//1  �ȰѾɵ� �ڴ��ͷ�
	if (this->m_p != NULL)
	{
	delete[] m_p;
	m_len = 0;
	}
	//2   ����obj1�����ڴ��С
	this->m_len = obj1.m_len;
	this->m_p = new char[m_len + 1];

	//��obj1����
	strcpy(m_p, obj1.m_p);
	return *this;
	}*/
//3  