//Erick Manuel Gonzalez Carrillo

#include <iostream>
#include <iomanip>
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif // _WIN32
#define TAM_MAX 30
#define MAX_REGISTROS 3
#define MAX_OPCIONES 5
#define C_0 0
#define NO_EXISTE_POSICION -1
using namespace std;

struct Agenda{
    int id;
    char nombre[TAM_MAX];
    char direccion[TAM_MAX];
    char telefono[TAM_MAX];
}agenda[MAX_REGISTROS];

void agregarContacto(int);
void altaAgenda();
void modificarDatos(int);
void eliminarContacto(int);
void borrarUnContacto();
int buscarContacto(int);
bool elContactoExiste(int);
void actualizarContacto();
int menu();
void mostrarContacto(int);
bool hayEspaciolibre();
void listarAgenda();
void pausa();

int contador, index=1;


int main()
{
    int opcion;
    do{
        opcion = menu();
        switch(opcion){
        case 1:
            altaAgenda();
            break;
        case 2:
            borrarUnContacto();
            break;
        case 3:
            listarAgenda();
            break;
        case 4:
            actualizarContacto();
            break;
        case 5:
            cout << "Saliendo. . ." << endl;
            continue;
        default:
            cout << "Opcion no valida" << endl;
        }
        pausa();

    }while(opcion != MAX_OPCIONES);
    return 0;
}


int menu(){
    int opcion;
    cout << "1. Alta de un contacto" << endl;
    cout << "2. Baja de un contacto" << endl;
    cout << "3. Listar agenda"  << endl;
    cout << "4. Actualizar contacto" << endl;
    cout << "5. Salir" << endl;
    cout << "\nElige una opcion: ";
    cin >> opcion;
    system(CLEAR);
    return opcion;
}


void agregarContacto(int indice){
    agenda[contador].id = indice;
    modificarDatos(contador++);
}

void altaAgenda(){
    cout << "Alta de una agenda \n" << endl;
    if(hayEspaciolibre()){
        agregarContacto(index++);
        cout << "\nContacto registrado con exito" << endl;
    }else{
        cout << "La agenda esta llena" << endl;
    }
}

bool hayEspaciolibre(){
    bool hayEspacio;
    if(contador > MAX_REGISTROS){
        hayEspacio = false;
    }else{
        hayEspacio = true;
    }
    return hayEspacio;
}

void listarAgenda(){
    cout << "Listado de agenda \n" << endl;
    cout << "#" << setw(10) << "ID" << setw(20) << "Nombre" << setw(30) << "Direccion" << setw(20) << "Telefono" << endl;
    cout << endl;
    int i = 0;
    if(i < contador){
            for(i=0 ; i < contador ; i++){
                cout << i+1 << setw(10);
                cout << agenda[i].id << setw(20);
                cout << agenda[i].nombre << setw(30);
                cout << agenda[i].direccion << setw(20);
                cout << agenda[i].telefono << endl;
        }
    }else{
        cout << "No hay agenda por registrar" << endl;
    }

}

void actualizarContacto(){
    cout << "Acutalizar contacto \n" << endl;
    listarAgenda();
    int idBuscar, posicion=NO_EXISTE_POSICION;
    cout << "Dame el id del Contacto: ";
    cin >> idBuscar;
    posicion = buscarContacto(idBuscar);
    if(elContactoExiste(posicion)){
        modificarDatos(posicion);
    }else{
        posicion = NO_EXISTE_POSICION;
        cout << "El Contacto no existe" << endl;
    }
}

void mostrarContacto(int indice){
    cout << "Mostrar Agenda" << endl;
    cout << "ID:" << agenda[indice].id << endl;
    cout << "Nombre: " << agenda[indice].nombre << endl;
    cout << "Direccion: " << agenda[indice].direccion << endl;
    cout << "No. Telefono: " << agenda[indice].telefono << endl;
}

void eliminarContacto(int indice){
    if(indice < contador){
        for(int i = indice ; i < contador-1 ; i++){
            if (i <= contador){
                agenda[i] = agenda[i+1];
            }
        }
        contador--;
    }
}

void borrarUnContacto(){
    int id;
    cout << "Borrar un contacto \n" << endl;
    listarAgenda();
    cout << "Dame el ID del Contacto a borrar: ";
    cin >> id;
    if(elContactoExiste(buscarContacto(id))){
        eliminarContacto(buscarContacto(id));
        cout << "Contacto eliminado con exito!" << endl;
    }
}
bool elContactoExiste(int indice){
    bool tieneDatos;
    if(MAX_REGISTROS < indice || indice > MAX_REGISTROS){
        cout << "Fuera de rango" << endl;
        if(indice > contador){
            cout << "No existe este contacto" << endl;
            tieneDatos = false;
        }else{
            tieneDatos = true;
        }
    }
    return tieneDatos;
}

int buscarContacto(int id){
    int x=C_0,posicion=NO_EXISTE_POSICION;
    bool ban=false;
    while(x<MAX_REGISTROS && ban==false){
      if(agenda[x].id==id){
          ban=true;
          posicion=x;
      }
     x++;
    }
    return posicion;
}

void modificarDatos(int posicion){
    cin.ignore();
    cout << "Dame el nombre: ";
    cin >> agenda[posicion].nombre;
    cin.get();
    cout << "Dame la direccion: ";
    cin >> agenda[posicion].direccion;
    cin.get();
    cout << "Dame el numero de telefono: ";
    cin >> agenda[posicion].telefono;
}
void pausa(){
    cin.ignore();
    cout << "Presiona entrar para continuar. . . "<< endl;
    cin.get();
    system(CLEAR);
}

