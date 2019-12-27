#include<iostream>
using namespace std;
#include "MyArray.h"

//类的框架设计完毕
//类的测试案例
void main()
{
	Array a1(10);
	for (int i = 0; i < a1.length(); i++)
	{
		a1.setData(i, i);
	}
	cout << "打印a1：" << endl;
	for (int i = 0; i < a1.length(); i++)
	{
		cout<<a1.getData(i)<<" ";
	}
	Array a2 = a1;
	cout << endl;
	cout << "打印a2："<<endl;
	for (int i = 0; i < a2.length(); i++)
	{
	cout << a2.getData(i) << " ";
	}
	cout << endl << "hello world" << endl;
	system("pause");
}