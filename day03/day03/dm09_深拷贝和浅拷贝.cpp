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
	//解决方案：手工的编写拷贝构造函数 使用什拷贝
	Name(const Name &obj1)
	{
		m_len = obj1.m_len;
		m_p = (char *)malloc(m_len + 1);
		strcpy(m_p, obj1.m_p);
	}
	~Name()
	{
		if (m_p!=NULL)
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


//对象析构的时候 出现coredump
void objplaymain()
{
	Name obj1("abcdefg");
	
	//Name obj2 = obj1;//默认的copy构造函数 C++编译器给我们提供的

	Name obj3("obj3");
	obj3 = obj1;//等号操作
}
void main91()
{
	objplaymain();
	cout << "hello world" << endl;
	system("pause");
	return;
}