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


void account::To_String(ostream& out) {
	out << Getsurname() << endl;
	out << Getname() << endl;
	out << Getoname() << endl;
}