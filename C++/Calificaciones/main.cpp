//Erick Manuel Gonzalez Carrillo

#include <iostream>
#define TAM_MAX 5

using namespace std;

double calificaciones[TAM_MAX];
double *ptrReprobados[TAM_MAX];
double promedio;
double *ptrPromedio = &promedio;
double mejorCalificacion;
double *ptrMejorCalificacion = &mejorCalificacion;
int contador;
int *ptrContador = &contador;

void pedirCalificaciones();
void obtenerPromedio();
void getReprobados();
double* getMejorCalificacion();

int main() {
    pedirCalificaciones();
    obtenerPromedio();
    getReprobados();

    cout << "Reprobados: ";
    for (int i = 0; i < *ptrContador; i++) {
        cout << *ptrReprobados[i] << " ";
    }

    cout << endl;
    cout << "Cantidad de reprobados: " << *ptrContador << endl;
    cout << "Promedio general: " << *ptrPromedio << endl;
    cout << "Mejor calificación: " << *getMejorCalificacion() << endl;

    return 0;
}

void pedirCalificaciones() {
    for (int i = 0; i < TAM_MAX; i++) {
        cout << "Dame la calificacion " << i + 1 << ": ";
        cin >> *(calificaciones + i);
    }
}

void obtenerPromedio() {
    double suma = 0;
    for (int i = 0; i < TAM_MAX; i++) {
        suma += *(calificaciones + i);
    }
    *ptrPromedio = suma / TAM_MAX;
}

void getReprobados() {
    for (int i = 0; i < TAM_MAX; i++) {
        if (*(calificaciones + i) < 60) {
            *(ptrReprobados + *ptrContador) = (calificaciones + i);
            (*ptrContador)++;
        }
    }
}

double* getMejorCalificacion() {
    *ptrMejorCalificacion = *calificaciones;
    for (int i = 1; i < TAM_MAX; i++) {
        if (*(calificaciones + i) > *ptrMejorCalificacion) {
            *ptrMejorCalificacion = *(calificaciones + i);
        }
    }
    return ptrMejorCalificacion;
}
