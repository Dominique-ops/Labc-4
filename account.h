#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <fstream>
#include "FIO.h"
using namespace std;

class account
{
private:
	FIO client;
public:
	account();
	account(char*, char*, char*);
	account(FIO);
	char* Getsurname();
	char* Getname();
	char* Getoname();
	virtual void To_String(ostream&);
};

