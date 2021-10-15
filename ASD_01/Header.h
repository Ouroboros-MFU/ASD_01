#pragma once
class myString
{
private:
	int len = 0;
	char* arr = nullptr;
public:
	myString(const char* str);
	myString(int size);
	myString(const myString& str);
	char& operator[](int index);
	bool operator==(const myString& a);
	myString operator+(const myString& a);
	myString operator*(int value);
	myString& operator*=(int value);
	myString& operator=(const myString& a);
	//myString& operator+=(const myString& a);////можно доделать
	
	myString getSubString(int index, int lengh);
	void print();
	int getLenght();
	~myString();
	
	friend std::ostream& operator<< (std::ostream& out, const myString& a);
};

myString operator*(int value, myString& a);
std::ostream& operator<< (std::ostream& out, const myString& a);