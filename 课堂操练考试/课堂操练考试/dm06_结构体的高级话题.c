#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//һ���ṹ�嶨������  ��ṹ���еĳ�Ա..  �ڴ沼�� �Ͷ�������
//����ͨ��age ��ַ ȥ��  ��Ľṹ����ڴ��ַ

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
	//p - 1;		// ����ͨ�� ���� Ҳû����
	////��仰����cpu �м���
	//p - 2;
	//p - 3;
	//p - p;
	//p - (p + p);  ָ��֮�� �� ָ���ָ��  ������� ��� 
	


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
	TeahcerAdv t1;		//&(t1.age)  �ĵ�ַ
	TeahcerAdv *p = NULL;
	p = &t1;
	//printf("size:%d\n", sizeof(TeahcerAdv));
	//strcpy(p, "dddd");
	//p - 1;		// ����ͨ�� ���� Ҳû����
	//��仰����cpu �м���
	//p - 2;
	//p - 3;

	//p - p;
	{
		int offsize1 = (int)p - (int)&(p->age);
		int offsize2 = (int)&(((TeahcerAdv *)0)->age);
		//p - (p + p);  ָ��֮�� �� ָ���ָ��  ������� ��� 
		//	int offsize = (int)&((p)->pname2);
		printf("offsize1:%d\n", offsize1);
		printf("offsize2:%d\n", offsize2);
	}


	printf("hello...\n");
	system("pause");
}