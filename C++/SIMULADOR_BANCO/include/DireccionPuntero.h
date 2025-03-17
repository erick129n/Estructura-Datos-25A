#ifndef DIRECCIONPUNTERO_H_INCLUDED
#define DIRECCIONPUNTERO_H_INCLUDED

#include "windows.h"
#include "iostream"

using namespace std;

void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void gotox(int x){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = 0;
    SetConsoleCursorPosition(hcon, dwPos);
}

void clearArea(int x, int y, int ancho, int largo) {
    for (int i = 0; i < largo; i++) {
        gotoxy(x, y + i);
        cout << string(ancho, ' '); // Rellena con espacios en blanco
    }
}


#endif // DIRECCIONPUNTERO_H_INCLUDED
