#include<iostream>
using namespace std;



class Test3
{
public:
	void init(int _a, int _b)
	{
		_a = a;
		_b = b;
	}
	Test3();
	~Test3();

private:
	int a;
	int b;

};

Test3::Test3()
{
}

Test3::~Test3()
{
}
void main31()
{
	Test3 t1;//类没有提供构造函数，C++编译器会自动给你提供一个默认的构造函数
			//类没有提供构造函数 copy构造函数，C++编译器会自动给程序员提供一个 默认的copy 构造函数 =
	int a = 10;
	int b = 20;
	t1.init(a, b);
	Test3 t21;
	Test3 t22;
	Test3 t23;
	//在这种场景之下 显示的初始化方案 显得很蹩脚

	Test3 tArray2[3] = { t21, t22, t23 };

	//在这种场景之下 满足不了  编程需要

//	Test3 tArray2[1999] = { t21, t22, t23 };

	//Test3 tArray[3];

	
	/*tArray[0].init(1, 2);
	tArray[1].init(1, 2);
	tArray[2].init(1, 2);*/
	cout<<"hello world"<<endl;
	system("pause");
}