#include<iostream>
using namespace std;

// 1
// malloc free
//new delete操作符 C++ 的语法
// 2
//基础性变量 分配数组变量 分配对象
//3
// 
//分配基础类型
void main1401()
{
	//
	int *p1 = (int *)malloc(sizeof(int));
	*p1 = 10;
	delete p1;
	//free(p1);
	int *p2 = new int;
	*p2 = 20;
	free(p2);

	//
	int *p3 = new int(30);
	printf("*p3:%d\n", *p3);
	//delete p3;
	free(p3);
	cout << "hello world" << endl;
	system("pause");
}
void main1402()
{
	//C语言分配数组
	int *p1 = (int *)malloc(sizeof(int)* 10);//int array[10]
	p1[0] = 1;
	//free(p1);
	delete [] p1;
	//C++分配数组
	int *pArray = new int[10];
	pArray[1] = 2;
	//delete[] pArray;//数组不要把[] 忘记
	free(pArray);
	//char *pArray2 = new char[25];//char buf[25]
	//delete[] pArray2;

	cout << "hello world" << endl;
	system("pause");
}
class Test
{
public:
	Test(int _a)
	{
		cout << "构造函数执行" << endl;
		a = _a;
	}
	~Test()
	{
		cout << "析构函数执行" << endl;
	}
protected:
private:
	int a;
};
//分配对象 new delete 
//
//相同和不同的地方  new自动的调用类型的构造函数 
//delete 操作符 能执行类的析构函数

//malloc free 函数 C
//new delete 操作符号 C++的关键字
//结论：

//malloc 不会调用类的构造函数
//free 不会调用类的析构函数
void main1403()
{
	//C语言
	Test *pT1 = (Test *)malloc(sizeof(Test));
	//free(pT1);
	delete pT1;
	//C++
	Test *pT2 = new Test(10);
	//delete pT2;
	free(pT2);
	cout << "hello world" << endl;
	system("pause");
}