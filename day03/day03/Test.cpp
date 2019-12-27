#include <stdio.h>
#include <stdlib.h>
class Student
{
private:
	int age;
public:
	Student();
	Student(int);
	~Student();
	int Getage();
};
Student::Student(int a)
{
	age = a;
}
Student::Student()
{
	age = 0;
}
Student::~Student()
{
}
int Student::Getage()
{
	return age;
}
int maintest(void)
{
	Student a(12);
	printf("%d\n", a.Getage());
	system("pause");
	return 0;
}