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
	bool operator==(const myString& a)const;
	myString operator+(const myString& str)const;
	myString operator*(int value)const;
	myString& operator=(const myString& a);
	//myString& operator+=(const myString& a);////можно доделать
	myString getSubString(int index, int lenght)const;
	void print()const;
	int getLenght()const;
	~myString();
	
	friend std::ostream& operator<< (std::ostream& out, const myString& a);
};

myString operator*(int value, myString& a);
std::ostream& operator<< (std::ostream& out, const myString& a);