///Calculo de n es multiplo de N -Erick Manuel Gonzalez Carrillo
#include <iostream>

#define C_0 0
#define C_1 1
#define C_2 2

using namespace std;


bool *multiplo(int*, int*);

int main()
{
    int *ptra=NULL, *ptrb=NULL;
    bool *esMultiplo;
    int a, b;
    cout << "Determinar si un numero es multiplo de N numero" << endl;
    cout << "Ingresa el numero: ";
    cin >> a;
    cout << "Ingresa el numero:  ";
    cin >> b;
    ptra = &a;
    ptrb = &b;
    esMultiplo = (multiplo(ptra, ptrb));
    if(*esMultiplo){
        cout << *ptra << " es multiplo de " << *ptrb;
    }else{
        cout << *ptra << " no es multiplo de " << *ptrb;
    }


    return 0;
}

bool *multiplo(int* a, int *b){
    int* residuo = (int*)malloc(sizeof(int));
    bool* esMultiplo = (bool*)malloc(sizeof(bool));
    *esMultiplo = false;
    *residuo = *a % *b;
    if(*residuo == 0){
        *esMultiplo = true;
    }else{
        *esMultiplo = false;
    }
    return esMultiplo;
}
