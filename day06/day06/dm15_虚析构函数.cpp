#include<iostream>
using namespace std;
//虚析构函数
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
//只执行了父类的析构函数
//想通过父类指针 把 所有的子类对象的析构函数 都执行一遍
void howToDelete(A *base)
{
	delete base;	//这句话不会表现出 多态这种属性
}
void main()
{
	
	C *myC = new C;//new delete 匹配
	//howToDelete(myC);
	delete myC;		//直接通过子类对象释放资源 不需要写virtual
	cout<<"hello world"<<endl;
	system("pause");
}