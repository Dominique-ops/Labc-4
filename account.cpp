#include "account.h"

account::account() {
	FIO();
}
account::account(char* n, char* s, char* o) {
	FIO(n, s, o);
}
account::account(FIO s) {
	client = s;
}
char* account::Getname() {
	return client.name;
}

char* account::Getsurname() {
	return client.surname;
}

char* account::Getoname() {
	return client.oname;
}

void  account::Setname(char* s) {
	 client.name = s;
}

void account::Setsurname(char* s) {
	 client.surname = s;
}

void account::Setoname(char* s) {
   client.oname = s;
}

void account::Setclient(char* n, char* s, char* o) {
	client.name = n;
	client.surname = s;
	client.oname = o;
}
void account::To_String(ostream& out) {
	out << Getsurname() << endl;
	out << Getname() << endl;
	out << Getoname() << endl;
}