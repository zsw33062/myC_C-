#include <iostream>
#include "MakeDll.h"
using namespace std;
#pragma comment(lib,"MakeDll.lib")
int main()
{
	int a = 10;
	int b = 2;
	int c = add(a, b);
	cout << c << endl;
	Point p1, p2;
	p2.SetPoint(5.6f, 7.8f);
	p1.DisPlay();
	p2.DisPlay();
	getchar();
	return 0;
}