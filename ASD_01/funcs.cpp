#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"
using namespace std;

	myString::myString(const char* str)
	{
		len = strlen(str);
		arr = (char*)malloc((len + 1) * sizeof(char));
		if (nullptr != arr) strcpy(arr, str);
		else throw "NO_MEMORY";
		//cout << arr << endl;
	}
	myString::~myString()
	{
		len = 0;
		free(arr);
	}
	char& myString::operator[](int index)
	{
		return arr[index];
	}
	char* myString::operator+(const char* str)
	{
		int lenght = len + strlen(str);
		char* res = (char*)malloc((lenght + 1) * sizeof(char));
		if (nullptr != arr) strcpy(res, arr);
		if (nullptr != res) strcat(res, str);
		else throw "STRING_IS_NULL";
		return res;
	}
	char* myString::operator*(int value)////////////////////////////////////////обеспечить коммутативность
	{
		char* res = (char*)malloc((value * len + 1) * sizeof(char));
		if (nullptr != arr) strcpy(res, arr);
		else throw "STRING_IS_NULL";
		for (int i = 0; i < value - 1; i++)
		{
			if (nullptr != arr && nullptr != res) strcat(res, arr);
			else throw "STRING_IS_NULL";
		}
		return res;
	}
	char* myString::getSubString(int index, int lengh)	///////////////////////// доделать подстроку
	{
		char* temp = (char*)malloc(lengh+1);
		for (int i = 0; i < lengh; i++)
		{
			temp[i] = arr[i+index];
		}
		temp[lengh] = '\0';
		return temp;
	}
	void myString::printArr()
	{
		cout << arr << endl;
	}
	int myString::getLen()
	{
		return len;
	}


char* operator*(int value, myString& a)
{
	return a * value;
}
