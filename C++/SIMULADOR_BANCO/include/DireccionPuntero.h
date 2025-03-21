#ifndef DIRECCIONPUNTERO_H_INCLUDED
#define DIRECCIONPUNTERO_H_INCLUDED

#include "windows.h"
#include "iostream"

using namespace std;

enum CURSOR{DESACTIVAR= FALSE, ACTIVAR= TRUE};
enum COLORES{NEGRO, AZUL, VERDE, AQUA, ROJO, PURPURA, AMARILLO,
            BLANCO, GRIS, AZUL_CLARO, VERDE_CLARO, AQUA_CLARO,
            ROJO_CLARO, PURPURA_CLARO, AMARILLO_CLARO, BLANCO_BRILLANTE};


// variables globales, para evitar repetir codigo
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cursorInfo;
COORD dwPos;
CONSOLE_SCREEN_BUFFER_INFO csbi;

void hideCursor(CURSOR activar){
    GetConsoleCursorInfo(hcon, &cursorInfo);
    cursorInfo.bVisible = activar;
    SetConsoleCursorInfo(hcon, &cursorInfo);
}

void gotoxy(int x, int y){
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void gotox(int x){
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


void showVersion(const char* version){
    GetConsoleScreenBufferInfo(hcon, &csbi);
    dwPos = {csbi.dwSize.X-sizeof(version), csbi.dwSize.Y-1};
    SetConsoleCursorPosition(hcon, dwPos);
    cout << version << endl;
    gotoxy(0, 0);
}

void setCursorColor(int color){
    hideCursor(ACTIVAR);
    cursorInfo.dwSize = 100;
    SetConsoleTextAttribute(hcon, color);
}



#endif // DIRECCIONPUNTERO_H_INCLUDED
