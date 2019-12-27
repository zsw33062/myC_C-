#include<iostream>

using namespace std;
class Test
{
public:
	Test(int a){ num = a; }
	~Test(){}
	void setNum(int a){ num = a; }
	int GetNum(){ return num; }
private:
	int num;
};
//值传递
void Add(Test t)
{
	int x = t.GetNum() + t.GetNum();//值传递，相当于为num创建一个副本值为100
	t.setNum(x);
	cout << t.GetNum() << endl;
}
int maintest

{
	Test tt(100);
	Add(tt);
	cout << tt.GetNum() << endl;//原对象的值没有变化，变化的是NUM的副本
	return 0;
}