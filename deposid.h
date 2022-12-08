#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <exception>
#include < string.h >
#include <iostream>
#include <fstream>
#include "account.h"
#include "credit.h"
class deposit: protected account 
{
private:
	int deposnumber;
	double sum;
public:
	static int counter;
	static void sort(deposit*);
	deposit();
	deposit(FIO, double, int);
	deposit(char*, char*, char*, double, int);
	void setdeposnumber(int);
	int getdeposnumber();
	void setsum(double);
	double getsum();
	static void add_deposit(deposit*);
	static void save_deposit(deposit*);
	void To_String(ostream&);
	static void load_deposit(deposit*);
	static int samefio(deposit*);
	static double right_int();
	static void write_off(deposit*);
	friend ostream& operator <<(ostream& out, deposit& obj);
	static void display(deposit*);
	
	void operator+(double value)
	{
		this->sum += value;
	}
	void operator-(double value)
	{
		this->sum -= value;
	}
};

