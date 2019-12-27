#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "MyString.h"

void main01()
{
	MyString s1;
	MyString s2("s2");
	MyString s2_2 = NULL;
	MyString s3 = s2;
	MyString s4 = "s4444444444";

	s4 = s2;
	s4="s2222";
	s4[1] = '4';
	printf("s4:%c\n",s4[1]);
	cout << s4 << endl;
	//ostream& operator<<(ostream &out, MySring &s)
	//s4[0];
	//char& operator[](int index) 
	//MySring&operator=(const char *p);
	//MySring&operator=(const MySring& s);

	//测试运算符重载 和 重载 []
	//=
	cout << "hello world" << endl;
	system("pause");
}
void main02()
{
	MyString s1;
	MyString s2("s2");

	MyString s3 = s2;

	//bool operator==(const char *p);
	//bool operator==(const MySring& p);
	//bool operator!=(const char *p);
	//bool operator!=(const MySring& p);
	if (s2 == "s2222222")
	{
		printf("相等\n");
	}
	else
	{
		printf("不相等\n");
	}

	if (s3 == s2)
	{
		printf("相等\n");
	}
	else
	{
		printf("不相等\n");
	}
}
void main03()
{
	MyString s1;
	MyString s2("s2");

	MyString s3 = s2;
	s3 = "aaa";

	//int operator() < (const char *p);
	//int operator() > (const char *p);
	//int operator() < (const MyString &s);
	//int operator() > (const MyString &s);
	int tag = (s3<"bbbb");
	if (tag < 0)
	{
		printf("s3小于bbbb\n");
	} 
	else
	{
		printf("s3大于bbbb\n");
	}
	/*if (s3 < s2)
	{
	printf("s3小于s2\n");
	}
	else
	{
	printf("s3大于s2\n");
	}*/
	MyString s4 = "aaaaffff";
	strcpy(s4.c_str(), "aa111");//MFC 框架
	cout << s4 << endl;
}
void main()
{
	MyString s1(128);
	cout << "\n请输入字符串（回车结束）\n" << endl;
	//重载 >> 操作符
	//istream operator>>(istream& in, MyString &s);
	cin >> s1;
	cout << endl; 
	cout << s1;
	system("pause");
}