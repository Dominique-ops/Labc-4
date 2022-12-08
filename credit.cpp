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
   credit_period = 0;
    month_payment = 0;

}

credit::credit(char* n, char* s, char* o, int id , double su, double per,int period) {
    Setclient(n, s, o);
	creditnumber = id;
	sum = su;
	percent = per;
    credit_period = period;
    month_payment = su * ((per / 100) / (1 - (pow(1 + per / 100, -period))));
}

void credit::add_credit(credit mas[]) {
    char* surname = new char[50];
    char* name = new char[50];
    char* oname = new char[50];
    char* buff = new char[50];
    int id;
    double sum;
    double per;
    cout << "������� ����� ��������� �����: ";
    id = right_int();

    cout << "������� ���" << endl;
    cin >> buff;
    if (strlen(buff) > 20) { throw length_error("�������� ����� � 20 ��������"); }
    strcpy(name, buff);
    cout << "������� �������" << endl;
    cin >> buff;
    if (strlen(buff) > 20) { throw length_error("�������� ����� � 20 ��������"); }
    strcpy(surname, buff);
    cout << "������� ��������" << endl;
    cin >> buff;
    if (strlen(buff) > 20) { throw length_error("�������� ����� � 20 ��������"); }
    strcpy(oname, buff);

    cout << "������� ����� �������: ";
    sum = right_int();

    cout << "������� ������� �������: ";
    per = right_int();

    double period;
    int month;
    cout << "������� ����(�����) �������: ";
    period = right_int();



    mas[credit::counter] = credit(name, surname, oname, id, sum,per,period);

    credit::counter++;
}

void credit::To_String(ostream& out) {
    out << Getsurname() << endl;
    out << Getname() << endl;
    out << Getoname() << endl;
    out << creditnumber << endl;
    out << sum << endl;
    out << percent << endl;
    out << credit_period << endl;
}


void credit::save_credit(credit mas[]) {
    ofstream file("Credit.txt");
    file << counter << endl;
    for (int i = 0; i < counter; i++) {
        mas[i].To_String(file);
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
        int id, period;
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
            file >> period;
            mas[i] = credit(n, s, o, id, sum,per,period);
        }
    }
    else {
        cout << "�������� ����� DB" << endl;
        try {
            add_credit(mas);
        }
        catch (length_error& e) {

            cout << e.what() << endl;
        }
    }
    file.close();
}

void credit::display(credit mas[]) {
    cout << "������� id" << endl;
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
        cout << "id �����������" << endl;
    }

}

ostream& operator <<(ostream& out, credit& obj) {

    out << obj.Getsurname() << endl;
    out << obj.Getname() << endl;
    out << obj.Getoname() << endl;
    out << obj.creditnumber << endl;
    out << obj.sum << endl;
    out << obj.percent << endl;
    out << obj.percent << endl;
    out << obj.month_payment << endl;

    return out;
}

void credit::sort(credit mas[]) {
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

/*void addsum(credit mas[])
{
    int id, value;
    cout << "������� �����" << endl;
    cin >> value;
    cout << "������� id" << endl;
    cin >> id;
    mas[id] + value;
    
}*/

void credit::loan_payment(credit mas[]) {

    cout << "������� ������" << endl;
    double n;
    n = right_int();
    cout << "������� ��������� �����" << endl;
    double m = right_int();
        bool flag = false;
    for (int i = 0; i < counter; i++) {
        if (mas[i].creditnumber == m) {
            mas[i] - n;
            flag = true;
            break;
        }
    }
    if (flag == false) {
        cout << "id �����������" << endl;
    }

}

int credit::samefio(credit mas1[]) {
    char* n = new char[20];
    char* s = new char[20];
    char* o = new char[20];
    char* buff = new char[100];
    int id = -1;
    try {
        cout << "������� ���" << endl;
        cin >> buff;
        if (strlen(buff) > 20) { throw length_error("�������� ����� � 20 ��������"); }
        strcpy(n, buff);
        cout << "������� �������" << endl;
        cin >> buff;
        if (strlen(buff) > 20) { throw length_error("�������� ����� � 20 ��������"); }
        strcpy(s, buff);
        cout << "������� ��������" << endl;
        cin >> buff;
        if (strlen(buff) > 20) { throw length_error("�������� ����� � 20 ��������"); }
        strcpy(o, buff);
        for (int i = 0; i < counter; i++) {
            if (strcmp(n, mas1[i].Getname()) == 0 && strcmp(s, mas1[i].Getsurname()) == 0 && strcmp(o, mas1[i].Getoname()) == 0) {
                id= mas1[i].creditnumber;
            }
            return id;
        }
    }
    catch (length_error& e) {
        cout<<e.what();
    }

}

double credit::right_int() {
    string buff;
    try {
        cin >> buff;
        for (int i = 0; i < buff.size(); i++) {
            if (isalpha(buff[i]) != 0) { throw 1; }
        }
        return stod(buff.c_str());
    }

    catch (int a) {
        cout << "�������� ��������" << endl;
        right_int();
    }


}