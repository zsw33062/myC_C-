#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Student
{
	char name[64];
	int id;

}Student;

//typedef struct Teacher
//{
//	char name[64];
//	int id;
//	char *p;
//	char **p2;
//	Student s1;
//}Teacher;
//�ṹ���� ��һ���ṹ��

//typedef struct Teacher
//{
//	char name[64];
//	int id;
//	char *p;
//	char **p2;
//	Student s1;
//	Student *p3;
//}Teacher;
//�ṹ���� ��һ���ṹ��


//�ṹ���� ��һ���Լ����͵Ļ�����
//typedef struct AdvTeacher
//{
//	char name[64];
//	int id; 
//	struct AdvTeacher AdvTeacher;	//�ݹ��Լ� ʼ���޷�ȷ�� �ڴ�
//	//���� 1 error C2079: ��AdvTeacher��ʹ��δ����� struct��AdvTeacher��	
//
//}AdvTeacher; ////���Լ� ���ʹ�С ��û�� ȷ��������� ���� �����͵�Ԫ�� �ǲ���ȷ��
//			//�ṹ�岻��Ƕ�׶��壨ȷ������ �������͵��ڴ��С�����䲻�� �ڴ棩

//typedef struct AdvTeacher2
//{
//	char name[64];
//	int id;
//	struct AdvTeacher2 *p2;	//��Ҫ ���� struct
//}AdvTeacher2;			//C ������ �ܼ�����ڴ� �Ĵ�С
// վ�� �ڴ� ������˼������
 
//������Ƕ�׵��� �� �ṹ�������͵�Ƕ�׶��� ��һ��
void main0101()
{	
	//Teacher t1;
	printf("hello...\n");
	system("pause");
}
