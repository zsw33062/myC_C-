#ifdef DLL_API//如果已经定义就什么都不做
//nothing to do
#else //否则定义DLL_API
#define DLL_API __declspec(dllexport)    //_declspec(dllexport)：导出标志
#endif
#include <iostream>
using namespace std;
DLL_API int add(int a, int b);//导出单独的函数
class DLL_API Point    //导出类，其自身所有函数都将被导出，可单独对某些类函数导出
{
private:
	float x, y;
public:
	Point();
	void SetPoint(float a, float b);
	void DisPlay();
};