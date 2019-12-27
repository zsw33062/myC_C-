#include "MakeDll.h"

int add(int a, int b)
{
	return a + b;
}

Point::Point()
{
	x = 0.0f;
	y = 0.0f;
}

void Point::SetPoint(float a, float b)
{
	x = a;
	y = b;
}
void Point::DisPlay()
{
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
}