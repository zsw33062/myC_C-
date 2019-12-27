#include<iostream>
using namespace std;


class programmer
{
public:
	virtual void getSal() = 0;
protected:
private:
};
class junior_progammar : public programmer
{
public:
	junior_progammar(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()// = 0;//函数声明 改 函数事项
	{
		cout << name << " " << job << " " << sal << endl;
	}
protected:
private:
	char *name;
	char *job;
	int  sal;
};
class mid_progammar : public programmer
{
public:
	mid_progammar(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()// = 0;//函数声明 改 函数事项
	{
		cout << name << " " << job << " " << sal << endl;
	}
protected:
private:
	char *name;
	char *job;
	int  sal;
};
class adv_progammar : public programmer
{
public:
	adv_progammar(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()// = 0;//函数声明 改 函数事项
	{
		cout << name << " " << job << " " << sal << endl;
	}
protected:
private:
	char *name;
	char *job;
	int  sal;
};

class architect : public programmer
{
public:
	architect(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()// = 0;//函数声明 改 函数事项
	{
		cout << name << " " << job << " " << sal << endl;
	}
protected:
private:
	char *name;
	char *job;
	int  sal;
};

//计算函数 简单的框架
void CalProgSal(programmer *base)
{
	base->getSal();
}
void main0801()
{
	junior_progammar jp("小王","初级",8600);

	mid_progammar mp("小张","中级",8600);

	adv_progammar ap("小李","高级",15000);

	//系统扩展
	architect ar("高水平学院","架构师",24000);

	CalProgSal(&jp);
	CalProgSal(&mp);
	CalProgSal(&ap);
	CalProgSal(&ar);


	cout<<"hello world"<<endl;
	system("pause");
}