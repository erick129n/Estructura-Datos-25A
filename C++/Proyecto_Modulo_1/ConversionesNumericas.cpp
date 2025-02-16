#include "ConversionesNumericas.h"
#define BASE_A_DOS 2
#define BASE_A_DIECICES 16
#define BASE_OCTAL 8
#define BASE_DECIMAL 10

#include <iostream>
#include <cstring>
#include "Artimetica.h"
using namespace std;



void decimalaBinario(double* numero){
    int residuo, valor;
    valor = *numero;

    while(valor/BASE_A_DOS > 0){
        residuo = valor%BASE_A_DOS;
        valor /= BASE_A_DOS;
        cout << residuo;
    }
    if(valor <= 1){
        residuo = valor%BASE_A_DOS;
        cout << residuo;
    }
}

void decimalaHexadecimal(double* numero){
    int resido, valor;
    valor = *numero;
    while(valor/BASE_A_DIECICES > 0){
        resido = valor%BASE_A_DIECICES;
        valor /= BASE_A_DIECICES;
        if(resido >= 10){
            cout << 'A' + (resido-10);
        }else{
            cout << '0' + resido;
        }
    }
    if(resido >= 10){
        cout << 'A' + (resido-10);
    }else{
        cout << '0' + resido;
    }

}

void decimalaOctal(double* numero){
    int residuo, valor;
    valor = *numero;
    while(valor/BASE_OCTAL > 0){
        residuo = valor%BASE_OCTAL;
        valor /= BASE_A_DIECICES;
        cout << residuo;
    }
    cout << valor;
}

void binarioaDecimal(int* numero, size_t tam) {
    int resultado = 0;
    for (size_t i = 0; i < tam; i++) {
        if (numero[i] == 1) {
            double* numero2 = new double(BASE_A_DOS);
            int* potencia = new int(i);
            double* potenciaResultado = xElevadoAnPotencia(numero2, potencia);
            resultado += *potenciaResultado;
            delete numero2;
            delete potencia;
            delete potenciaResultado;
        }
    }

}

void hexadecimalaDecimal(char* numero, size_t tam) {
    int resultado = 0;
    for (size_t i = 0; i < tam; i++) {
        int valor = (numero[i] >= '0' && numero[i] <= '9') ? numero[i] - '0' :
                    (numero[i] >= 'A' && numero[i] <= 'F') ? numero[i] - 'A' + 10 :
                    (numero[i] >= 'a' && numero[i] <= 'f') ? numero[i] - 'a' + 10 : 0;
        double* numeroBase = new double(BASE_A_DIECICES);
        int* potencia = new int(tam - i - 1);
        double* potenciaResultado = xElevadoAnPotencia(numeroBase, potencia);
        resultado += valor * *potenciaResultado;
        delete numeroBase;
        delete potencia;
        delete potenciaResultado;
    }
    cout << "Número en Decimal: " << resultado << endl;
}

void octalaDecimal(int* numero, size_t tam) {
    int resultado = 0;
    for (size_t i = 0; i < tam; i++) {
        double* numeroBase = new double(BASE_OCTAL);
        int* potencia = new int(tam - i - 1);
        double* potenciaResultado = xElevadoAnPotencia(numeroBase, potencia);
        resultado += numero[i] * *potenciaResultado;
        delete numeroBase;
        delete potencia;
        delete potenciaResultado;
    }
    cout << "Número en Decimal: " << resultado << endl;
}

void octalaBinario(int* numero, size_t tam) {
    int decimal = 0;
    for (size_t i = 0; i < tam; i++) {
        double* numeroBase = new double(BASE_OCTAL);
        int* potencia = new int(tam - i - 1);
        double* potenciaResultado = xElevadoAnPotencia(numeroBase, potencia);
        decimal += numero[i] * *potenciaResultado;
        delete numeroBase;
        delete potencia;
        delete potenciaResultado;
    }

    int binario[32];
    int index = 0;
    while (decimal > 0) {
        binario[index++] = decimal % BASE_A_DOS;
        decimal /= BASE_A_DOS;
    }

    cout << "Número en Binario: ";
    for (int i = index - 1; i >= 0; i--) {
        cout << binario[i];
    }
    cout << endl;
}

void hexadecimalaBinario(char* numero, size_t tam) {
    int decimal = 0;
    for (size_t i = 0; i < tam; i++) {
        int valor = (numero[i] >= '0' && numero[i] <= '9') ? numero[i] - '0' :
                    (numero[i] >= 'A' && numero[i] <= 'F') ? numero[i] - 'A' + 10 :
                    (numero[i] >= 'a' && numero[i] <= 'f') ? numero[i] - 'a' + 10 : 0;
        double* numeroBase = new double(BASE_A_DIECICES);
        int* potencia = new int(tam - i - 1);
        double* potenciaResultado = xElevadoAnPotencia(numeroBase, potencia);
        decimal += valor * *potenciaResultado;
        delete numeroBase;
        delete potencia;
        delete potenciaResultado;
    }

    int binario[32];
    int index = 0;
    while (decimal > 0) {
        binario[index++] = decimal % BASE_A_DOS;
        decimal /= BASE_A_DOS;
    }

    cout << "Número en Binario: ";
    for (int i = index - 1; i >= 0; i--) {
        cout << binario[i];
    }
    cout << endl;
}

void binarioaOctal(int* numero, size_t tam) {
    int decimal = 0;
    for (size_t i = 0; i < tam; i++) {
        double* numeroBase = new double(BASE_A_DOS);
        int* potencia = new int(tam - i - 1);
        double* potenciaResultado = xElevadoAnPotencia(numeroBase, potencia);
        decimal += numero[i] * *potenciaResultado;
        delete numeroBase;
        delete potencia;
        delete potenciaResultado;
    }

    int octal[32];
    int index = 0;
    while (decimal > 0) {
        octal[index++] = decimal % BASE_OCTAL;
        decimal /= BASE_OCTAL;
    }

    cout << "Número en Octal: ";
    for (int i = index - 1; i >= 0; i--) {
        cout << octal[i];
    }
    cout << endl;
}

void binarioaHexadecimal(int* numero, size_t tam) {
    int decimal = 0;
    for (size_t i = 0; i < tam; i++) {
        double* numeroBase = new double(BASE_A_DOS);
        int* potencia = new int(tam - i - 1);
        double* potenciaResultado = xElevadoAnPotencia(numeroBase, potencia);
        decimal += numero[i] * *potenciaResultado;
        delete numeroBase;
        delete potencia;
        delete potenciaResultado;
    }

    char hexadecimal[32];
    int index = 0;
    while (decimal > 0) {
        int resto = decimal % BASE_A_DIECICES;
        hexadecimal[index++] = (resto < 10) ? ('0' + resto) : ('A' + (resto - 10));
        decimal /= BASE_A_DIECICES;
    }

    cout << "Número en Hexadecimal: ";
    for (int i = index - 1; i >= 0; i--) {
        cout << hexadecimal[i];
    }
    cout << endl;
}

