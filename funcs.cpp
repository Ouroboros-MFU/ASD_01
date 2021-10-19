#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"
using namespace std;

	myString::myString(const char* str)
	{
		len = strlen(str);
		arr = new char [len+1];
		if (nullptr != arr) strcpy(arr, str);
		else throw "NO_MEMORY";
	}
	myString::myString(unsigned int size)
	{
		len = size;
		arr = new char[len+1];
	}
	myString::myString(const myString& s)
	{
		len = s.len;
		arr = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			arr[i] = s.arr[i];
		}
		arr[len] = '\0';
	}
	myString::~myString()
	{
		len = 0;
		delete[]arr;
	}
	char& myString::operator[](int index)///////////////доступ по индексу
	{
		return arr[index];
	}
	myString myString::operator+(const myString& str)
	{
		size_t lenght = len + strlen(str.arr);
		myString res(lenght + 1);
		if (nullptr != res.arr) 
		{
			strcpy(res.arr, arr);
			strcat(res.arr, str.arr);
		}
		else throw "STRING_IS_NULL";
		return res;
	}
	myString myString::operator*(int value)
	{
		unsigned int lenght = value * len;
		myString res(lenght + 1);
		if (nullptr != arr) strcpy(res.arr, arr);
		else throw "STRING_IS_NULL";
		for (int i = 0; i < value - 1; i++)
		{
			if (nullptr != arr && nullptr != res.arr) strcat(res.arr, arr);
			else throw "STRING_IS_NULL";
		}
		res.arr[lenght] = '\0';
		return res;
	}
	myString& myString::getSubString(int index, int lenght)	
	{
		myString res(lenght+1);
		for (int i = 0; i < lenght; i++)
		{
			res[i] = arr[i+index];
		}
		res[lenght] = '\0';
		return res;
	}
	void myString::printArr()
	{
		cout << arr << endl;
	}
	int myString::getLen()
	{
		return len;
	}
	std::ostream& operator<<(std::ostream& out, const myString& a)
	{
		 for (int i = 0; i < a.len;i++)
		 {
			 out << a.arr[i];
		 }
		 a.arr[a.len] = '\0';
		 return out;
	}




myString operator*(int value, myString& a)
{
	return a * value;
}
