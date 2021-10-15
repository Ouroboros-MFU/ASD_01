#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	//cout << 
	myString a("Hello World!");
	myString b(a);
	a.print();
	//cout << 3*a << endl;
	cout << b << endl;
	//a + "abc";
	cout << (a+b);
	a.print();

	//cout << a << endl;
	//~myString();
	return 0;
}