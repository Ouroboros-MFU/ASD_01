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
myString::myString(size_t size)
{
	len = size;
	arr = new char[len + 1];
}
myString::myString(const myString& str)
{
	len = str.len;
	arr = new char[len + 1];
	for (size_t i = 0; i < len; i++)
	{
		arr[i] = str.arr[i];
	}
	arr[len] = '\0';
}
myString::~myString()
{
	delete[]arr;
}
bool myString::operator==(const myString& a)const
{
	if (len != a.len) return false;
	for (size_t i = 0; i < len; i++)
	{
		if (arr[i] != a.arr[i]) return false;
	}
	return true;
}
char& myString::operator[](const size_t index)
{
	if (index < 0 || index > len) throw "INVALID_INDEX!";
	return arr[index];
}

myString myString::operator+(const myString& str)const
{
	const size_t length = len + strlen(str.arr);
	char* res = new char[length + 1];
	strcpy(res, arr);
	strcat(res, str.arr);
	myString result(res);
	delete[]res;
	return result;
}
myString myString::operator*(const int value)const
{
	if (value <= 0) throw "INVALID_MULTIPLIER!";
	const size_t length = value * len;
	myString res(length + 1);
	if (nullptr != arr) strcpy(res.arr, arr);
	else throw "STRING_IS_NULL";
	for (int i = 0; i < value - 1; i++)
	{
		if (nullptr != arr && nullptr != res.arr) strcat(res.arr, arr);
		else throw "STRING_IS_NULL";
	}
	res.arr[length] = '\0';
	return res;
}
myString& myString::operator=(const myString& a)
{
	if (this == &a) return *this;
	delete[]arr;
	len = a.len;
	arr = new char[len + 1];
	for (size_t i = 0; i < len; i++)
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

myString myString::getSubString(const int index, const int length)const
{
	if (index < 0 || length <= 0 || length>len - index) throw "INVALID_INDEX_OR_LENGHT";
	myString result(length);
	for (int i = 0; i < length; i++)
	{
		result[i] = arr[i + index];
	}
	result[length] = '\0';
	return result;
}
void myString::print()const
{
	cout << arr << endl;
}
size_t myString::getLength()const
{
	return len;
}
myString operator*(const int value, const myString& a)
{
	if (value < 0) throw "INVALID_MULTIPLIER!";
	return a * value;
}
std::ostream& operator<< (std::ostream& out, const myString& a)
{
	for (size_t i = 0; i < a.len; i++)
	{
		out << a.arr[i];
	}
	a.arr[a.len] = '\0';
	return out;
}