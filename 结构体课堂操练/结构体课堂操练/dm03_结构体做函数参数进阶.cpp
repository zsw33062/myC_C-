#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Teacher
{
	char name[64];
	char *alisname;
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
int creatTeacher02(Teacher **pT, int num)
{
	Teacher *tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher)*num);	//Teacher  Array[3]
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0, sizeof(Teacher)*num);
	for (int i = 0; i < num;i++)
	{
		tmp[i].alisname = (char*)malloc(20);
	}
	
	*pT = tmp;	//二级指针 形参 去 间接的修改实参的值
	return 0;
}
void FreeTeacher(Teacher *p, int num)
{
	if (p == NULL)
	{
		return;
	}
	for (int i = 0; i < num; i++)
	{
		if (p[i].alisname != NULL)
			free(p[i].alisname);
	}
	free(p);
}
int  main0301()
{
	Teacher *pArray = NULL;
	Teacher		Array[3];
	int			i = 0;
	int			ret = 0;
	int num = sizeof(Array) / sizeof(Array[0]);
	creatTeacher02(&pArray, num);
	if (ret != 0)
	{
		printf("func create Teacher09() er\n");
		return ret;
	}
	for (i = 0; i < num; i++)
	{
		printf("\nplease enter the age:");
		scanf("%d", &(pArray[i].age));

		printf("\nplease enter the name:");
		scanf("%s", (pArray[i].name));		//向指针所指向的内存空间拷贝数据u

		printf("\nplease enter the alias:");
		scanf("%s", (pArray[i].alisname));	
	}
	printTeacher(pArray, num);
	sortTeacher(pArray, num);
	printf("after the sort:\n");
	printTeacher(pArray, num);
	FreeTeacher(pArray,num);
	printf("hello...\n");
	system("pause");
	return ret;
}