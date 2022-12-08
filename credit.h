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
	int credit_period;
	double month_payment;
public:
	static int counter;
	static void sort(credit*);
	int Getcreditnumber();
	double Getsum();
	double Getpercent();
	credit();
	credit(char*, char*, char*, int, double, double,int);
	static void add_credit(credit*);
	static void load_credit(credit*);
	static void save_credit(credit*);
	void To_String(ostream&);
	static void loan_payment(credit*);
	static void display(credit*);
	static int samefio(credit*);
	static double right_int();
	void load_payment(credit*);
	friend ostream& operator <<(ostream& out, credit& obj);

	void operator-(double value)
	{
		this->sum -= value;
	}


};

