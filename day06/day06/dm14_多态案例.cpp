#include<iostream>
using namespace std;

// HeroFighter
//AdvHeroFighter
//EnemyFighter

class HeroFighter
{
public:
	virtual int power()
	{
		  return 10;
	}
protected:
private:
};
class EnemyFighter
{
public:
	int attack()
	{
		return 15;
	}
protected:
private:
};

class AdvHeroFighter:public HeroFighter
{
public:
	virtual int power()
	{
		return 20;
	}

protected:
private:
};

class AdvAdvHeroFighter :public HeroFighter
{
public:
	virtual int power()
	{
		return 30;
	}
};
//多态威力
//1 PlayObj给对象搭建舞台 看成一个框架
//多态的思想
//面向对象的3大概念
//封装：突破c函数的概念....用类做函数的时候,可以使用对象的属性 和方法
//继承：A B代码复用
//多态：可以使用未来

//多态很重要
//实现多态的三个条件
//C语言 间接赋值 是指针存在的最大意义
//是C语言的特有的现象（1 定义两个变量 2 建立关联 3 *p在被调用函数中去间接的修改实参的值）

//实现多态的三个条件
//1 要有继承
//2 要有虚函数重写
//3 用父类指针（父类引用）指向子类对象 ...
void PlayObj(HeroFighter *hf, EnemyFighter *ef)
{
	if (hf->power() > ef->attack())	//hf->power()函数调用会有多态发生
	{
		printf("猪脚win\n");
	}
	else
	{
		printf("猪脚挂掉\n");
	}
}

void main()
{
	HeroFighter hf;
	AdvHeroFighter Advhf;
	EnemyFighter ef;
	AdvAdvHeroFighter Advadvhf;

	PlayObj(&hf, &ef);
	PlayObj(&Advhf, &ef);
	PlayObj(&Advadvhf, &ef);

}
void main1401()
{
	HeroFighter hf;
	AdvHeroFighter Advhf;
	EnemyFighter ef;
	AdvAdvHeroFighter Advadvhf;
	

	if (hf.power()>ef.attack())
	{
		printf("猪脚win\n");
	} 
	else
	{
		printf("猪脚挂掉\n");
	}

	if (Advhf.power() > ef.attack())
	{
		printf("Adv 猪脚win\n");
	}
	else
	{
		printf("Adv 猪脚挂掉\n");
	}
	cout<<"hello world"<<endl;
	system("pause");
}