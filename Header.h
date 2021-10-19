#pragma once
class myString
{
private:
	size_t len = 0;
	char* arr = nullptr;
public:
	myString(const char* str);
	myString(unsigned int size);
	myString(const myString& s);
	char& operator[](int index);
	myString operator+(const myString& str);
	myString operator*(int value);
	myString& getSubString(int index, int lengh);
	void printArr();
	int getLen();
	~myString();

	//myString& operator+(const myString& s);

	//myString& operator+=(const myString& rhs);
	friend myString operator+(const myString& lhs, const myString& rhs);
	friend std::ostream& operator<<(std::ostream& out, const myString& a);
};

//myString operator+(const myString& lhs, const myString& rhs);

std::ostream& operator<<(std::ostream& out, const myString& a);
myString operator*(int value, myString& a);