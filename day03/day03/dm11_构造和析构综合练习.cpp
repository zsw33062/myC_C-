//对象作函数参数
//1 研究拷贝构造
//2 研究构造函数，析构函数的调用顺序

//总结 构造和析构的调用顺序

#include<iostream>
using namespace std;
class ABCD
{
public:
	ABCD(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		printf("ABCD() construct,a:%d,b%d,c%d \n",this->a,this->b,this->c);
	}		
	~ABCD()
	{
		printf("~ABCD() construct,a:%d,b%d,c%d \n", this->a, this->b, this->c);
	}
	int getA()
	{
		return this->a;
	}
protected:											 
private:
	int a;
	int b;
	int c;
};
class MyE
{
public:
	MyE():abcd1(1, 2, 3), abcd2(4,5,6),m(100)
	{
		cout << "MyD()" << endl;
	}
	~MyE()
	{
		cout << "~MyD()" << endl;
	}
	MyE(const MyE &obj) :abcd1(7, 8, 9), abcd2(10, 11, 12), m(100)
	{
		printf("MyD(const MyD &obj)\n");
	}
protected:
public:
	ABCD abcd1;
	ABCD abcd2;
	const int m;
};
int doThing(MyE mye1)
{
	printf("doThing() my1.abcd1.a:%d\n", mye1.abcd1.getA());
	return 0;
}int run2()
{
	MyE myE;
	doThing(myE);//用实参初始化形参myE1 的拷贝构造函数
	return 0;
}
int run3()
{
	printf("run3 start..\n");
	//ABCD(400, 500, 600);//临时对象的生命周期 只存在于这一行

	 ABCD abcd = ABCD(100, 200, 300);//C++编译器已经优化了 不用调了
	//若想直接调用构造函数呢?
	//想调用构造函数对abcd 对象进行再复制，可以吗？
	//在构造函数里面调用另外一个构造函数，会有什么结结果？


	printf("run3 end\n");
	return 0;
}
void main111()
{
	//run2();
	run3();
	//1 2 3
	//4 5 6
	//myD
	//7 8 9
	//10 11 12
	//7
	//构造函数 执行完毕 开始析构
	//10 11 12
	//7 8 9
	//myD
	//4 5 6
	//1 2 3
	cout<<"hello world"<<endl;
	system("pause");
}