#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "account.h"
class deposit: protected account 
{
private:
	friend static void sort(deposit*);
	int deposnumber;
	double sum;
public:
	static int counter;
	deposit();
	deposit(FIO, double, int);
	deposit(char*, char*, char*, double, int);
	int setdeposnumber(int);
	int getdeposnumber();
	double setsum(double);
	double getsum();
	static void add_deposit(deposit*);
	static void save_deposit(deposit*);
	void To_String(ostream&);
	static void load_deposit(deposit*);
	friend ostream& operator <<(ostream& out, deposit& obj);
	static void display(deposit*);
	
	void operator+(double value)
	{
		this->sum += value;
	}
};

