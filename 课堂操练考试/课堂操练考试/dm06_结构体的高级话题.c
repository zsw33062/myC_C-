#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//一旦结构体定义下来  则结构体中的成员..  内存布局 就定下来了
//可以通过age 地址 去求  大的结构体的内存地址

typedef struct TeahcerAdv
{
	char name[64];			//64
	int age;				//4
	int p;					//4
	char *pname2;			//4

}TeahcerAdv;



void main61()
{
	TeahcerAdv t1;
	TeahcerAdv *p=NULL;
	p = &t1;
	//printf("size:%d\n", sizeof(TeahcerAdv));
	//strcpy(p, "dddd");
	//p - 1;		// 编译通过 运行 也没问题
	////这句话呢在cpu 中计算
	//p - 2;
	//p - 3;
	//p - p;
	//p - (p + p);  指针之间 是 指针和指针  不能相加 相乘 
	


	{
		int offsize1 = (int)&(p->age);
		int offsize2 = (int)&(p->age);
		printf("(int)&(p->age):%d\n", offsize1);
	}


	printf("hello...\n");
	system("pause");
}
void main()
{
	TeahcerAdv t1;		//&(t1.age)  的地址
	TeahcerAdv *p = NULL;
	p = &t1;
	//printf("size:%d\n", sizeof(TeahcerAdv));
	//strcpy(p, "dddd");
	//p - 1;		// 编译通过 运行 也没问题
	//这句话呢在cpu 中计算
	//p - 2;
	//p - 3;

	//p - p;
	{
		int offsize1 = (int)p - (int)&(p->age);
		int offsize2 = (int)&(((TeahcerAdv *)0)->age);
		//p - (p + p);  指针之间 是 指针和指针  不能相加 相乘 
		//	int offsize = (int)&((p)->pname2);
		printf("offsize1:%d\n", offsize1);
		printf("offsize2:%d\n", offsize2);
	}


	printf("hello...\n");
	system("pause");
}