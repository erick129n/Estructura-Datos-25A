/*
    SIMULADOR BANCARIO

    En este proyecto se simulara el proceso y trabajo de un banco con uso de TDA's
    COLA.
    Nota: ESTE SIMULADOR ESTA DISEÑADO PARA EMULAR EN WINDOWS

    Procesos:
    1. El programa se inicializa antes de ingresar al banco. Para esta version, el
    ingreso estara limitado a la cantidad elegida por el usuario asi como
    los datos del cliente. Una ves que se asignen los clientes
    estaran en la entrada haciendo una fila general, a espera de su ticket.

    2. Ya terminando de solicitar los datos de todos los clientes, el cliente
        pedira si ticket a recepcion e ingresaran al banco. (en versiones futuras el usuario
                                                             podria saltarse este paso)

    3. Ya con el ticket, en la siguiente transicion, los clientes estaran dentro del banco
        donde se acomodaran segun a donde se dirigan (en versiones futuras habra una sola fila
        donde los clientes esperan su turno para cada puesto y no esperarlo de una sola fila)

    4. Existira una "Pantalla" donde se mosrtara el turno de cada cliente en el lugar correspondiente
        Si hay un cliente en la fila y el empleado esta disponible, entonces se extraera de la cola
        el cliente y se dirigira con el empleado.

    5. Los clientes seran atendidos en tiempos, como es una simulacion estos tendran seran atendidos
        en diferentes tiempos, unos duraran mas otros duraran menos.

    6. Terminando los clientes se van en esta version solo se borraran (se espera que se muevan a la salida en versiones futuras)
        entonces el empleado estara disponible y pasara el siguiente. El ciclo se repetira hasta vaciar todos los clientes.

    7. Tambien estaran los clientes que se se dirigan al ATM, solo estara disponible 1. Estos tendran registro distintos
        y se apila a la fila del ATM

    8. Terminando podemos reiniciar el proceso o salir.

    NOTA: ESTA ES LA VERSION BETA, POR LO QUE INICIARA UNA COLA DE CLIENTES


*/

#ifndef _WIN32
#error "Sistema operativo no soportado para este programa"
#endif // _WIN32

#include <iostream>
#include <limits>
#include <cstdlib>
#include <windows.h>
#include <windows.h>
#include "Cola.h"
#include "Cliente.h"
#include "Empleado.h"




#define CLEAR "cls"
#define MAX_CONTADORES 3
#define UN_SEGUNDO 1000 //conversion en milisegundos
using namespace std;

enum CONTADORES{CAJA=1, ATENCION_CLIENTE, GERENTE};
enum MENUPRINCIPAL{ENCOLAR=1, SOLICITAR_TICKET, ENVIAR_A_COLA, REGISTRO_ATM, SALIR};


void menuOpciones(int& opcion);
bool validarEnteros(int& dato);
void encolarClientes();
void pedirDatosCliente(Cliente& cliente);
void menuAndondeSeDirige();
void solicitarTickets();
///PROBABLEMENTE SE NECESITE INICIALIZAR EL PROGRAMA
//void inicializarElementos();


//inicialiacion de los empleados
Empleado gerente('G');
Empleado atencionCliente('D');
Empleado cajero('A');
Empleado recepcionista('R'); //recepcionista no es indispensable, podria no requerirlo
Cola <Cliente> colaEntrada;
Cola <Cliente> colaCaja;

int contadorId;
int contadores[MAX_CONTADORES]; //estos contadores seran los que tendra cada pila de objetos
int contadorCaja;

///VERSION SIN ANIMACIONES
int main()
{
    bool continuar;
    int opcion;
    cout << "SIMULADOR DE BANCO EN CONSOLA" << endl;
    continuar = false;
    do{
        opcion = 0;
        continuar = true;
        menuOpciones(opcion);
        switch(opcion){
        case ENCOLAR:
            encolarClientes();
            break;
        case SOLICITAR_TICKET:
            solicitarTickets(); //mostrara o guardara los turnos
            //hacer implementacion que guarda los clientes a las filas correspondientes
            cin.get();
            break;
        case ENVIAR_A_COLA:
            //logica para enviar los clientes a la cola
            cout << "En construccion :)" << endl;
            break;
        case REGISTRO_ATM:
            //logica para registrar clientes al atm
            cout << "En construccion :)" << endl;
            break;
        case SALIR: continuar = false; break; //si la opcion es salir terminar el programa
        default:
            //si no eligio ninguna de las opciones el programa regresara
            cout << "Opcion invalida vuelve a intentar. . . " <<endl;
            Sleep(UN_SEGUNDO);
            system(CLEAR);
            break;
        }
        system(CLEAR);

    }while(continuar);

    return 0;
}

void menuOpciones(int& opcion){
    cout << "Simulador de banco v.B.1.0" << endl;
    cout << ENCOLAR <<") Encolar clientes" << endl;
    cout << SOLICITAR_TICKET << ") Solicitar ticket a recepcion" << endl;
    cout << ENVIAR_A_COLA << ") Enviar a cola general de atencion" << endl;
    cout << REGISTRO_ATM << ") Registro y encolado de clientes ATM" << endl;
    cout << SALIR << ") Salir" << endl;
    cout << "Elige una opcion: ";
    validarEnteros(opcion);
}

void menuAndondeSeDirige();

//prueba que la entrada de datos sea valida
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

void encolarClientes(){
    int cantidad;
    cout << "Dame la cantidad de clientes: ";
    validarEnteros(cantidad);
    for(int  i = 0 ; i < cantidad ; i++){
        Cliente cliente;
        pedirDatosCliente(cliente); //llenamos los datos del cliente
        colaEntrada.enqueue(cliente); //despues los encolamos
    }

}

void menuAndondeSeDirige(){
    cout << "1) Caja" << endl;
    cout << "2) Atencion a clientes" << endl;
    cout << "3) Gerente" << endl;
}

void pedirDatosCliente(Cliente& cliente) {
    string nombre;
    int opcion;
    char seleccion;
    int turno;
    cout << "Dame el nombre del cliente: ";
    cin >> nombre; ///hacer funcion que valida que sean caracteres
    cin.get();  // Limpiar el buffer

    menuAndondeSeDirige();
    cout << "A donde se dirige: ";
    validarEnteros(opcion);

    // Asignar turno según la opción elegida
    switch(opcion) {
        case CAJA:
            seleccion = 'C'; //el identificador de la caja
            turno = contadores[CAJA]++; //guardara un conteo que representa los clientes que van a caja
            break;
        case ATENCION_CLIENTE:
            seleccion = 'T'; //identificador de atencion a clientes
            turno = contadores[ATENCION_CLIENTE]++; //guardara un conteo que representa los clientes que van a atencion a clientes
            break;
        case GERENTE:
            seleccion = 'G'; // identificador a gerente
            turno = contadores[GERENTE]++; //guardara un conteo que representa los clientes que van a gerente
            break;
        default:
            cout << "Error en la asignación de turnos" << endl;
            break;
    }

    cliente.setNombre(nombre);  // Asignamos el nombre del cliente
    cliente.setId(contadorId++);  // Asignamos un identificador único al cliente
    cliente.setIdTurno(seleccion); // Asignamos el identificador de turno
    cliente.setContTurno(turno); // Asignamos un contador por identidicador
}


///SIGUIENTE IMPLEMENTACION, GUARDARLOS EN COLAS CORRESPONDIENTES
void solicitarTickets(){
    cin.ignore();
    cout << "Solicitar tickets" << endl;

    //esta funcion sera la responsable de mover los clientes a las colas de los empleados
    //de momento solo extrae los clientes y los muestra
    Cliente cliente;
    while (!colaEntrada.estaVacia()) {  // Mientras haya clientes en la cola
        if (colaEntrada.dequeue(cliente)) {  // Extraemos el siguiente cliente
                 cout << "Turno: " << cliente.getIdTurno() << cliente.getContTurno()
                 << endl;
        } else {
            cout << "Error al extraer el cliente de la cola." << endl;
        }
    }
}
