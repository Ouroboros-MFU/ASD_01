#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"
using namespace std;

myString::myString(const char* str)
{
	len = strlen(str);
	arr = new char[len + 1];
	if (nullptr != arr) strcpy(arr, str);
	else throw "NO_MEMORY";
}
myString::myString(int size)
{
	if (size < 0) throw "INVALID_SIZE!";
	len = size;
	arr = new char[len + 1];
}
myString::myString(const myString& str)
{
	len = str.len;
	arr = new char[len + 1];
	for (int i = 0;i < len;i++)
	{
		arr[i] = str.arr[i];
	}
	arr[len] = '\0';
}
myString::~myString()
{
	len = 0;
	delete[]arr;
}
bool myString::operator==(const myString& a)const
{
	if (len != a.len) return false;
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (arr[i] != a.arr[i]) return false;
		}
		return true;
	}
}
char& myString::operator[](const int index)
{
	if (index < 0 || index > len) throw "INVALID_INDEX!";
	return arr[index];
}

myString myString::operator+(const myString& str)const
{
	const unsigned int lenght = len + strlen(str.arr);
	char* res = new char[lenght+1];
	strcpy(res, arr);
	strcat(res, str.arr);
	myString result(res);
	delete[]res;
	return result;
}
myString myString::operator*(const int value)const
{
	if (value <= 0) throw "INVALID_MULTIPLIER!";
	const unsigned int lenght = value * len;
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
myString& myString::operator=(const myString& a)
{
	if (this == &a) return *this;
	if (arr) delete[]arr;
	len = a.len;
	arr = new char[len + 1];
	for (int i = 0; i < len;i++)
	{
		arr[i] = a.arr[i];
	}
	arr[len] = '\0';
	return *this;
}
//myString& myString::operator+=(const myString& a)////////////можно доделать
//{
//	len = len + strlen(a.arr);
//	//if (arr) delete[]arr;
//	char* res = new char[len+1];
//	strcat(res, arr);
//	strcat(res, a.arr);
//	delete[]arr;
//	arr = new char[len + 1];
//	arr = res;
//	delete[]res;
//	arr[len] = '\0';
//	return *this;
//}

myString myString::getSubString(const int index, const int lenght)const
{
	if (index < 0 || lenght <= 0 || lenght>len-index) throw "INVALID_INDEX_OR_LENGHT";
	char* res = new char[lenght+1];
	for (int i = 0; i < lenght; i++)
	{
		res[i] = arr[i+index];
	}
	res[lenght] = '\0';
	myString result(res);
	delete[]res;
	return result;
}
void myString::print()const
{
	cout << arr << endl;
}
int myString::getLenght()const
{
	return len;
}
myString operator*(int value, myString& a)
{
	if (value < 0) throw "INVALID_MULTIPLIER!";
	return a * value;
}
std::ostream& operator<< (std::ostream& out, const myString& a)
{
	for (int i = 0;i < a.len;i++)
	{
		out << a.arr[i];
	}
	a.arr[a.len] = '\0';
	return out;
}