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
	virtual void getSal()// = 0;//�������� �� ��������
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
	virtual void getSal()// = 0;//�������� �� ��������
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
	virtual void getSal()// = 0;//�������� �� ��������
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
	virtual void getSal()// = 0;//�������� �� ��������
	{
		cout << name << " " << job << " " << sal << endl;
	}
protected:
private:
	char *name;
	char *job;
	int  sal;
};

//���㺯�� �򵥵Ŀ��
void CalProgSal(programmer *base)
{
	base->getSal();
}
void main0801()
{
	junior_progammar jp("С��","����",8600);

	mid_progammar mp("С��","�м�",8600);

	adv_progammar ap("С��","�߼�",15000);

	//ϵͳ��չ
	architect ar("��ˮƽѧԺ","�ܹ�ʦ",24000);

	CalProgSal(&jp);
	CalProgSal(&mp);
	CalProgSal(&ap);
	CalProgSal(&ar);


	cout<<"hello world"<<endl;
	system("pause");
}