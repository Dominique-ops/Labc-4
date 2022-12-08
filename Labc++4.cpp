#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include "account.h"
#include "FIO.h"
#include "deposid.h"
#include "credit.h"

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
        //printf_s("- добавить к сумме(депозит)       7 -\n");
        printf_s("- Выход из программы              7 -\n");
        printf_s("                                     \n");
        printf_s("- Введите номер функции: ");
        while (scanf_s("%d", &item) != 1 || item > 8 || item < 1) {
            printf_s("- ошибка\n");
            printf_s("                          \n");
            printf_s("- Введите номер функции: ");
            while (fgetc(stdin) != '\n');
        }
        printf_s("                                   \n\n");
        switch (item)
        {
        case 1:
            deposit::add_deposit(mas1);
            break;
        case 2:
            credit::add_credit(mas2);
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
        }

    }
    return 0;
}


