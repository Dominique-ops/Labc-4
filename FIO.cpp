#include "FIO.h"

FIO::FIO() {
	name = new char[20];
	surname = new char[20];
	oname = new char[20];
	strcpy(name, "Ivan");
	strcpy(surname, "Ivanov");
	strcpy(oname, "Ivanovich");

}

FIO::FIO(char* n, char* s, char* o)
{
	name = n;
	surname = s;
	oname = o;
}
