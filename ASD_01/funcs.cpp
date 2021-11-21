#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"
#include <stdlib.h>
using namespace std;
template<typename T>
myString<T>::myString()
{
	len = 1;
	arr = new T[len];
}
template<typename T>
myString<T>::myString(const T* str, const size_t length)
{
	len = length;
	arr = new T[len + 1];
	arr[len] = '\0';
	if (nullptr != arr)
	{
		for (size_t i = 0; i < len; i++)
		{
			arr[i] = str[i];
		}
	}
	else throw "NO_MEMORY";
}
template<typename T>
myString<T>::myString(const T* str)
{
	len = sizeof(str) / sizeof(T);
	arr = new T[len + 1];
	arr[len] = '\0';
	if (nullptr != arr)
	{
		for (size_t i = 0; i < len; i++)
		{
			arr[i] = str[i];
		}
	}
	else throw "NO_MEMORY";
}
template<typename T>
myString<T>::myString(const size_t size)
{
	if (size < 0) throw "INVALID_SIZE!";
	len = size;
	arr = new T[len + 1];
	arr[len] = '\0';
}
template<typename T>
myString<T>::myString(const myString<T>& str)
{
	len = str.len;
	arr = new T[len + 1];
	for (size_t i = 0; i < len; i++)
	{
		arr[i] = str.arr[i];
	}
	arr[len] = '\0';
}
template<typename T>
myString<T>::~myString()
{
	delete[]arr;
}
template<typename T>
bool myString<T>::operator==(const myString& a)const
{
	if (len != a.len) return false;
	else
	{
		for (size_t i = 0; i < len; i++)
		{
			if (arr[i] != a.arr[i]) return false;
		}
		return true;
	}
}
template<typename T>
T& myString<T>::operator[](const size_t index)
{
	if (index < 0 || index > len) throw "INVALID_INDEX!";
	return arr[index];
}
template<typename T>
myString<T> myString<T>::operator+(const myString& str)const
{
	if (len == 0 && str.len == 0) throw "STRING_IS_NULL!";
	const size_t length = len + str.len;
	T* res = new T[length];
	if (nullptr != res)
	{
		for (size_t i = 0; i < len; i++)
		{
			res[i] = arr[i];
		}
		for (size_t i = len; i < length; i++)
		{
			res[i] = str.arr[i - len];
		}
	}
	else
	{
		throw "NO_COTENATE_MEMORY!";
	}
	myString result(res, length);
	delete[]res;
	return result;
}
template<typename T>
myString<T> myString<T>::operator*(const int value)const
{
	if (len == 0) throw "STRING_IS_NULL!";
	if (value <= 0) throw "INVALID_MULTIPLIER!";
	const size_t length = value * (len);
	T* res = new T[length];
	size_t count = 0;
	for (int k = 0; k < value; k++)
	{
		if (nullptr != arr && nullptr != res)
		{
			while (count < length)
			{
				for (size_t i = 0; i < len; i++)
				{

					res[count] = arr[i];

					count++;

				}
			}
		}
	}
	//myString res(length + 1);
	/*if (nullptr != arr)
	{
		for (size_t i = 0; i < len; i++)
		{
			res[i] = arr[i];
		}
	}
	else throw "STRING_IS_NULL";
	size_t count = len;
	for (int k = 0; k < value - 1; k++)
	{
		if (nullptr != arr && nullptr != res)
		{
			while (count < length)
			{
				for (size_t i = 0; i < len; i++)
				{

					res[count] = arr[i];

					count++;

				}
			}
		}
		else throw "STRING_IS_NULL";
	}*/
	myString result(res, length);
	return result;
}

template<typename T>
myString<T>& myString<T>::operator=(const myString<T>& str)
{
	if (this == &str) return *this;
	delete[]arr;
	len = str.len;
	arr = new T[len + 1];
	for (int i = 0; i < len; i++)
	{
		arr[i] = str.arr[i];
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
template<typename T>
myString<T> myString<T>::operator()(const size_t start, const size_t stop)
{
	if (start < 0 || stop > len || stop < start) throw "INVALID_PARAM!";
	const size_t length = stop - start;
	//T* res = new T[length + 1];
	T* res = new T[length];
	for (size_t i = 0; i < length; i++)
	{
		res[i] = arr[start + i];
	}
	//res[length] = '\0';
	myString<T> result(res, length);
	delete[] res;
	return result;
}
template<typename T>
myString<T> myString<T>::operator()(const size_t start)
{
	if (start < 0 || start > len) throw "INVALID_PARAM!";
	const size_t length = len - start;
	T* res = new T[length];
	for (size_t i = 0; i < length; i++)
	{
		res[i] = arr[start + i];
	}
	//res[length] = '\0';
	myString<T> result(res, length);
	delete[] res;
	return result;
}
/*template<typename T>
myString<T> myString<T>::getSubString(const size_t index, const size_t length)const
{
	if (index < 0 || length <= 0 || length>len-index) throw "INVALID_INDEX_OR_LENGTH";
	char* res = new char[length+1];
	for (size_t i = 0; i < length; i++)
	{
		res[i] = arr[i+index];
	}
	res[length] = '\0';
	myString result(res);
	delete[]res;
	return result;
}*/
template<typename T>
void myString<T>::print()const
{
	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
template<typename T>
size_t myString<T>::getLength()const
{
	return len;
}
template<typename T>
myString<T> operator*(const int value, const myString<T>& a)
{
	if (value < 0) throw "INVALID_MULTIPLIER!";
	return a * value;
}
template<typename T>
std::ostream& operator<< (std::ostream& out, myString<T>& a)
{
	for (size_t i = 0; i < a.getLength(); i++)
	{
		out << a[i];
	}
	return out;
}