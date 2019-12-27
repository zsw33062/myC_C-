#include<iostream>

//ÑÏ½÷
using namespace std;
int test(int *test)
{
	*test = *test + 10;
	return 0;
}
void maintest()
{
	int a = 10;
	int *p = NULL;
	test(&a);
	free(p);
	free(p);
	printf("a:%d\n", a);
	
	cout<<"hello world"<<endl;
	system("pause");
}