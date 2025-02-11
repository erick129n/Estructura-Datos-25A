//Erick Manuel Gonzalez Carrillo

#include <iostream>
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32
#define TAM_MAX 8

using namespace std;

int* repetidos(int arreglo[], int tamanio);
int contador;
int main()
{
    int arreglo[TAM_MAX] = {3,5,3,8,4,1,5,7};
    int *ptr;
    ptr = &arreglo[0];
    for(int i = 0 ; i < TAM_MAX ; i++){
        cout << *(ptr+i) << endl;
    }

    ptr = repetidos(arreglo, TAM_MAX);
    cout << "repetidos: ";

    for(int i = 0 ; i < contador ; i++){
        cout << *(ptr+i) << ",";
    }
    return 0;
}

int* repetidos(int arreglo[], int tamanio){
    int* p = (int*)malloc(sizeof(int));
    int j;
    int arrAux[TAM_MAX];
    for(int i = 0 ; i < tamanio-1 ; i++){
        for(j = i ; j < tamanio-i-1 ; j++){
            if(arreglo[i] <= arreglo [j+1] && arreglo[i] >= arreglo[j+1]){
                arrAux[contador++] = arreglo[i];
            }
        }
    }
    p = &arrAux[0];
    return p;
}
