// Lab10.4.cpp
// Михайлов Олександр
// Опрацювання рядків текстового файлу
// Варіант 24

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

void EnterStrToFile1(string* s, const int amount, ofstream& f1) {
    for (int i = 0; i < amount; i++) {
        cout << " " << i + 1 << " рядок: ";
        if (i == 0) {
            cin.get();
        }
        getline(cin, s[i]);
        string intoFile = s[i];
        f1 << intoFile << endl;
    }
}

void EnterStrToFile2(string* s, const int amount, ofstream& f2) {
    for (int i = 0; i < amount; i++) {
        cout << " " << i + 1 << " рядок: ";
        getline(cin, s[i]);
        string intoFile = s[i];
        f2 << intoFile << endl;
    }
}

void PrintSameRows(string* s1, string* s2, const int amount) {
    cout << "Рядки, які збігаються:" << endl;
    for (int i = 0; i < amount; i++) {
        if (s1[i] == s2[i]) {
            cout << s1[i] << endl;
        }
    }
}

void NotSameRowAmount(string* s1, string* s2, const int amount) {
    int NotSameRowAmount = 0;
    for (int i = 0; i < amount; i++) {
        if (s1[i] != s2[i]) {
            NotSameRowAmount++;
        }
    }
    cout << endl << "Кількість рядків, які не збігаються: " << NotSameRowAmount << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int fileRowAmount, menu;
    string file1Name, file2Name, file1help, file2help;

    cout << " Введіть назву першого файлу: "; cin >> file1help;
    cout << " Введіть назву другого файлу: "; cin >> file2help;

    file1Name = file1help + ".txt";
    file2Name = file2help + ".txt";

    ofstream f1;
    ofstream f2;

    f1.open(file1Name);
    f2.open(file2Name);

    cout << endl << " Файли успішно створено!" << endl << endl;

    do {
        cout << " Введіть кількість рядків у файлах: "; cin >> fileRowAmount;
        if (fileRowAmount < 1) {
            cout << " Кількість рядків не може бути меньше одного!" << endl;
        }
    } while (fileRowAmount < 1);

    string* f1str = new string[fileRowAmount];
    string* f2str = new string[fileRowAmount];

    cout << endl << " Введіть рядки у перший файл:" << endl;
    EnterStrToFile1(f1str, fileRowAmount, f1);

    cout << endl << " Введіть рядки у другий файл:" << endl;
    EnterStrToFile2(f2str, fileRowAmount, f2);
    
    cout << endl << " Рядки успішно введені!" << endl; 
    do {
        cout << endl << endl;
        cout << "Виберіть дію:" << endl;
        cout << "[1] - Вивести рядки, які збігаються" << endl;
        cout << "[2] - Вивести кількість рядків, які не збігаються" << endl;
        cout << "[0] - Завершити виконання програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menu;
        cout << endl << endl;

        switch (menu) {
        case 1:
            PrintSameRows(f1str, f2str, fileRowAmount);
            break;
        case 2:
            NotSameRowAmount(f1str, f2str, fileRowAmount);
            break;
        case 0:
            break;
        default:
            cout << " Ви ввели помилкове значення!" << endl;
        }
    } while (menu != 0);

    f1.close();
    f2.close();
    delete[] f1str;
    delete[] f2str;
    return 0;
}
