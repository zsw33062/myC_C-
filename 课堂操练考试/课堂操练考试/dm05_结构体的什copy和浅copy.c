#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct TeahcerAdv
{
	char name[64];
	int age;
	char *pname2;

}TeahcerAdv;


//编译器的 = 号操作只会把指针变量的值，从from拷贝到to 
//但不会  把指针变量 所指的内存空间拷贝过去


//结构体中 套一个 一级指针 或  二级指针

//如果想 执行深拷贝 显式的分配内存
void copyTeacher(TeahcerAdv *to, TeahcerAdv *from)
{
	//*to = *from;								//浅拷贝
	memcpy(to, from, sizeof(TeahcerAdv));			//浅拷贝
	to->pname2 = (char *)malloc(100);
	strcpy(to->pname2, from->pname2);
	
}
void main0501()
{	
	TeahcerAdv t1;
	TeahcerAdv t2;
	strcpy(t1.name, "name1");
	t1.pname2 = (char *)malloc(100);
//	t2.pname2 = (char *)malloc(100);
	strcpy(t1.pname2, "ssss");
	
	//t1 copy t2
	copyTeacher(&t2, &t1);

	if (t1.pname2!=NULL)
	{
		free(t1.pname2);
		t1.pname2 = NULL; 
	}
	if (t2.pname2 != NULL)
	{
		free(t2.pname2);		//在这里出问题 down 掉了
		t2.pname2 = NULL;
	}
	printf("hello...\n");
	system("pause");
}
