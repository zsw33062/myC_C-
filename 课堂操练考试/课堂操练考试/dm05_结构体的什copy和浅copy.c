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


//�������� = �Ų���ֻ���ָ�������ֵ����from������to 
//������  ��ָ����� ��ָ���ڴ�ռ俽����ȥ


//�ṹ���� ��һ�� һ��ָ�� ��  ����ָ��

//����� ִ����� ��ʽ�ķ����ڴ�
void copyTeacher(TeahcerAdv *to, TeahcerAdv *from)
{
	//*to = *from;								//ǳ����
	memcpy(to, from, sizeof(TeahcerAdv));			//ǳ����
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
		free(t2.pname2);		//����������� down ����
		t2.pname2 = NULL;
	}
	printf("hello...\n");
	system("pause");
}
