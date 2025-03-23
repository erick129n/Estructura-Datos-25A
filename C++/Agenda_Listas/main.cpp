#include <iostream>
#include <limits>
#include "Lista.h"
#include "Persona.h"


using namespace std;

enum MENU{INGRESO=1, BUSCAR_ID, BUSCAR_NOMBRE, BUSCAR_POS, MODIFICAR, ELIMINAR, SALIR};

int ctID = 1000;
int contador;

void menu(int& opcion);
void altaPersona();
void pedirDatosPersona(Persona& persona);
void buscarID();
bool validarEnteros(int& dato);
void listarAgenda(Lista<Persona> datos);

void showPersona(Persona per);


Lista<Persona> agenda;



int main()
{
    int opcion;
    do{
        menu(opcion);
        system("cls");
        switch(opcion){
            case INGRESO: altaPersona(); break;
            case BUSCAR_ID: buscarID(); break;
            case BUSCAR_NOMBRE: break;
            case BUSCAR_POS: break;
            case MODIFICAR: break;
            case ELIMINAR: break;
            case SALIR: continue;
            default: cout << "Opcion no valida vuelve a intentarlo" << endl; break;
        }
        cin.ignore();
        system("cls");
    }while(opcion != SALIR);
    return 0;
}


void menu(int& opcion){
    cout << INGRESO <<") Agregar conacto" << endl;
    cout << BUSCAR_ID <<") Buscar por ID" << endl;
    cout << BUSCAR_NOMBRE <<") Bucar por nombre" << endl;
    cout << BUSCAR_POS << ") Buscar por posicion" << endl;
    cout << MODIFICAR << ") Modificar" << endl;
    cout << ELIMINAR << ") Eliminar contacto" << endl;
    cout << SALIR << ") Salir" << endl;
    cout << "Elige una opcion: ";
    validarEnteros(opcion);

}


bool validarEnteros(int& dato){
    bool entradaValida = false;
    while(!entradaValida){
        cin >> dato;
        if(cin.fail()){
            cin.clear(); //limpia el estado del error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignora el resto de la linea
        }else{
            entradaValida = true;
        }
    }
    return entradaValida;
}


void altaPersona(){
    cout << "Agregar contacto" << endl;
    Persona nuevoContacto;
    pedirDatosPersona(nuevoContacto);
    agenda.insertarAlFinal(nuevoContacto);
}


void pedirDatosPersona(Persona& persona){
    cin.ignore();
    string nombre;
    string numero;
    int ID;

    cout << "Dame el nombre: ";
    getline(cin, nombre);
    do {
        cout << "Dame el numero de telefono (10 digitos): ";
        getline(cin, numero);

        if (!persona.setNumeroTel(numero)) {
            cout << "El número debe contener 10 dígitos numéricos.\n";
        }
    } while (!persona.setNumeroTel(numero));

    ctID++;
    contador++;
    ID = ctID;
    persona.setNombre(nombre);
    persona.setId(ID);
}

void listarAgenda(Lista<Persona> datos){
    Persona persona;
    while(!datos.isEmpty()){
        datos.removerDelFinal(persona);

    }
}

/// funcion sin completar
void buscarID(){
    int id;
    agenda.print();
    cout << "Buscar contacto por ID" << endl;
    cin >> id;
    Lista<Persona> tempLista;
    tempLista = agenda;
    while(!tempLista.isEmpty()){
        Persona tempPer;
        tempLista.removerDelInicio(tempPer);

        if(id == tempPer.getId()){
            showPersona(tempPer);
        }
    }
    cin.get();

}

void showPersona(Persona per){
    cout << "ID:" << per.getId() << endl;
    cout << "Nombre: " << per.getNombre() << endl;
    cout << "Telefono: " << per.getNumeroTelefono() << endl;
}
