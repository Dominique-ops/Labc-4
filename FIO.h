#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
class FIO
{
private:
	friend class account;
	char* surname;
	char* name;
	char* oname;
public:
	FIO();
	FIO(char*, char*, char*);

	FIO(FIO& other) {
		surname = other.surname;
		name = other.name;
		oname = other.oname;
	}
};

