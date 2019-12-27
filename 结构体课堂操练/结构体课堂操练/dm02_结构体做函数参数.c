#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;
void printTeacher(Teacher *array, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("age: %d\n", array[i].age);
	}
}
void sortTeacher(Teacher *array, int num)
{
	int i;
	int j;
	Teacher tmp;
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			//if (array[i]>array[j])
			if (array[i].age>array[j].age)
			{
				tmp = array[i];		//	= 号 操作 赋值操作
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}
//结构体 数组 3 输入老师的年龄 进行排序
//Teacher *creatTeacher(int num)
//{
//	Teacher *tmp = NULL;
//	tmp = (Teacher *)malloc(sizeof(Teacher)*num);	//Teacher  Array[3]
//	if (tmp==NULL)
//	{
//		return NULL;
//	}
//}
void main21()
{	
	int			i = 0;
	Teacher		Array[3];			//在stack 临时区分配内存
									//malloc  堆 动态 分配内存
	int num = sizeof(Array) / sizeof(Array[0]);

	for (i = 0; i < num; i++)
	{
		printf("please enter age:");
		scanf("%d", &(Array[i].age));
	}
	printf("**********************************\n");
	//打印 老师年龄
	for (i = 0; i < num; i++)
	{
		printf("age:%d  \n", (Array[i].age));
	}
	printf("**********************************\n");

	printTeacher(Array, num);

	sortTeacher(Array, num);
	printf("after sort:\n");

	printTeacher(Array, num);
	printf("hello...\n");
	system("pause");
}
Teacher *creatTeacher(int num)
{
	Teacher *tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher)*num);	//Teacher  Array[3]
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;
}
void FreeTeacher(Teacher *p)
{
	if (p != NULL)
	{
		free(p);
	}
}
void main0202()
{
	Teacher *pArray = NULL;
	Teacher		Array[3];
	int			i = 0;
	int num = sizeof(Array) / sizeof(Array[0]);
	pArray = creatTeacher(num);
	//int num = sizeof(Array) / sizeof(Array[0]);
	//int			num = 3;
		//在stack 临时区分配内存
	//malloc  堆 heap  动态 分配内存
	for (i = 0; i < num; i++)
	{
		printf("\nplease enter the age:");
		scanf("%d", &(pArray[i].age));
	}
	printTeacher(pArray, num);
	sortTeacher(pArray, num);
	printf("after the sort:\n");
	printTeacher(pArray, num);
	FreeTeacher(pArray);
	printf("hello...\n");
	system("pause");
}