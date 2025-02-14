#include <iostream>
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32

#define BASE_DIECISEIS 16

using namespace std;

void convertirAHexadecimal(int numero);
bool volverAOperar();

int main()
{
    int numero;
    bool continuar = true;
    do{
        cout << "Converitdor de decimal a Hexadecimal 1.0.v." << endl;
        cout << "Dame el numero a convertir: ";
        cin >> numero;
        convertirAHexadecimal(numero);
        cout << endl;
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


void convertirAHexadecimal(int numero){
    int residuo;
    if(numero == 0){
        return;
    }
    residuo = numero%BASE_DIECISEIS;

    if(numero/BASE_DIECISEIS > 0){
        convertirAHexadecimal(numero/BASE_DIECISEIS);
    }
    if(residuo >= 10){
        switch(residuo){
            case 10: cout << "A"; break;
            case 11: cout << "B"; break;
            case 12: cout << "C"; break;
            case 13: cout << "D"; break;
            case 14: cout << "E"; break;
            case 15: cout << "F"; break;
            default: cout << residuo; break;

        }
    }else{
        cout << residuo;
    }
}
