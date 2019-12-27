#include<iostream>
#include <cstdlib>

using namespace std;
class Test
{
public:
	int i;
public:
	Test(int i)
	{
		this->i = i;
	}
	Test operator+(const Test&obj)
	{
		Test ret(0);
		cout << "执行 + 号重载函数" << endl;
		ret.i = obj.i;
		return ret;
	}
	bool operator&&(const Test& obj)
	{
		cout << "执行 && 重载函数" << endl;
		return i&&obj.i;
	}
protected:
private:
	//int i;
};
//&& 从左向右
void main0701()
{
	int a1 = 0;
	int a2 = 1;

	cout << "注意：&&操作符的结合顺序是从左向右" << endl;

	if (a1 && (a1 + a2))
	{
		cout << "有一个是假，则不再执行下一个表达式的计算" << endl;
	}

	Test t1 = 0;
	Test t2 = 1;

	//if (t1 && (t1 + t2))
	//{
	//	//t1.operator&&(t1.operator+(t2))
	//	cout << "两个函数都被指向了，而且是先执行了 + " << endl;
	//}
	//1   && || 重载他们 不会产生 短路效果
	if ((t1 + t2) && t1)
	{
		//t1.operator&&(t1.operator+(t2))
		cout << "两个函数都被指向了，而且是先执行了 + " << endl;
	}
	//2   &&  运算符的结核性
	//当两个 逻辑与 在一起的时候，才去谈运算符的结和性
	//从左到右
	//if ((t1 + t2) && t1 && t2)
	{
		//t1.operator&&(t1.operator+(t2))
		cout << "两个函数都被指向了，而且是先执行了 + " << endl;
	}

	cout<<"hello world"<<endl;
	system("pause");
}