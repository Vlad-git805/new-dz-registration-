
#pragma once
#include <string>

using namespace std;

struct Reg
{
	string FullName;
	string mail;
	string pass;
};

void init();
void Registration();
void LogInToYourAccount();