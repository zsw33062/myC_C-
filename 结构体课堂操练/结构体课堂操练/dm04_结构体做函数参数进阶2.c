#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//"name 111"
//"name 222"
//"name 333"
typedef struct Teacher
{
	//char student[10][30];
	char name[64];
	char *alisname;
	char **stuname; 
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
	for (int i = 0; i < num; i++)
	{ 
		char **p= NULL;
		//malloc一级指针
		tmp[i].alisname = (char*)malloc(20);
		//二级指针的第三种内存模型
		
			p = (char **)malloc(3 * sizeof(char *));//打造二维内存	//3  *  120
			for (int j = 0; j < 3; j++)
			{
				p[/*i*/j] = (char *)malloc(120);
			}
			tmp[i].stuname = p; 
		
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
		//释放一级指针
		if (p[i].alisname != NULL)
			free(p[i].alisname);
	}
	//释放二级指针
	int i = 0;
	if (p[i].stuname != NULL)
	{
		char **myp = p[i].stuname;	//用myp 将p[i].stuname  接过来
		for (int j = 0; j < 3; j++)
		{
			if (p != NULL)
			{
				free(myp[j]);
			}
		}
		free(myp);
		p[i].stuname = NULL;
	}
	free(p);
}
int  main()
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

	//	printf("\nplease enter the name:");
	//	scanf("%s", (pArray[i].name));		//向指针所指向的内存空间拷贝数据u

		printf("\nplease enter the alias:");
		scanf("%s", (pArray[i].alisname));
		for (int j = 0; j < 3; j++)
		{
			printf("\nplease enter student name:");
			scanf("%s", pArray[i].stuname[j]);
		}
	}
	printTeacher(pArray, num);
	sortTeacher(pArray, num);
	printf("after the sort:\n");
	printTeacher(pArray, num);
	FreeTeacher(pArray, num);
	printf("hello...\n");
	system("pause");
	return ret;
}