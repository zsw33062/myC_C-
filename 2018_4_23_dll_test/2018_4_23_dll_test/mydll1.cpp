// mydll1.cpp : 定义 DLL 应用程序的导出函数。
//
#include "stdafx.h"
#include "mydll1.h"
// extern "C"//在C++语言当中，extern "C"告诉编译器，用C语言的方式编译这个函数
// {
// 	//函数1：得到2个数中的最大值

	DLL_API int mymax(int a, int b)
	{
		if (a > b)
			return a;
		else
			return b;
	}
	//函数2：得到2个数的总和

	DLL_API int myadd(int a, int b)
	{
		return a + b;
	}
/*}*/