#include<iostream>
using namespace std;
#include "MyArray.h"

//��Ŀ��������
//��Ĳ��԰���
void main()
{
	Array a1(10);
	for (int i = 0; i < a1.length(); i++)
	{
		a1.setData(i, i);
	}
	cout << "��ӡa1��" << endl;
	for (int i = 0; i < a1.length(); i++)
	{
		cout<<a1.getData(i)<<" ";
	}
	Array a2 = a1;
	cout << endl;
	cout << "��ӡa2��"<<endl;
	for (int i = 0; i < a2.length(); i++)
	{
	cout << a2.getData(i) << " ";
	}
	cout << endl << "hello world" << endl;
	system("pause");
}