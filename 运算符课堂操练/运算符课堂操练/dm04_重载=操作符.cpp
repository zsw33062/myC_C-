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
	Name& operator=(Name &obj1)//入门的都是这么写 0.0
	{
		//1  先把旧的 内存释放
		if (this->m_p != NULL)
		{
			delete[] m_p;
			m_len = 0;
		}
		//2   根据obj1分配内存大小
		this->m_len = obj1.m_len;
		this->m_p = new char[m_len + 1];

		//把obj1复制
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


//对象析构的时候 出现coredump
void objplaymain()
{
	Name obj1("abcdefg");

	Name obj2 = obj1;//默认的copy构造函数 C++编译器给我们提供的

	Name obj3("obj3");//浅拷贝

	/*obj3.operator=(obj1);
	operator=(Name &obj1)*/
	obj3 = obj1;//等号操作重载
	obj1 = obj2 = obj3;//等号操作符 自右向左
	//obj1 = void; 不支持链式编程
}
void main0401()
{
	objplaymain();
	cout << "hello world" << endl;
	system("pause");
	return;
}
//结论
//1  先释放旧的内存
//2	 返回一个引用
/*Name& operator=(Name &obj1)//入门的都是这么写 0.0
	{
	//1  先把旧的 内存释放
	if (this->m_p != NULL)
	{
	delete[] m_p;
	m_len = 0;
	}
	//2   根据obj1分配内存大小
	this->m_len = obj1.m_len;
	this->m_p = new char[m_len + 1];

	//把obj1复制
	strcpy(m_p, obj1.m_p);
	return *this;
	}*/
//3  