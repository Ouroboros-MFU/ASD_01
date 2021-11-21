#pragma once
#include <iostream>
template<typename T>
class myString
{
private:
	size_t len = 0;
	T* arr = nullptr;
public:
	myString();
	myString(const T* str, const size_t length);
	myString<T>(const T* str);
	myString(size_t size);
	myString(const myString<T>& str);
	~myString();
	bool operator==(const myString<T>& a)const;
	T& operator[](const size_t index);
	myString<T> operator+(const myString<T>& str)const;
	myString<T> operator*(int value)const;
	myString<T>& operator=(const myString<T>& a);
	myString<T> operator()(const size_t start, const size_t stop);
	myString<T> operator()(const size_t start);
	//myString& operator+=(const myString& a);  ////можно_доделать
	myString<T> getSubString(size_t index, size_t length)const;
	void print()const;
	size_t getLength()const;


	//friend std::ostream& operator<< (std::ostream& out, const myString& a);
};
template<typename T>
myString<T> operator*(const int value, const myString<T>& a);
template<typename T>
std::ostream& operator<< (std::ostream& out, myString<T>& a);