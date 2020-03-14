#include <iostream>
#include <string>
#include "Regist.h"

using namespace std;


int main()
{
	init();
	int menu;
	do
	{
		cout << endl;
		cout << "Menu:" << endl;
		cout << " 1 - registration:" << endl;
		cout << " 2 - log in to your account" << endl;
		cout << " 7 - exit" << endl;
		cout << "Select action ";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			cout << "Registration:" << endl;
			Registration();
		}
		break;
		case 2:
		{
			cout << "Log in to your account" << endl;
			LogInToYourAccount();
		}
		break;
		case 7:
			break;
		default:
			break;
		}
	} while (menu != 7);

	system("pause");
	return 0;
}