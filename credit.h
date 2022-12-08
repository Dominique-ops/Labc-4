#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include "account.h"

class credit:protected account
{ 
private:
	int creditnumber;
	double sum;
	double percent;
public:
	static int counter;
	static void sort(credit*);
	int Getcreditnumber();
	double Getsum();
	double Getpercent();
	credit();
	credit(char*, char*, char*, int, double, double);
	static void add_credit(credit*);
	static void save_credit(credit*);
	void To_String(ostream&);
	static void load_credit(credit*);
	static void display(credit*);
	friend ostream& operator <<(ostream& out, credit& obj);

	void operator+(double value)
	{
		this->sum += value;
	}


};

