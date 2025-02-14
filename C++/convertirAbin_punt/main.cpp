#include <iostream>
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32

#define BASE_A_DOS 2
using namespace std;

int* convertirAbin(int* numero);
bool repetirAccion();
void imprimirBinario(int* ptrArray);

int main()
{
    int numero;
    int* ptr=NULL, *P;
    bool otraVez = true;
    do{
        cout << "Conversor de decimal a binario 2.0.v."<< endl;
        cout << "Dame el numero a convertir: ";
        cin >> numero;
        ptr = &numero;
        P = convertirAbin(ptr);
        cout << "Numero a binario: ";
        imprimirBinario(P);
        cout << endl;
        otraVez = repetirAccion();
        system(CLEAR);
    }while(otraVez);
    return 0;
}


bool repetirAccion(){
    char opcion;
    cout << "Ingresar otro numero? (S/N): ";
    cin >> opcion;
    if(opcion == 'S' || opcion == 's'){
        return true;
    }
    return false;
}

void imprimirBinario(int* ptrArray){

    for(int i = *ptrArray ; i >= 1 ; i--){
        cout << *(ptrArray+i) << " ";
    }
    cout << endl;
}

int* convertirAbin(int* numero){
    int* arrayBin = (int*)malloc(sizeof(int));
    int residuo;
    int cociente;
    int contador=0;
    int valor = *numero;
    while(valor/BASE_A_DOS > 0){
        cociente = valor/BASE_A_DOS;
        residuo = valor%BASE_A_DOS;
        valor = cociente;
        arrayBin[0] = ++contador;
        arrayBin[contador] = residuo;

    }
    if(valor <= 1){
        residuo = valor%BASE_A_DOS;
        arrayBin[0] = ++contador;
        arrayBin[contador] = residuo;
    }
    return arrayBin;
}
