#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class myString
{
private:
	int len = 0;
	char* arr = nullptr;
public:
	myString(const char* str)
	{
		len = strlen(str);
		arr = (char*)malloc((len + 1) * sizeof(char));
		if (nullptr != arr) strcpy(arr, str);
		else throw "NO_MEMORY";
		//cout << arr << endl;
	}
	char& operator[](int index)
	{
		return arr[index];
	}
	char* operator+(const char* str)
	{
		int lenght = len + strlen(str);
		char* res = (char*)malloc((lenght + 1) * sizeof(char));
		if (nullptr != arr) strcpy(res, arr);
		if (nullptr != res) strcat(res, str);
		else throw "STRING_IS_NULL";
		return res;
	}
	char* operator*(int value)////////////////////////////////////////обеспечить коммутативность
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
	char* getSubString(int index, int lenght)	///////////////////////// доделать подстроку
	{
		char* temp = (char*)malloc((lenght + 1) * sizeof(char));
		for (int i = index; i < lenght; i++)
		{
			for (int j = 0; j < lenght; j++)
			{
				temp[j] = arr[i];
			}
		}
		return temp;
	}
	void printArr()
	{
		cout << arr << endl;
	}
	int getLen()
	{
		return len;
	}
	/*~myString()////////////////////////////разобраться с деструктором
	{
		free(arr);
	}*/
};

int main()
{
	myString a("Hello World!");
	a.printArr();
	//cout << a[1] << endl;
	cout << a * 3 << endl;
	//a.printArr();
	//cout << a.getSubString(0, 5) << endl;
	/*cout << endl;
	//a[1] = 3;
	cout << a[1] << endl;*/
	cout << a + "ght" << endl;
	/*a * 4;
	a.printArr();*/
	return 0;
}