#include "Regist.h"
#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;

#define CLEAR system("cls");
#define PAUSE system("pause");

list<Reg> registration;
const string fileName = "Registration.txt";
void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();
	if (isOpen == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		int currentString = 0;
		string data;
		Reg oldReg;
		while (!fin.eof())
		{
			currentString++;
			getline(fin, data);
			if (currentString == 1)
			{
				oldReg.FullName = data;
			}
			else if (currentString == 2)
			{
				oldReg.mail = data;
			}
			else if (currentString == 3)
			{
				oldReg.pass = data;
				currentString = 0;
				registration.push_back(oldReg);
				oldReg = Reg();
			}
		}
	}
	fin.close();
}

void Registration()
{
	Reg newRegist;
	cout << "Enter name" << endl;
	cin.ignore();
	getline(cin, newRegist.FullName);
	cout << "Enter mail" << endl;
	cin >> newRegist.mail;
	cout << "Enter password" << endl;
	cin >> newRegist.pass;
	registration.push_back(newRegist);

	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == false)
	{
		cout << "Error: Application can't connect to database file" << endl;
	}
	else
	{
		cout << "File open!" << endl;
		fout << newRegist.FullName << endl;
		fout << newRegist.mail << endl;
		fout << newRegist.pass << endl;
	}
	fout.close();
	cout << "New user seccesssful added..." << endl;
	PAUSE
		CLEAR
}

void LogInToYourAccount()
{
	string name;
	string mail;
	string pass;
	bool nameP = false;
	bool mailP = false;
	bool passP = false;
	cout << "Enter correct name" << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Enter correct mail" << endl;
	cin >> mail;
	cout << "Enter correct password" << endl;
	cin >> pass;
	fstream fs("Registration.txt", ios::in | ios::out);
	if (!fs)
	{
		cout << "Error" << endl;
		return;
	}
	else
	{
		cout << "___________________________________" << endl;
		int currentString = 0;
		string data;
		while (!fs.eof())
		{
			currentString++;
			//getline(fs, data);
			//cout << data << endl;
			//data = "";
			//fs >> data;
			getline(fs, data);
			//cout << data << "\n";
			if (currentString == 1)
			{
				if (name == data)
				{
					nameP = true;
				}
			}
			else if (currentString == 2)
			{
				if (mail == data)
				{
					mailP = true;
				}
			}
			else if (currentString == 3)
			{
				if (pass == data)
				{
					passP = true;
				}
			}
			if (nameP == true && mailP == true && passP == true && currentString == 3)
			{
				cout << "Hello " << name << ". You log in tour account" << endl;
				return;
			}
			if (currentString == 3)
			{
				currentString = 0;
				nameP = false;
				mailP = false;
				passP = false;
			}
		}
		cout << "You entered not correct information. PLease try again" << endl;	
	}
	fs.close();
}


