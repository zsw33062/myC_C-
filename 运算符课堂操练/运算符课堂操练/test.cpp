#include<iostream>

using namespace std;
class Test
{
public:
	Test(int a){ num = a; }
	~Test(){}
	void setNum(int a){ num = a; }
	int GetNum(){ return num; }
private:
	int num;
};
//ֵ����
void Add(Test t)
{
	int x = t.GetNum() + t.GetNum();//ֵ���ݣ��൱��Ϊnum����һ������ֵΪ100
	t.setNum(x);
	cout << t.GetNum() << endl;
}
int maintest

{
	Test tt(100);
	Add(tt);
	cout << tt.GetNum() << endl;//ԭ�����ֵû�б仯���仯����NUM�ĸ���
	return 0;
}