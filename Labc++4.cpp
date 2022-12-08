#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include "account.h"
#include "FIO.h"
#include "deposid.h"
#include <exception>
#include "credit.h"
//#include "stdexcept"
using namespace std;




int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    class deposit* mas1 = new deposit[3];
    class credit* mas2 = new credit[3];
    deposit::load_deposit(mas1);
    credit::load_credit(mas2);
    while (true)
    {
        int  item = 0;
        printf_s("                                     \n");
        printf_s("- Добавить новый депозит          1 -\n");
        printf_s("- Добавить кредит                 2 -\n");
        printf_s("- Информация о депзозите          3 -\n");
        printf_s("- Информация о кредите            4 -\n");
        printf_s("- сортировка по сумме(депозит)    5 -\n");
        printf_s("- сортировка по сумме(кредит)     6 -\n");
        printf_s("- Выход из программы              7 -\n");
        printf_s("- выполнить платеж                8 -\n");
        printf_s("- списать с депозита              9 -\n");
        printf_s("- найти ФИО в депозите и кредите  6 -\n");
        printf_s("                                     \n");
        printf_s("- Введите номер функции: ");
        while (scanf_s("%d", &item) != 1 || item > 11 || item < 1) {
            printf_s("- ошибка\n");
            printf_s("                          \n");
            printf_s("- Введите номер функции: ");
            while (fgetc(stdin) != '\n');
        }
        printf_s("                                   \n\n");
        switch (item)
        {
        case 1:
            try {
                deposit::add_deposit(mas1);
            }
            catch (length_error& e) {

                cout << e.what() << endl;
            }
            break;
        case 2:

            try {
                credit::add_credit(mas2);
            }
            catch (length_error& e) {

                cout << e.what() << endl;
            }
            break;
        case 3:
            deposit::display(mas1);
            break;
        case 4:
            credit::display(mas2);
            break;
        case 5:
            deposit::sort(mas1);
            break;
        case 6:
            credit::sort(mas2);
            break;
        case 7:
            deposit::save_deposit(mas1);
            credit::save_credit(mas2);
            exit(0);
            break;

        case 8:
            credit::loan_payment(mas2);
            break;
        case 9:
            deposit::write_off(mas1);
            break;
        case 10:
            if (deposit::samefio(mas1) == -1 || credit::samefio(mas2) == -1) {
                cout << " отсутствуют" << endl;
            
            }
            else {
                cout << "id: " << deposit::samefio(mas1);
            }
            break;

        }
    }
    return 0;
}

