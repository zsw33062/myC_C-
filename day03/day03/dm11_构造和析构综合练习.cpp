//��������������
//1 �о���������
//2 �о����캯�������������ĵ���˳��

//�ܽ� ����������ĵ���˳��

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
	doThing(myE);//��ʵ�γ�ʼ���β�myE1 �Ŀ������캯��
	return 0;
}
int run3()
{
	printf("run3 start..\n");
	//ABCD(400, 500, 600);//��ʱ������������� ֻ��������һ��

	 ABCD abcd = ABCD(100, 200, 300);//C++�������Ѿ��Ż��� ���õ���
	//����ֱ�ӵ��ù��캯����?
	//����ù��캯����abcd ��������ٸ��ƣ�������
	//�ڹ��캯�������������һ�����캯��������ʲô������


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
	//���캯�� ִ����� ��ʼ����
	//10 11 12
	//7 8 9
	//myD
	//4 5 6
	//1 2 3
	cout<<"hello world"<<endl;
	system("pause");
}