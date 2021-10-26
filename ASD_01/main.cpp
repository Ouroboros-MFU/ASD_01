#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	try
	{
		cout << "Enter your string: ";
		char buffer[100];
		cin.getline(buffer, 100);
		myString a(buffer);
		int change = 1;
		while (change)
		{
			int key = 0;
			//system("cls");
			cout << " Choose what you want to do:\n 1) Read/write a symbol by index.\n 2) Concatenate strings.\n 3) Multiplicate string.\n 4) Get substring by index and lenght\n 5) Compare strings.\n 6) Print string.\n 7) Exit.\n";
			cin >> key;
			change = 0;
			switch (key)
			{
			case 1:
			{
				system("cls");
				cout << " Read/write a symbol by index.\n _____________________________\n\n Do you want read or write a symbol?\n 1)Read.\n 2)Write." << endl;
				int choose = 0, index = 0;
				cin >> choose;
				cout << "Which index?" << endl;
				cin >> index;
				switch (choose)
				{
				case 1:
				{
					system("cls");
					cout << "Symbol [" << index << "] is: " << a[index] << endl;
					change = 1;
					break;
				}
				case 2:
				{
					cout << "On which symbol do you want to change?" << endl;
					char s;
					cin >> s;
					a[index] = s;
					change = 1;
					system("cls");
					cout << " Complete!\n";
					system("pause");
					break;
				}

				default:
				{
					cout << "Error choice! Try again!" << endl;
					cin >> choose;
					change = 1;
					break;
				}
				}
				break;
			}
			case 2:
			{
				system("cls");
				char bufferB[100];
				cout << " Concatenate strings.\n ____________________\n\n Enter catenate string: ";
				cin >> bufferB;
				cout << endl << endl;
				myString b(bufferB);
				myString sum(a + b);
				cout << " Concatenated string is: " << sum << endl;
				change = 1;
				break;
			}
			case 3:
			{
				system("cls");
				int power = 0;
				cout << " Multiplicate string.\n ____________________\n\n Enter the multiplier: ";
				cin >> power;
				cout << endl;
				myString mul(power * a);
				cout << "Multiplication is: " << mul << endl;
				change = 1;
				break;
			}
			case 4:
			{
				system("cls");
				cout << " Get substring by index and lenght\n _________________________________\n\n Enter index of start substring: ";
				int ind = 0;
				cin >> ind;
				cout << endl;
				cout << "Enter substring lenght: ";
				int len = 0;
				cin >> len;
				cout << endl;
				myString sub(a.getSubString(ind, len));
				cout << "Substring is: " << sub << endl;
				change = 1;
				break;
			}
			case 5:
			{
				system("cls");
				char bufferB[100];
				cout << " Compare strings.\n ________________\n\n Enter comparing string: ";
				cin >> bufferB;
				cout << endl;
				myString b(bufferB);
				cout << "Strings are equal: " << (a==b);
				change = 1;
				break;
			}
			case 6:
			{
				system("cls");
				cout << "Your string is: ";
				a.print();
				change = 1;
				break;
			}
			case 7:
			{
				return 0;
			}
			default: 
			{
				system("cls");
				cout << "Error choice! Try again!" << endl;
				change = 1;
			}
			}
		}
	}
	catch (const char* ex)
	{
		cout <<"ERROR: " << ex << endl;
	}
}