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
//��̬����
//1 PlayObj��������̨ ����һ�����
//��̬��˼��
//��������3�����
//��װ��ͻ��c�����ĸ���....������������ʱ��,����ʹ�ö�������� �ͷ���
//�̳У�A B���븴��
//��̬������ʹ��δ��

//��̬����Ҫ
//ʵ�ֶ�̬����������
//C���� ��Ӹ�ֵ ��ָ����ڵ��������
//��C���Ե����е�����1 ������������ 2 �������� 3 *p�ڱ����ú�����ȥ��ӵ��޸�ʵ�ε�ֵ��

//ʵ�ֶ�̬����������
//1 Ҫ�м̳�
//2 Ҫ���麯����д
//3 �ø���ָ�루�������ã�ָ��������� ...
void PlayObj(HeroFighter *hf, EnemyFighter *ef)
{
	if (hf->power() > ef->attack())	//hf->power()�������û��ж�̬����
	{
		printf("���win\n");
	}
	else
	{
		printf("��Źҵ�\n");
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
		printf("���win\n");
	} 
	else
	{
		printf("��Źҵ�\n");
	}

	if (Advhf.power() > ef.attack())
	{
		printf("Adv ���win\n");
	}
	else
	{
		printf("Adv ��Źҵ�\n");
	}
	cout<<"hello world"<<endl;
	system("pause");
}