#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//����һ��������

//������һ���������� ���̶���С�ڴ�� �ı� ���� ��û�з����ڴ�

typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;
Teacher t2 = { "aaa", 12, 21 };
//�����Ͷ������ �ķ���
struct Student
{
	char name[64];
	int age;
}s1, s2;	//������ʵ�ʱ�� ͬʱ �������
struct Student2
{
	char name[64];
	int age;
}s5 = { "name", 21 };
struct 
{
	char name[64];
	int age;
}s11, s21;			//���� ���ͱ���

//��ʼ�����������ַ���

//������� Ȼ���ʼ��

//
void main0101()
{	
	struct Teacher t1;//����C ������ ���� �����ڴ�
	
//	Teacher  t101;	//����C ������ ���� �����ڴ�//1 ���� �������

	Teacher t2 = { "aaaa", 21, 01 };

	t1.age = 21;  //t1.age  " . "������ �Ǹ�ʲô�� ��û�� ������
							// ��Ѱַ���� ���� age �����t1 ����� ��ƫ����====������ ��cpu �� ����
							//û�в����ڴ�

	{
		Teacher *p = NULL;
		p = &t2;
		printf("p->age:%d\n", p->age);		// ->  ʵѰַ���� �� �� age �����t2�������ƫ���� ���� �� cpu �� ����
		printf("p->naem:%d", p->name);
	}
	strcpy(t1.name, "t1name");
	printf("%s\n", t1.name);
	printf("hello...\n");
	system("pause");
}
void copyTeacher(Teacher to, Teacher from)
{
	to = from;
}
void copyTeacher02(Teacher *to, Teacher *from)
{
	*to = *from;
}
void copyTeacher03(Teacher **to, Teacher *from)
{	
	//����ָ�� ��Ӹı� һ��ָ���ֵ
	(*to) = from;
}

void main0102()
{
	Teacher t1 = { "aaaa", 21, 01 };
	Teacher *pt1 = &t1;
	Teacher t2;
	Teacher t3;
	memset(&t3, 0, sizeof(t3));
	t2 = t1;	//	= �Ų����� ������ ����Ϊ

	//������ �ṩ�� �� �� = �Ÿ�ֵ ���� ���� Ҫ˳��
	/*printf("t2.name:%s\n", t2.name);
	printf("t2.age:%d\n", t2.age);
	printf("t2.id:%d\n", t2.id);

	copyTeacher(t3, t1);
	printf("copyTeacher after:\n");
	printf("t3.name:%s\n", t3.name);
	printf("t3.age:%d\n", t3.age);
	printf("t3.id:%d\n", t3.id);

	copyTeacher02(&t3, &t1);
	printf("copyTeacher02 after:\n");
	printf("t3.name:%s\n", t3.name);
	printf("t3.age:%d\n", t3.age);
	printf("t3.id:%d\n", t3.id);*/
	Teacher *pt31 = NULL;
	Teacher **pt32 = NULL;
	
	pt32 = &pt31;

	copyTeacher03(pt32, pt1);
	printf("copyTeacher03 after:\n");
	printf("pt3.name:%s\n", pt31->name);
	printf("pt3.age:%d\n", pt31->age);
	printf("pt3.id:%d\n", pt31->id);
	/*printf("pt3.name:%s\n", (*pt3)->name);
	printf("pt3.age:%d\n", (*pt3)->age);
	printf("pt3.id:%d\n", (*pt3)->id);*/
	printf("hello...\n");
	system("pause");
}