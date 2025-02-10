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


int* bubbleSort(int arreglo[], int tamanio);

int main()
{
    int arreglo[TAM_MAX] = {6,5,3,8,4,1,2,7};
    int* ptr;
    ptr=&arreglo[0];
    cout << "Arreglos." << endl;
    cout << "Arreglo desordenado: ";
    for(int i = 0 ; i < TAM_MAX ; i++){
        cout << *(ptr+i) << " ";
    }
    cout << endl << endl;
    ptr = bubbleSort(arreglo, TAM_MAX);
    cout << "Arreglo ordenado ascendente: ";
    for(int i = 0 ; i < TAM_MAX ; i++){
        cout << *(ptr+i) << " ";
    }
    cout << endl;
    return 0;
}


int* bubbleSort(int arreglo[], int tamanio){
    int* ptrArreglo = (int*)malloc(sizeof(int));
    int j;
    int aux;
    bool interruptor = true;
    for(int i = 0 ; i < tamanio-1 && interruptor; i++){
        interruptor = false;
        for(j = 0 ; j < tamanio-i-1 ; j++){

            if(arreglo[j] > arreglo[j+1]){
                interruptor = true;
                aux = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = aux;
            }
        }
    }

    ptrArreglo = &arreglo[0];
    return ptrArreglo;
}
