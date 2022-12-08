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
    char* buff = new char[100];
    int id;
    double sum;
    cout << "Введите номер счета: ";
    id = right_int();

        cout << "Введите имя" << endl; 
        cin >> buff;
        if (strlen(buff) > 20) { throw length_error("Превышен лимит в 20 символов"); }
        strcpy(name, buff);
        cout << "Введите фамилию" << endl;
        cin >> buff;
        if (strlen(buff) > 20) { throw length_error("Превышен лимит в 20 символов"); }
        strcpy(surname, buff);
        cout << "Введите отчество" << endl;
        cin >> buff;
        if (strlen(buff) > 20) { throw length_error("Превышен лимит в 20 символов"); }
        strcpy(oname, buff);
        cout << "Введите депозит: ";
        sum = right_int();

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
        try {
        add_deposit(mas);
    }
        catch (length_error& e) {

            cout << e.what() << endl;
        }
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
    id = deposit::right_int();
    mas[id] + value;

}

void deposit::display(deposit mas[]) {
    cout << "Введите id" << endl;
    int m;
    m = right_int();
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

int deposit::samefio(deposit mas1[]) {
    char* n = new char[20];
    char* s = new char[20];
    char* o = new char[20];
    char* buff = new char[100];
    int id = -1;
    try {
        cout << "Введите имя" << endl;
        cin >> buff;
        if (strlen(buff) > 20) { throw length_error("Превышен лимит в 20 символов"); }
        strcpy(n, buff);
        cout << "Введите фамилию" << endl;
        cin >> buff;
        if (strlen(buff) > 20) { throw length_error("Превышен лимит в 20 символов"); }
        strcpy(s, buff);
        cout << "Введите отчество" << endl;
        cin >> buff;
        if (strlen(buff) > 20) { throw length_error("Превышен лимит в 20 символов"); }
        strcpy(o, buff);
        for (int i = 0; i < deposit::counter; i++) {
            if (strcmp(n, mas1[i].Getname()) == 0 && strcmp(s, mas1[i].Getsurname()) == 0 && strcmp(o, mas1[i].Getoname()) == 0) {
                id = mas1[i].deposnumber;
            }
            return id;
        }
    }
    catch (length_error& e) {
        cout << e.what() << endl;
    }

}

double deposit::right_int() {
    string buff;
    try {
        cin >> buff;
        for (int i = 0; i < buff.size(); i++) {
            if (isalpha(buff[i]) != 0) { throw 1; }
        }
        return stod(buff.c_str()); 
    }

    catch (int a) {
        cout << "неверное значение"<<endl;
        right_int();
    }
        
    
}

void deposit::write_off(deposit mas[]) {
    cout << "введите платеж" << endl;
    double n;
    n = right_int();
    cout << "введите id" << endl;
    double m = right_int();
    bool flag = false;
    try {
        for (int i = 0; i < counter; i++) {
            if (mas[i].deposnumber == m) {

                if (mas[i].sum < n) { throw 1; }
                mas[i] - n;
                flag = true;
                break;
            }
        }
        if (flag == false) {
            cout << "id отсутствует" << endl;
        }
    }
    catch(int a) {
        cout << "значение больше чем сумма" << endl;
    }
}
