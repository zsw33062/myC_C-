#ifdef DLL_API//����Ѿ������ʲô������
//nothing to do
#else //������DLL_API
#define DLL_API __declspec(dllexport)    //_declspec(dllexport)��������־
#endif
#include <iostream>
using namespace std;
DLL_API int add(int a, int b);//���������ĺ���
class DLL_API Point    //�����࣬���������к����������������ɵ�����ĳЩ�ຯ������
{
private:
	float x, y;
public:
	Point();
	void SetPoint(float a, float b);
	void DisPlay();
};