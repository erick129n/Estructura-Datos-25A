#include <iostream>
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32

#define BASE_DIECISEIS 16
#define TAM_MAX_CAR 128

using namespace std;

char* convertirAHexadecimal(int* numero);
bool volverAOperar();
void imprimirNumero(char* n);

int main()
{
    int numero;
    int *ptr=nullptr;
    char *P;
    bool continuar = true;
    do{
        cout << "Converitdor de decimal a Hexadecimal 2.0.v." << endl;
        cout << "Dame el numero a convertir: ";
        cin >> numero;
        ptr = &numero;

        P = convertirAHexadecimal(ptr);
        imprimirNumero(P);
        continuar = volverAOperar();
        system(CLEAR);
    }while(continuar);
    return 0;
}

bool volverAOperar(){
    char opcion;
    cout << "Ingresar otro numero? (S/N): ";
    cin >> opcion;
    if(opcion == 'S' || opcion == 's'){
        return true;
    }
    return false;
}


char* convertirAHexadecimal(int* numero) {
    int residuo, valor, contador = 0;
    valor = *numero;

    int temp = valor;
    while (temp > 0) {
        contador++;
        temp /= BASE_DIECISEIS;
    }

    char* arreglo = (char*)malloc((contador + 1) * sizeof(char));
    if (arreglo == NULL) return NULL;
    arreglo[0] = contador;

    for (int i = 1; i <= contador; i++) {
        residuo = valor % BASE_DIECISEIS;
        valor /= BASE_DIECISEIS;

        if (residuo >= 10) {
            arreglo[i] = 'A' + (residuo - 10);
        } else {
            arreglo[i] = '0' + residuo;
        }
    }

    return arreglo;
}

void imprimirNumero(char* n){
    for(int i  = *n ; i >= 0 ; i--){
        cout << n[i];
    }
    cout << endl;

}

