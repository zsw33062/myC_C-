#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
#include "MyString.h"
//cout<<s4<<endl;
//重载<<操作符
ostream& operator<<(ostream &out, MyString &s)
{
	out << s.m_p;
	return out;
}
//重载>>操作符
istream& operator>>(istream &in, MyString &s)
{
	in >> s.m_p;
	return in;
}
MyString::MyString(int len)
{
	if (len == 0)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, " ");
	}
	else
	{
		m_len = len;
		m_p = new char[m_len + 1];
		memset(m_p, 0, m_len);
		//strcpy(m_p," ");
	}
}
MyString::MyString(const char *p)
{
	if (p == NULL)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, " ");
	}
	else
	{
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy(m_p, p);
	}
}
//拷贝构造函数
//MySring s3 = s2;
MyString::MyString(const MyString &s)
{
	m_len = s.m_len;
	m_p = new char[m_len + 1];
	strcpy(m_p, s.m_p);
}
MyString::~MyString()
{
	if (m_p!=NULL)
	{
		delete[]m_p;
		m_p = NULL;
		m_len = 0;
	}
}
//s4="s2222"
MyString& MyString::operator=(const char *p)
{
	//1 旧内存释放掉
	if (this->m_p != NULL)
	{
		delete[]m_p;
		m_len = 0;
	} 
	//2 根据p 分配内存
	if (p == NULL)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, " ");
	}
	else
	{
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy(m_p, p);
	}
	return *this;
}
//s4=s2
MyString& MyString::operator=(const MyString& s)
{
	//1 旧内存释放掉
	if (this->m_p != NULL)
	{
		delete[]m_p;
		this->m_len = 0;
	}
	//2 根据s 分配内存
	
		m_len = s.m_len;
		m_p = new char[m_len + 1];
		strcpy(m_p, s.m_p);
		
		return *this;
}
char& MyString::operator[](int index)
{
	return m_p[index];
}

//if (s2 == "s222222");
bool MyString::operator==(const char *p) const
{
	if (p==NULL)
	{
		if (this->m_len == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	} 
	else
	{
		if (this->m_len==strlen(p))
		{
			strcmp(m_p, p);
		}
		else
		{
			return false;
		}
	}
	return true;
}
bool MyString::operator!=(const char *p) const
{
	return !(*this==p);
}
bool MyString::operator==(const MyString& s) const
{
	if (m_len!=s.m_len)
	{
		return false;
	}
	return !(strcmp(m_p, s.m_p));
}

bool MyString::operator!=(const MyString& s) const //const 修饰的是this 指针
{
	return !(*this == s);
}
//return *this返回的是当前对象的克隆或者本身
//（若返回类型为A， 则是克隆， 若返回类型为A&，
//则是本身 ）。return this返回当前对象的地址
//（指向当前对象的指针）

//if (s3 < "bbbb")
int MyString::operator < (const char *p)
{
	return strcmp(this->m_p,p);
}
int MyString::operator > (const char *p)
{
	return strcmp(p, this->m_p);
}
int MyString::operator < (const MyString &s)
{
	return strcmp(this->m_p, s.m_p);
}
int MyString::operator > (const MyString &s)
{
	return strcmp(s.m_p, this->m_p);
}
