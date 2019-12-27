#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Test
{
public:
	Test()//无参数 构造函数
	{
		a=10;//作用 完成 对属性的初始化工作
		p = (char *)malloc(100);
		strcpy(p, "aaaaaaf");
		cout << "我是构造函数 被执行了" << endl;
	}
	void printP()
	{
		cout << p << endl;
		cout << a << endl;
	}
	~Test()//析构函数
	{
		if (p==NULL)
		{
			cout << "aaa";
			free(p);
		}
		cout << "我是析构函数 被执行了" << endl;
	}
protected:
private:
	int a;
	char *p;
};
//给对象搭建一个舞台，研究对象的行为
void objplay()
{
	Test t1;
	t1.printP();

	cout << "分隔符"<<endl;

	Test t2;
	t2.printP();
}
//先创建的对象 后释放
void main11()
{
	objplay();
	cout<<"hello world"<<endl;
	system("pause");
}