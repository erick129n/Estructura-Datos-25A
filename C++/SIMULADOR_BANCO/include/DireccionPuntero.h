#ifndef DIRECCIONPUNTERO_H_INCLUDED
#define DIRECCIONPUNTERO_H_INCLUDED

#include "windows.h"
#include "iostream"

using namespace std;

enum CURSOR{DESACTIVAR= FALSE, ACTIVAR= TRUE};


void hideCursor(CURSOR activar){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hcon, &cursorInfo);
    cursorInfo.bVisible = activar;
    SetConsoleCursorInfo(hcon, &cursorInfo);
}

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


//FUNCION SOBRECARGADA PARA LIMPIAR SOLO EL AREA DE LOS PERSONASJES
void clearArea(int x, int* y){
    gotoxy(x, y[0]);   cout << "     ";  // Borra la cabeza
    gotoxy(x, y[1]); cout << "     ";  // Borra el torso y brazos
    gotoxy(x, y[2]); cout << "     ";  // Borra las piernas
}


#endif // DIRECCIONPUNTERO_H_INCLUDED
