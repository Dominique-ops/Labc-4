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

    class deposit* mas1 = new deposit[10];
    class credit* mas2 = new credit[10];
    while (true)
    {
        int  item = 0;
        printf_s("                                     \n");
        printf_s("- Добавить новый счет             1 -\n");
        printf_s("- Информация о счете              2 -\n");
        printf_s("- сортировка по алфавиту          3 -\n");
        printf_s("- добавить к сумме                4 -\n");
        printf_s("- Выход из программы              5 -\n");
        printf_s("                                     \n");
        printf_s("- Введите номер функции: ");
        while (scanf_s("%d", &item) != 1 || item > 6 || item < 1) {
            printf_s("- ошибка\n");
            printf_s("                          \n");
            printf_s("- Введите номер функции: ");
            while (fgetc(stdin) != '\n');
        }
        printf_s("                                   \n\n");
        switch (item)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
           
            break;
        case 5:
         
            break;
        }

    }
    return 0;
}


