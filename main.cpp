#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	
	myString a("Hello World!");
	myString b("Hello");
	myString res(a * 3);
	cout << a;
	cout << endl;
	cout << b;
	cout << endl;
	cout << res;
	cout << endl;

	cout << a;
	return 0;
}