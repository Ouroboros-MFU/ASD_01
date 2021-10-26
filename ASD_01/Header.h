#pragma once
class myString
{
private:
	size_t len = 0;
	char* arr = nullptr;
public:
	myString(const char* str);
	myString(size_t size);
	myString(const myString& str);
	char& operator[](const size_t index);
	bool operator==(const myString& a)const;
	myString operator+(const myString& str)const;
	myString operator*(int value)const;
	myString& operator=(const myString& a);
	//myString& operator+=(const myString& a);////можно доделать
	myString getSubString(int index, int lenght)const;
	void print()const;
	size_t getLength()const;
	~myString();
	
	friend std::ostream& operator<< (std::ostream& out, const myString& a);
};

myString operator*(int value, const myString& a);
std::ostream& operator<< (std::ostream& out, const myString& a);