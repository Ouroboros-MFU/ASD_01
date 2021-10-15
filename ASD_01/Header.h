#pragma once
class myString
{
private:
	int len = 0;
	char* arr = nullptr;
public:
	myString(const char* str);
	char& operator[](int index);
	char* operator+(const char* str);
	char* operator*(int value);
	char* getSubString(int index, int lengh);
	void printArr();
	int getLen();
	~myString();
};

char* operator*(int value, myString& a);