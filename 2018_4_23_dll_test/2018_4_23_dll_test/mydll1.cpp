// mydll1.cpp : ���� DLL Ӧ�ó���ĵ���������
//
#include "stdafx.h"
#include "mydll1.h"
// extern "C"//��C++���Ե��У�extern "C"���߱���������C���Եķ�ʽ�����������
// {
// 	//����1���õ�2�����е����ֵ

	DLL_API int mymax(int a, int b)
	{
		if (a > b)
			return a;
		else
			return b;
	}
	//����2���õ�2�������ܺ�

	DLL_API int myadd(int a, int b)
	{
		return a + b;
	}
/*}*/