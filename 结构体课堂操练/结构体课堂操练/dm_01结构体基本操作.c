#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//定义一个机构体

//定义了一个数据类型 ，固定大小内存块 的别 名， 还没有分配内存

typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;
Teacher t2 = { "aaa", 12, 21 };
//用类型定义变量 的方法
struct Student
{
	char name[64];
	int age;
}s1, s2;	//定义类词的时候 同时 定义变量
struct Student2
{
	char name[64];
	int age;
}s5 = { "name", 21 };
struct 
{
	char name[64];
	int age;
}s11, s21;			//匿名 类型变量

//初始化变量的三种方法

//定义变量 然后初始化

//
void main0101()
{	
	struct Teacher t1;//告诉C 编译器 给我 分配内存
	
//	Teacher  t101;	//告诉C 编译器 给我 分配内存//1 类型 定义变量

	Teacher t2 = { "aaaa", 21, 01 };

	t1.age = 21;  //t1.age  " . "操作符 是干什么的 有没有 操作符
							// 是寻址操作 计算 age 相对于t1 大变量 的偏移量====》计算 在cpu 中 进行
							//没有操作内存

	{
		Teacher *p = NULL;
		p = &t2;
		printf("p->age:%d\n", p->age);		// ->  实寻址操作 是 算 age 相对于t2大变量的偏移量 计算 在 cpu 中 进行
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
	//二级指针 间接改变 一级指针的值
	(*to) = from;
}

void main0102()
{
	Teacher t1 = { "aaaa", 21, 01 };
	Teacher *pt1 = &t1;
	Teacher t2;
	Teacher t3;
	memset(&t3, 0, sizeof(t3));
	t2 = t1;	//	= 号操作下 编译器 的行为

	//编译器 提供了 简单 的 = 号赋值 操作 我们 要顺从
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