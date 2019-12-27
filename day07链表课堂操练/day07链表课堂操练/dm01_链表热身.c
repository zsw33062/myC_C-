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
//结构体中 套一个结构体

//typedef struct Teacher
//{
//	char name[64];
//	int id;
//	char *p;
//	char **p2;
//	Student s1;
//	Student *p3;
//}Teacher;
//结构体中 套一个结构体


//结构体中 套一个自己类型的机构提
//typedef struct AdvTeacher
//{
//	char name[64];
//	int id; 
//	struct AdvTeacher AdvTeacher;	//递归自己 始终无法确定 内存
//	//错误 1 error C2079: “AdvTeacher”使用未定义的 struct“AdvTeacher”	
//
//}AdvTeacher; ////在自己 类型大小 还没有 确定的情况下 引用 字类型的元素 是不正确的
//			//结构体不能嵌套定义（确定不了 数据类型的内存大小，分配不了 内存）

//typedef struct AdvTeacher2
//{
//	char name[64];
//	int id;
//	struct AdvTeacher2 *p2;	//需要 加上 struct
//}AdvTeacher2;			//C 编译器 能计算出内存 的大小
// 站在 内存 的问题思考问题
 
//函数的嵌套调用 和 结构数据类型的嵌套定义 不一样
void main0101()
{	
	//Teacher t1;
	printf("hello...\n");
	system("pause");
}
