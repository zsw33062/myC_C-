#pragma once

#include<iostream>
using namespace std;



class Array
{
public:
	Array(int length);
	Array(const Array& obj);
	~Array();
public:
	void setData(int index, int value);
	int getData(int index);
	int length();
protected:
private:
	int m_length;
	int *m_space;
};