#include<iostream>
using namespace std;

//构造中调用构造 是一种危险的行为
class MyTest
{
public:
	MyTest(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	MyTest(int a, int b)
	{
		this->a = a;
		this->b = b;
		MyTest(a, b, 100);
	}
	~MyTest()
	{
		printf("~MyTest:%d, %d, %d\n", a, b, c);
	}
protected:
private:
	int a;
	int b;
	int c;
public:
	int getC() const{ return c; }
	void setC(int val){ c = val; }
};
void main()
{
	MyTest t1(1, 2);
	printf("c:%d\n", t1.getC());//c 为什么是个乱码
	cout<<"hello world"<<endl;
	system("pause");
}