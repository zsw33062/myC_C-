#include<iostream>
using namespace std;

//�����е��ù��� ��һ��Σ�յ���Ϊ
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
	printf("c:%d\n", t1.getC());//c Ϊʲô�Ǹ�����
	cout<<"hello world"<<endl;
	system("pause");
}