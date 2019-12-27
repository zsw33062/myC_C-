#include<iostream>
using namespace std;
class C1
{
public:
	int i;
	int j;
	int k;
protected:
private:
};
class C2
{
public:
	int i;
	int j;
	int k;
	static int m;
public:
	int getK() const{ return k; }
	void setK(int val){ k = val;};

protected:
private:
};
struct S1
{
	int i;
	int j;
	int k;
};
struct S2
{
	int i;
	int j;
	int k;
	static int m;
};
void main1601()
{
	printf("c1:%d\n",sizeof(C1));
	printf("c2:%d\n", sizeof(C2));
	printf("s1:%d\n", sizeof(S1));
	printf("s2:%d\n", sizeof(S2));
	cout<<"hello world"<<endl;
	system("pause");
}