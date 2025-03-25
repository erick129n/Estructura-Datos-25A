#include <iostream>
#include <limits>
#include "Lista.h"
#include "Persona.h"

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32


using namespace std;

enum MENU{INGRESO=1, BUSCAR_ID, BUSCAR_NOMBRE, BUSCAR_POS, MODIFICAR, ELIMINAR, SALIR};

int ctID = 1000;
int contador;

void menu(int& opcion);
void altaPersona();
void pedirDatosPersona(Persona& persona);
void buscarID();
void buscarNombre();
void buscarPosicion();
bool buscarPosicion(Persona& persona);
void modificarContacto();
bool validarEnteros(int& dato);
void eliminarContacto();
void listarAgenda(Lista<Persona> datos);
void pausita();

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
            case BUSCAR_NOMBRE: buscarNombre(); break;
            case BUSCAR_POS: buscarPosicion(); break;
            case MODIFICAR: modificarContacto(); break;
            case ELIMINAR: break;
            case SALIR: continue;
            default: cout << "Opcion no valida vuelve a intentarlo" << endl; break;
        }
        pausita();
    }while(opcion != SALIR);
    return 0;
}


void menu(int& opcion){
    cout << "Agenda v2.0." << endl;
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


bool validarEnteros(int& dato) {
    while (true) {
        cin >> dato;
        if (cin.fail()) {
            cin.clear();  // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada incorrecta
            cout << "Entrada no válida. Intenta de nuevo: ";
        } else {
            return true;
        }
    }
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

void buscarID(){
    cin.ignore();
    int id;
    agenda.print();
    cout << "Buscar contacto por ID" << endl;
    cout << "? ";
    validarEnteros(id);
    Lista<Persona> tempLista(agenda);
    while(!tempLista.isEmpty()){
        Persona tempPer;
        tempLista.removerDelInicio(tempPer);

        if(id == tempPer.getId()){
            showPersona(tempPer);
            cin.get();
            return;
        }
    }
    cout << "No se econtro el contacto con el id: " << id << endl;

}

void buscarNombre(){
    cin.ignore();
    string nombre;
    int contador =0;
    agenda.print();
    cout << "Buscar por nombre: " << endl;
    cout << "? ";
    getline(cin, nombre);
    Lista<Persona> tempLista(agenda);
    while(!tempLista.isEmpty()){
        Persona tempPer;
        tempLista.removerDelInicio(tempPer);
        if(!nombre.compare(tempPer.getNombre())){
            contador++;
            showPersona(tempPer);
        }
    }
    cout << "Se encontro (" << contador << ") contacto con el nombre " << nombre;
}

void buscarPosicion(){
    cin.ignore();
    int pos;
    int contador=0;
    agenda.print();
    cout << "Buscar por posicion" << endl;
    cout << "? ";
    validarEnteros(pos);
    Lista<Persona> tempLista(agenda);
    while(!tempLista.isEmpty()){
        Persona tempPer;
        tempLista.removerDelInicio(tempPer);
        if(pos-1 == contador){
            showPersona(tempPer);
            cin.get();
            return;
        }
        contador++;
    }
    cout << "No se encontraron contactos en la posicion: " << pos << endl;
}

bool buscarPosicion(Persona& persona){
    cin.ignore();
    int pos;
    int contador=0;
    agenda.print();
    cout << "Buscar por posicion" << endl;
    cout << "? ";
    validarEnteros(pos);
    Lista<Persona> tempLista(agenda);
    while(!tempLista.isEmpty()){
        Persona tempPer;
        tempLista.removerDelInicio(tempPer);
        if(pos-1 == contador){
            showPersona(tempPer);
            persona = tempPer;
            cin.get();
            return true;
        }
        contador++;
    }
    cout << "No se encontraron contactos en la posicion: " << pos << endl;
    return false;
}

void modificarContacto() {
    int posicion;
    cout << "Ingresa la posición del contacto a modificar: ";
    validarEnteros(posicion);

    Lista<Persona> tempLista;
    Persona temp;
    int contador = 0;
    bool encontrado = false;

    while (!agenda.isEmpty()) {
        agenda.removerDelInicio(temp);
        if (contador == posicion - 1) {  // Se encontró el contacto
            encontrado = true;
            cout << "Contacto encontrado. Ingresa los nuevos datos:\n";
            pedirDatosPersona(temp);  // Modificar datos
        }
        tempLista.insertarAlFinal(temp);
        contador++;
    }

    agenda = tempLista;  // Restaurar la lista

    if (encontrado) {
        cout << "Contacto actualizado correctamente.\n";
    } else {
        cout << "No se encontró el contacto en la posición indicada.\n";
    }
}


/// implementacion de eliminar contacto
void eliminarContacto() {
    int posicion;
    cout << "Ingresa la posición del contacto a eliminar: ";
    validarEnteros(posicion);

    Lista<Persona> tempLista;
    Persona temp;
    int contador = 0;
    bool encontrado = false;

    while (!agenda.isEmpty()) {
        agenda.removerDelInicio(temp);
        if (contador == posicion - 1) {  // Se encontró el contacto
            encontrado = true;
            cout << "Contacto eliminado con éxito.\n";
        } else {
            tempLista.insertarAlFinal(temp);  // Reinsertar solo los que no se eliminan
        }
        contador++;
    }

    agenda = tempLista;  // Restaurar la lista

    if (!encontrado) {
        cout << "No se encontró un contacto en la posición indicada.\n";
    }
}

void showPersona(Persona per){
    cout << "ID:" << per.getId() << endl;
    cout << "Nombre: " << per.getNombre() << endl;
    cout << "Telefono: " << per.getNumeroTelefono() << endl;
}

void pausita(){
    cin.ignore();
    cout << "Presiona entrar para continuar . . .";
    cin.get();
    system(CLEAR);

}
