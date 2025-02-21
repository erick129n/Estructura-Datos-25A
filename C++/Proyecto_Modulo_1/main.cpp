#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstddef>

#include "Artimetica.h"
#include "ConversionesNumericas.h"

#define TIEMPO_MILISEGUNDOS_PAUSADO 1000
#define TAM_MAXIMO 10
#define OPERADOR_SUMA "+"
#define OPERADOR_RESTA "-"
#define OPERADOR_MULTIPLICACION "*"
#define OPERADOR_DIVISION "/"
#define OPERADOR_RESIDUO "%"
#define VALOR_POR_DEFECTO 2
#define STR_SUMA "suma"
#define STR_RESTA "resta"
#define STR_MULTIPLICACION "multiplicacion"
#define STR_DIVISION "division"
#define STR_RESIDUO "residuo"
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32

#ifdef _WIN32
    #include <windows.h>
    void pausita(unsigned int milisegundos){
        Sleep(milisegundos);
    }
#else
    void pausita(unsigned int milisegundos){
        struct timespec tiempo;
        tiempo.tv_sec = milisegundos / 1000;
        tiempo.tv_nsec = (milisegundos % 1000) * 1000000;
        nanosleep(&tiempo, NULL);
    }
#endif

using namespace std;

enum MENU{SALIR, SUMA, RESTA, MULTIPLICACION, DIVISION, RESIDUO, X_ELEVADO, FACTORIAL,
    X_ELEVADO_Y, RAIZ_CUADRADA, COSENO, SENO, TANGENTE, CONVERSIONES};

enum MENU_CONVERSIONES{DEC_BIN=14, BIN_DEC, DEC_OCT, OCT_DEC, DEC_HEX, HEX_DEC,
    BIN_OCT, OCT_BIN, BIN_HEX, HEX_BIN, REGRESAR};

void pausar();
void menu(int& opcion);
void menuConversiones(int& opcion);
double* procesarUnDato(const string& datos);

bool esdigito(const char* numero);
double* procesarDatos(const string& datos, const char* operador);
void convertirDatos(const char* cadena, double* variableAGuardar);
void pedirDatos(int opcion, const char* operacion);
size_t tamanioArreglo;

class AdministrarArtimetico{
    private:
        double* numero;
        string datos;

    public:
        AdministrarArtimetico() { };
        AdministrarArtimetico(double* numero,string datos){
            this-> numero = numero;
            this-> datos = datos;
        }
        double getNumero(){
            return *numero;
        }
        string getDatos(){
            return datos;
        }
        void pedirDatos(int opcion, const char* operacion);
};

void AdministrarArtimetico::pedirDatos(int opcion, const char* operacion) {
    string datos;
    double* numeros = new double[tamanioArreglo];
    double* resultado;
    cout << endl;
    cout << "Nota: si ingresas operadores de otro tipo, la calculadora los ignorara." << endl;
    cout << "Ingresa datos: ";
    cin >> datos;

    numeros = procesarDatos(datos, operacion);

    switch(opcion) {
        case SUMA:
            resultado = operar(numeros, tamanioArreglo, suma_op);
            cout << "Resultado: " << *resultado << endl;
            break;
        case RESTA:
            resultado = operar(numeros, tamanioArreglo, resta_op);
            cout << "Resultado: " << *resultado << endl;
            break;
        case MULTIPLICACION:
            resultado = operar(numeros, tamanioArreglo, multiplicacion_op);
            cout << "Resultado: " << *resultado << endl;
            break;
        case DIVISION:
            resultado = operar(numeros, tamanioArreglo, division_op);
            cout << "Resultado: " << *resultado << endl;
            break;
        case RESIDUO:
            resultado = operar(numeros, tamanioArreglo, residuo_op);
            cout << "Resultado: " << *resultado << endl;
            break;
        default:
            break;
    }

    delete[] numeros;
}

int main()
{
    int opcion;
    bool opcSalir = false;
    AdministrarArtimetico admin;
    do{
        opcSalir = true;
        menu(opcion);
        switch(opcion){
        case SUMA:
                admin.pedirDatos(opcion, OPERADOR_SUMA);
             break;
        case RESTA:
            admin.pedirDatos(opcion, OPERADOR_RESTA);
            break;
        case MULTIPLICACION:
            admin.pedirDatos(opcion, OPERADOR_MULTIPLICACION);
            break;
        case DIVISION:
            admin.pedirDatos(opcion, OPERADOR_DIVISION);
            break;
        case RESIDUO:
            admin.pedirDatos(opcion, OPERADOR_RESIDUO);
            break;
        case X_ELEVADO: break;
        case FACTORIAL: break;
        case X_ELEVADO_Y: break;
        case RAIZ_CUADRADA: break;
        case COSENO: break;
        case SENO: break;
        case TANGENTE: break;
        case DEC_BIN:
            break;
        case BIN_DEC:
                string datos;
                double* numeros = new double[tamanioArreglo];
                cout << endl;
                cout << "Nota: si ingresas operadores de otro tipo, la calculadora los ignorara." << endl;
                cout << "Ingresa datos: ";
                cin >> datos;
                numeros = procesarUnDato(datos);
                decimalaBinario(numeros);
                delete[] numeros;
            break;
        case DEC_OCT: break;
        case OCT_DEC: break;
        case DEC_HEX: break;
        case HEX_DEC: break;
        case BIN_OCT: break;
        case OCT_BIN: break;
        case BIN_HEX: break;
        case HEX_BIN: break;
        case REGRESAR:
            cout << "Regresando. . .";
            pausita(TIEMPO_MILISEGUNDOS_PAUSADO);
            system(CLEAR);
             break;
        case SALIR: cout << "Saliendo. . . "; opcSalir = false; break;
        default:
            cout << "Opcion no reconocida, vuelve a intntentarlo" << endl;
            pausar();
            break;
        }
        cout << endl;
        pausar();
    }while(opcSalir);

    return 0;
}

void menu(int& opcion){
    cout << "Calculadora v1.0." << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;
    cout << "5. Residuo" << endl;
    cout << "6. X numero elevado al cuadrado" << endl;
    cout << "7. Factorial" << endl;
    cout << "8. X numero elevado a la N potencia" << endl;
    cout << "9. Raiz cuadrada" << endl;
    cout << "10. Coseno" << endl;
    cout << "11. Seno" << endl;
    cout << "12. Tangente" << endl;
    cout << "13. Conversiones numericas" << endl;
    cout << "0. Salir " << endl;

    cout << "Seleccion a una opcion: ";
    cin >> opcion;
    if(opcion == CONVERSIONES){
        system(CLEAR);
        menuConversiones(opcion);
        opcion+=CONVERSIONES+1;
    }
}

void menuConversiones(int& opcion){
    opcion = 0;
    cout << "Converisones: " << endl;
    cout << "1. Decimal a binario" << endl;
    cout << "2. Binario a decimal" << endl;
    cout << "3. Decimal a octal" << endl;
    cout << "4. Octal a Decimal" << endl;
    cout << "5. Decimal a Hexadecimal" << endl;
    cout << "6. Hexadecimal a decimal" << endl;
    cout << "7. Binario a octal" << endl;
    cout << "8. Binario a hexadecimal" << endl;
    cout << "9. Hexadecial a binario" << endl;
    cout << "10. Regresar al menu principal" << endl;
    cout << "Selecciona una opcion: ";
    cin >> opcion;
}

void pausar(){
    cin.ignore();
    cout << "Presiona entrar para continuar . . .";
    cin.get();
    system(CLEAR);
}

bool esdigito(const char* cadena) {
    while (*cadena) {
        if (!isdigit(*cadena)) {
            return false;
        }
        ++cadena;
    }
    return true;
}

double* procesarDatos(const string& datos, const char* operador) {
    tamanioArreglo = 0;
    size_t tamanio = datos.length();
    double* datosNumericos = new double[tamanio];
    char* cadena = new char[tamanio + 1];
    size_t prev_pos = 0;
    size_t pos = 0;

    while ((pos = datos.find_first_of(operador, prev_pos)) != string::npos) {
        string scad = datos.substr(prev_pos, pos - prev_pos);
        strcpy(cadena, scad.c_str());
        double numero = strtod(cadena, nullptr);
        if (numero != 0.0 || (cadena[0] == '0' && cadena[1] == '\0')) {
            datosNumericos[tamanioArreglo++] = numero;
        } else {
            cout << "Error al convertir el número: " << cadena << endl;
        }

        prev_pos = pos + 1;
    }

    string scad = datos.substr(prev_pos);
    strcpy(cadena, scad.c_str());
    double numero = strtod(cadena, nullptr);
    if (numero != 0.0 || (cadena[0] == '0' && cadena[1] == '\0')) {
        datosNumericos[tamanioArreglo++] = numero;
    } else {
        cout << "Error al convertir el número: " << cadena << endl;
    }

    delete[] cadena;
    return datosNumericos;
}

double* procesarUnDato(const string& datos){
    tamanioArreglo = 0;
    size_t tamanio = datos.length();
    double* datosNumericos = new double[tamanio];
    char* cadena = new char[tamanio + 1];
    size_t prev_pos = 0;
    size_t pos = 0;

    while ((pos = datos.find_first_of("+-*/", prev_pos)) != string::npos) {
        string scad = datos.substr(prev_pos, pos - prev_pos);
        strcpy(cadena, scad.c_str());
        double numero = strtod(cadena, nullptr);
        if (numero != 0.0 || (cadena[0] == '0' && cadena[1] == '\0')) {
            datosNumericos[tamanioArreglo++] = numero;
        } else {
            cout << "Error al convertir el número: " << cadena << endl;
        }

        prev_pos = pos + 1;
    }

    string scad = datos.substr(prev_pos);
    strcpy(cadena, scad.c_str());
    double numero = strtod(cadena, nullptr);
    if (numero != 0.0 || (cadena[0] == '0' && cadena[1] == '\0')) {
        datosNumericos[tamanioArreglo++] = numero;
    } else {
        cout << "Error al convertir el número: " << cadena << endl;
    }

    delete[] cadena;
    return datosNumericos;
}
