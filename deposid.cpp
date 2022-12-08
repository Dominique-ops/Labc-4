#include "deposid.h"


int deposit::counter = 0;

deposit::deposit():account() {

	sum = 100;
	deposnumber = 0;
}

deposit::deposit(FIO s, double su, int depos):account(s) {
	
	sum = su;
	deposnumber = depos;

}

deposit::deposit(char* n, char* s, char* o, double su, int id) {
    Setclient(n, s, o);
	sum = su;
	deposnumber = id;
}

int deposit::getdeposnumber() {
	return deposnumber;
}
void  deposit::setdeposnumber(int value) {
	deposnumber = value;
}

void deposit::setsum(double value) {
	sum = value;
}

double deposit::getsum() {
	return sum;
}

void deposit::add_deposit(deposit mas[]) {
    char* surname = new char[50];
    char* name = new char[50];
    char* oname = new char[50];
    int id;
    double sum;
    cout << "Введите номер счета: ";
    cin >> id;

    cout << "Введите фамилию: ";
    cin >> surname;

    cout << "Введите имя: ";
    cin >> name;

    cout << "Введите отчество: ";
    cin >> oname;

    cout << "Введите депозит: ";
    cin >> sum;


    mas[deposit::counter] = deposit(name, surname, oname, sum, id);

    deposit::counter++;
}


void deposit::save_deposit(deposit mas[]) {
    ofstream file("Deposit.txt");
    file << counter << endl;
    for (int i = 0; i < counter; i++) {
        mas[i].To_String(file);
    }
    delete[] mas;
    file.close();
}
 
void deposit::To_String(ostream& out) {
    out << Getsurname() << endl;
    out << Getname() << endl;
    out << Getoname() << endl;
    out << deposnumber << endl;
    out << sum << endl;
}

void deposit::load_deposit(deposit mas[]) {
    ifstream file("Deposit.txt");
    if (file.is_open() && file.peek() != EOF) {
        char* n = new char[20];
        char* s = new char[20];
        char* o = new char[20];
        int id;
        double sum;
        file >> counter;
        for (int i = 0; i < counter; i++) {
            file >> s;
            file >> n;
            file >> o;
            file >> id;
            file >> sum;
            mas[i] = deposit(n, s, o, sum, id);
        }
    }
     else {
         cout << "Создание новой DB" << endl;
         add_deposit(mas);
     }
    file.close();

}

ostream& operator <<(ostream& out, deposit& obj) {

    out << obj.Getsurname() << endl;
    out << obj.Getname() << endl;
    out << obj.Getoname() << endl;
    out << obj.deposnumber << endl;
    out << obj.sum << endl;

    return out;
}

void deposit::sort(deposit mas[]) {
        deposit test;
        for (int i = 0; i < deposit::counter - 1; ++i) {
            for (int j = 0; j < deposit::counter - 1; ++j) {
                if (mas[j].sum < mas[j + 1].sum) {
                    test = mas[j + 1];
                    mas[j + 1] = mas[j];
                    mas[j] = test;
                }
            }
        }

    
}

void addsum(deposit mas[])
{
    int id; double value;
    cout << "Введите сумму" << endl;
    cin >> value;
    cout << "Введите id" << endl;
    cin >> id;
    mas[id] + value;

}

void deposit::display(deposit mas[]) {
    cout << "Введите id" << endl;
    int m;
    cin >> m;
    bool flag = false;
    for (int i = 0; i < counter; i++) {
        if (mas[i].deposnumber == m) {
            cout << mas[i];
            flag = true;
            break;
        }
    }
    if (flag == false) {
        cout << "id отсутствует" << endl;
    }

}