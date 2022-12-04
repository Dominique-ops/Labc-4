#include "credit.h"

int credit::counter = 0;

int credit::Getcreditnumber() {
	return creditnumber;
}

double credit::Getsum() {
	return sum;
}

double credit::Getpercent() {
	return percent;
}

credit::credit():account() {
	creditnumber = 0;
	sum = 0;
	percent = 0;

}

credit::credit(char* n, char* s, char* o, int id , double su, double per):account(n,s,o) {
	creditnumber = id;
	sum = su;
	percent = per;
}

void credit::add_credit(credit mas[]) {
    char* surname = new char[50];
    char* name = new char[50];
    char* oname = new char[50];
    int id;
    double sum;
    double per;
    cout << "¬ведите номер кредитной карты: ";
    cin >> id;

    cout << "¬ведите фамилию: ";
    cin >> surname;

    cout << "¬ведите им€: ";
    cin >> name;

    cout << "¬ведите отчество: ";
    cin >> oname;

    cout << "¬ведите сумма кредита: ";
    cin >> sum;

    cout << "¬ведите процент кредита: ";
    cin >> per;

    mas[credit::counter] = credit(name, surname, oname, id, sum,per);

    credit::counter++;
}

void credit::To_String(ostream& out) {
    out << Getsurname() << endl;
    out << Getname() << endl;
    out << Getoname() << endl;
    out << creditnumber << endl;
    out << sum << endl;
    out << percent << endl;
}


void credit::save_credit(credit mas[]) {
    ofstream file("Credit.txt");
    file << counter << endl;
    for (int i = 0; i < counter; i++) {
        mas[counter].To_String(file);
    }
    delete[] mas;
    file.close();
}

void credit::load_credit(credit mas[]) {
    ifstream file("Credit.txt");
    if (file.is_open() && file.peek() != EOF) {
        char* n = new char[20];
        char* s = new char[20];
        char* o = new char[20];
        int id;
        double sum;
        double per;
        file >> counter;
        for (int i = 0; i < counter; i++) {
            file >> s;
            file >> n;
            file >> o;
            file >> id;
            file >> sum;
            file >> per;
            mas[counter] = credit(n, s, o, id, sum,per);
        }
    }
    else {
        cout << "—оздание новой DB" << endl;
        add_credit(mas);
    }
    file.close();
}

void credit::display(credit mas[]) {
    cout << "¬ведите id" << endl;
    int m;
    cin >> m;
    bool flag = false;
    for (int i = 0; i < counter; i++) {
        if (mas[i].creditnumber == m) {
            cout << mas[i];
            flag = true;
            break;
        }
    }
    if (flag == false) {
        cout << "id отсутствует" << endl;
    }

}

ostream& operator <<(ostream& out, credit& obj) {

    out << obj.Getsurname() << endl;
    out << obj.Getname() << endl;
    out << obj.Getoname() << endl;
    out << obj.creditnumber << endl;
    out << obj.sum << endl;
    out << obj.percent << endl;

    return out;
}

void sort(credit mas[]) {
    credit test;
    for (int i = 0; i < credit::counter - 1; ++i) {
        for (int j = 0; j < credit::counter - 1; ++j) {
            if (mas[j].sum < mas[j + 1].sum) {
                test = mas[j + 1];
                mas[j + 1] = mas[j];
                mas[j] = test;
            }
        }
    }


}

void addsum(credit mas[])
{
    int id, value;
    cout << "¬ведите сумму" << endl;
    cin >> value;
    cout << "¬ведите id" << endl;
    cin >> id;
    mas[id] + value;

}