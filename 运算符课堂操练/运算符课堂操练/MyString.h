#include<iostream>
using namespace std;
//c中没有字符串 字符串类（c风格的字符串）
//空串
class MyString
{
	friend ostream& operator<<(ostream &out, MyString &s);
	friend istream& operator>>(istream& in, MyString &s);
public:
	MyString(int len = 0);
	MyString(const char *p);
	MyString(const MyString &s);
	~MyString();
public:
	//重载 = 操作符
	MyString&operator=(const char *p);
	MyString&operator=(const MyString& s);
	char& operator[](int index);
public://重载 == 和 ！= 操作符
	bool operator==(const char *p) const;
	bool operator==(const MyString& p) const;
	bool operator!=(const char *p) const;
	bool operator!=(const MyString& p) const;
public:
	int operator < (const char *p);
	int operator > (const char *p);
	int operator < (const MyString &s);
	int operator > (const MyString &s);
public:
	//把类的指针 漏出来
	char *c_str()
	{
		return m_p;
	}
	const char *c_str2()
	{
		return m_p;
	}
	int length()
	{
		return m_len;
	}
public:
private:
	int m_len;
	char *m_p;
};