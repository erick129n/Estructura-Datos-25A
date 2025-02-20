#include <iostream>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32

#include "FiguraGeometrica.h"
using namespace std;

enum MENU{CUADRADO=1, RECTANGULO, POLIGONO, SALIR};

void menu(int& opcion);
void pedirDatosCuadrado(FiguraGeometrica& fig);
void pedirDatosRectangulo(FiguraGeometrica& fig);
void pedirDatosPoligono(FiguraGeometrica& fig);
void conValoresPorDefecto(FiguraGeometrica fig);
void pausita();

int main()
{
    FiguraGeometrica cuadrado;
    FiguraGeometrica rectangulo;
    FiguraGeometrica poligono;
    int opcion;

    do{
        menu(opcion);
        system(CLEAR);
        switch(opcion){
            case CUADRADO:
                cout << "Calculo del area del cuadrado " << endl;
                pedirDatosCuadrado(cuadrado);
                cout << "Area: " << cuadrado.getArea(cuadrado.getLado(), cuadrado.getLado()) << endl;
                break;
            case RECTANGULO:
                cout << "Calculo del area del rectangulo " << endl;
                pedirDatosRectangulo(rectangulo);
                cout << "Area: " << rectangulo.getArea(rectangulo.getBase(), rectangulo.getAltura()) << endl;
                 break;
            case POLIGONO:
                 cout << "Calculo del area de un poligono " << endl;
                pedirDatosPoligono(poligono);
                cout << "Area: " << poligono.getArea(poligono.getApotema()) << endl;
                break;
            case SALIR: cout << "Saliendo . . ." << endl; continue;
            default: cout << "Opcion no valida vuelve a intentar." << endl; break;
        }
        pausita();

    }while(opcion != SALIR);
    return 0;
}


void menu(int& opcion){
    cout << "Calculo del Area de figuras geometricas v1.0" << endl;
    cout << "1. Cuadrado" << endl;
    cout << "2. Rectangulo" << endl;
    cout << "3. Poligono" << endl;
    cout << "4. Salir" << endl;
    cout << "Elige una opcion: ";
    cin >> opcion;
}

void pedirDatosCuadrado(FiguraGeometrica& fig){
    double lado;
    cout << "Dame el lado: ";
    cin >> lado;
    fig.setLado(lado);
}

void pedirDatosRectangulo(FiguraGeometrica& fig){
    double base, altura;
    cout << "Dame la base: ";
    cin >> base;
    cout << "Dame la altura: " ;
    cin >> altura;
    fig.setBase(base);
    fig.setAltura(altura);
}

void pedirDatosPoligono(FiguraGeometrica& fig){
    double lado;
    int numeroLados;
    cout << "Dame el numero de lados del poligono: ";
    cin >> numeroLados;
    cout << "Dame el tamanio de los lados: ";
    cin >> lado;
    fig.setNumeroLados(numeroLados);
    fig.setLado(lado);
}
void pausita(){
    cin.ignore();
    cout << "Presiona entrar para continuar. . . " << endl;
    cin.get();
    system(CLEAR);
}
