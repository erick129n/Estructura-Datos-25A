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
        pedira su ticket a recepcion e ingresaran al banco. (en versiones futuras el usuario
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

/// ESTE CODIGO SE FUE A LA VERGA XDXDXDXDXDXDXDXDXDXD

#ifndef _WIN32
#error "Sistema operativo no soportado para este programa"
#endif // _WIN32

#include <iostream>
#include <limits>
#include <cstdlib>
#include <windows.h>
#include <windows.h>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <cmath>

#include <chrono>
#include <thread>

#include "Cola.h"
#include "Cliente.h"
#include "Empleado.h"
#include "AdmTurnos.h"
#include "DireccionPuntero.h"
#include "Animaciones.h"




#define MAX_CONTADORES 3
#define UN_SEGUNDO 1000 //conversion en milisegundos
#define UN_SEGUNDO_Y_MEDIO 1500 //conversion en milisegundos
#define MEDIO_SEGUNDO 500 //conversion en milisegundos
#define ID_GERENTE 'G' //constante que representa al gerente
#define ID_ATENCION_CLIENTE 'T' //constante que representa a atencion a cliente
#define ID_CAJERO 'C' //constante que representa al cajero
using namespace std;

enum CONTADORES{CAJA=1, ATENCION_CLIENTE, GERENTE};
enum MENUPRINCIPAL{ENCOLAR=1, SOLICITAR_TICKET, ENVIAR_A_COLA, REGISTRO_ATM, SALIR};


void inicializarPrograma();
void menuOpciones(int& opcion);

void pantallaDeTurnos();
void menuAndondeSeDirige();
string converirACadena(char id, int cont);
bool validarEnteros(int& dato);
int generarTiempoAleatorio();

void encolarClientes();
void pedirDatosCliente(Cliente& cliente);
void solicitarTickets();
void dirigirClienteACola(Cliente& cliente);


void enviarClienteAempleado();
bool lasColasTienenDatos();
bool quitarClientes();
void GuardarPosicionesEnX(Cliente& cliente, int& posX);

void pedirDatosParaAtm(Cliente& cliente);
void registroParaAtm();
bool vaciarColaATM();


//inicialiacion de los empleados
Empleado gerente(ID_GERENTE);
Empleado atencionCliente(ID_ATENCION_CLIENTE);
Empleado cajero(ID_CAJERO);
Empleado recepcionista('R'); //recepcionista no es indispensable, podria no requerirlo

//inicializacion de la TDA cola
Cola <Cliente> colaEntrada; //esta sera la cola general
Cola <Cliente> colaCaja; // la cola de caja
Cola <Cliente> colaAtencionCliente; //cola de atencion a clientes
Cola <Cliente> colaGerente; //cola para genrente
Cola <Cliente> ATM; //cola especial de cajero automatico
vector <string> listaTurnos;


AdmTurnos turnos;

int contadorId;
int contadores[MAX_CONTADORES]; //estos contadores seran los que tendra cada pila de objetos
int contadorAtm;
int posXInicial = 50;
int posXFinal = posXInicial;
int posXInicialDentroBanco[3];
///VERSION SIN ANIMACIONES
int main()
{
    bool continuar;
    int opcion;
    int posYdentroBanco[3] = {7, 8, 9};
    showVersion("v.B.2.0"); //muestra la version del simulador
    cout << "SIMULADOR DE BANCO EN CONSOLA" << endl;

    continuar = false;
    setCursorColor(VERDE);
    inicializarPrograma();
    do{
        opcion = 0;
        continuar = true;
        menuOpciones(opcion);

        switch(opcion){
        case ENCOLAR:
            personajeRecepcionista(); // muestra un recepcionista
            encolarClientes(); // encola los clientes y los anima

            break;
        case SOLICITAR_TICKET:
            if(colaEntrada.estaVacia()){
                gotoxy(40, 2); cout << "La entrada esta vacia no hay clientes por atender" << endl;
                Sleep(UN_SEGUNDO);
            }else
                solicitarTickets(); //mostrara y guardara los clientes en las colas
            break;
        case ENVIAR_A_COLA:
            // ANIMACION DONDE ENTRAN LOS CLIENTES EN CADA COLA.
            clearArea(0, 0, 120, 70);
            showVersion("v.B.2.0"); //muestra la version del simulador
            gotoxy(0, 0);

            //Sleep(UN_SEGUNDO);
            while(lasColasTienenDatos() && colaEntrada.estaVacia()){
                mostrarCajero(posXInicial);
                mostrarAtencionCliente(posXInicial);
                mostrarGerente(posXInicial);
                mostrarLosClientesEnCola(contadores, posXInicial, posYdentroBanco);
               //mostrarLosClientesEnCola(colaCaja);
               //mostrarLosClientesEnCola(colaAtencionCliente);
               //mostrarLosClientesEnCola(colaGerente);
                //simula que el cliente se va a con el empleado.
                enviarClienteAempleado();
                quitarClientes();
                /// aqui es donde estara la logica del borrado de clientes en cada lugar de donde estan los empleados
                //Sleep(UN_SEGUNDO);
            }
            gotoxy(0, 0); cout << "El banco se ha vaciado. Presiona cualquier tecla para continuar" << endl;
            cin .get();
            cin.ignore();
            clearArea(0, 0, 120, 70);
            break;
        case REGISTRO_ATM:
            //logica para registrar clientes al atm y encolarlos
            registroParaAtm();
            while(vaciarColaATM()){
                cout << "Siguiente cliente" << endl;
            }
            cout << "En construccion :)" << endl;
            break;
        case SALIR: continuar = false; continue; //si la opcion es salir terminar el programa
        default:
            //si no eligio ninguna de las opciones el programa regresara
            cout << "Opcion invalida vuelve a intentar. . . " <<endl;
            Sleep(UN_SEGUNDO);
            clearArea(0, 0, 40, 10);
            break;
        }
        clearArea(0, 0, 110, 10);
        gotoxy(0, 0);
    }while(continuar);

    return 0;
}

void inicializarPrograma(){
    gerente.setCliente(nullptr);
    cajero.setCliente(nullptr);
    atencionCliente.setCliente(nullptr);
    for(auto& c : contadores){
        contadores[c] = -1;
    }
}

void menuOpciones(int& opcion){
    cout << "Simulador de banco Banorte"  << endl;
    cout << ENCOLAR <<") Encolar clientes" << endl;
    cout << SOLICITAR_TICKET << ") Solicitar ticket a recepcion" << endl; // quitar opcion
    cout << ENVIAR_A_COLA << ") Enviar a cola general de atencion" << endl; //quitar opcion
    cout << REGISTRO_ATM << ") Registro y encolado de clientes ATM" << endl;
    cout << SALIR << ") Salir"  << endl;
    cout << "Elige una opcion: ";
    validarEnteros(opcion);
}


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
    gotoxy(40, 0); cout << "Dame la cantidad de clientes: ";
    validarEnteros(cantidad);
    for(int  i = 0 ; i < cantidad ; i++){
        Cliente cliente;

        posXFinal = animarPersona(cliente, posXInicial);//animacion donde entra el cliente
        pedirDatosCliente(cliente); //llenamos los datos del cliente
        clearArea(40, 1, 40, 10); //limpia la entrada de datos
        colaEntrada.enqueue(cliente); //despues los encolamos

    }
    //posXInicial += 5; //inecesario
    Sleep(UN_SEGUNDO);
}

void menuAndondeSeDirige(){
    gotoxy(40, 2); cout << "1) Caja" << endl;
    gotoxy(40, 3); cout << "2) Atencion a clientes" << endl;
    gotoxy(40, 4); cout << "3) Gerente" << endl;
}

void pedirDatosCliente(Cliente& cliente) {
    string nombre;
    int opcion;
    char seleccion;
    int turno;
    gotoxy(40, 1); cout << "Dame el nombre del cliente: ";
    cin >> nombre; ///hacer funcion que valida que sean caracteres
    cin.get();  // Limpiar el buffer

    menuAndondeSeDirige();
    gotoxy(40, 5); cout << "A donde se dirige: ";
    validarEnteros(opcion);

    // Asignar turno según la opción elegida
    switch(opcion) {
        case CAJA:
            seleccion = ID_CAJERO; //el identificador de la caja
            turno = contadores[CAJA]++; //guardara un conteo que representa los clientes que van a caja
            break;
        case ATENCION_CLIENTE:
            seleccion = ID_ATENCION_CLIENTE; //identificador de atencion a clientes
            turno = contadores[ATENCION_CLIENTE]++; //guardara un conteo que representa los clientes que van a atencion a clientes
            break;
        case GERENTE:
            seleccion = ID_GERENTE; // identificador a gerente
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
    string str = converirACadena(seleccion, turno);
    listaTurnos.push_back(str); //guarda la lista de turnos;
}

//convierte los turnos en cadenas string de los turnos para mayor flexibilidad
string converirACadena(char id, int cont){
    stringstream ss;
    ss << id;
    ss << cont;
    string str = ss.str();
    return str;
}


void solicitarTickets(){
    cin.ignore();
    gotox(40); cout << "Solicitar tickets" << endl;
    int i = 1 ;
    int nuevaPos=0;
    //esta funcion sera la responsable de mover los clientes a las colas de los empleados
    Cliente cliente;
    while (!colaEntrada.estaVacia()) {  // Mientras haya clientes en la cola
        if (colaEntrada.dequeue(cliente)) {  // Extraemos el siguiente cliente
                nuevaPos = cliente.getPosX();
                 gotoxy(40, i ++);cout << "Turno: " << cliente.getIdTurno() << cliente.getContTurno()
                 << endl;
                 dirigirClienteACola(cliente); //lo mueve a otra cola
                hideCursor(DESACTIVAR);
                Sleep(UN_SEGUNDO);
                clearArea(nuevaPos, cliente.getPosY());
                if(nuevaPos < 66){
                    nuevaPos = animarColaClientes(cliente);
                }
                Sleep(generarTiempoAleatorio());
                clearArea(nuevaPos, cliente.getPosY());
                posXFinal +=4;

                hideCursor(ACTIVAR);

        } else {
            cout << "Error al extraer el cliente de la cola." << endl;
        }
    }
    posXInicial = 50;
}

//mueve a los clientes a las colas correspondientes
void dirigirClienteACola(Cliente& cliente){
    //pantallaDeTurnos();
    //int posYdentroBanco[3] = {7, 8, 9};
    char idTurno = cliente.getIdTurno();
    switch(idTurno){
        case ID_CAJERO:
            colaCaja.enqueue(cliente);
            break;
        case ID_ATENCION_CLIENTE:
            colaAtencionCliente.enqueue(cliente);
            break;
        case ID_GERENTE:
            colaGerente.enqueue(cliente);
            break;
        default: cout << "El cliente " << cliente.getNombre() << " no se le asigno turno" << endl;
    }
}


void pantallaDeTurnos(){
    cout << "Siguientes: " << endl;
    for(auto& siguiente : listaTurnos){
        cout << siguiente << endl;
    }
    cout << "En turno: " << endl;
    //si los empleados tienen un cliente, mostrara el turno si no no mostrara nada
    turnos.mostrarClienteEnTurno(&cajero);
    turnos.mostrarClienteEnTurno(&gerente);
    turnos.mostrarClienteEnTurno(&atencionCliente);

}


void enviarClienteAempleado(){
    Cliente cliente1, cliente2, cliente3;
    if(lasColasTienenDatos()){ //si las colas aun tienen clientes
        colaCaja.dequeue(cliente1); //se desapila de la cola
        colaAtencionCliente.dequeue(cliente2);
        colaGerente.dequeue(cliente3);
        turnos.asignarClienteAEmpleado(&cliente1, &cajero); //se dirigen al empleado correspondiente
        turnos.asignarClienteAEmpleado(&cliente2, &atencionCliente);
        turnos.asignarClienteAEmpleado(&cliente3, &gerente);
    }else{
        return;
    }

}


bool lasColasTienenDatos(){
    return !colaAtencionCliente.estaVacia() || !colaCaja.estaVacia() || !colaGerente.estaVacia();

}


//con el tiempo que sera random quitara los clientes en las Colas
bool quitarClientes(){
    if(!lasColasTienenDatos()){
        return false;
    }else{
        //aqui se supone que ira con respecto a la animaciones
        //con tiempos aleatorios simulando que cada cliente dura lo que debe de durar
        Sleep(generarTiempoAleatorio());
        turnos.desasignarTurno(&cajero);
        Sleep(generarTiempoAleatorio());
        turnos.desasignarTurno(&atencionCliente);
        Sleep(generarTiempoAleatorio());
        turnos.desasignarTurno(&gerente);
        return true;
    }

}

//generara numeros aleatorios en segundos
int generarTiempoAleatorio(){
    unsigned int numeroRandom = 0;
    srand(time(0));
    numeroRandom = rand() % 3000;
    return numeroRandom;

}



void pedirDatosParaAtm(Cliente& cliente){
    string nombre;
    cout << "Nombre: ";
    cin >> nombre;
    cin.get();
    cliente.setContTurno(contadorAtm++);
    cliente.setNombre(nombre);
    cliente.setId(contadorId++);
    cliente.setIdTurno('R');
}

void registroParaAtm(){
    int cant;
    cout << "Registrar clientes en ATM" << endl;
    cout << "Cuantos clientes van a ATM";
    validarEnteros(cant);
    for(int i = 0 ; i < cant ; i++ ){
        Cliente cliente;
        pedirDatosParaAtm(cliente);
        ATM.enqueue(cliente);
    }
    cout << "clientes ingresados con exito" << endl;

}


bool vaciarColaATM(){
    if(ATM.estaVacia()){
        cout << "ATM esta libre" << endl;
        return false;
    }else{
        Cliente cliente;
        Sleep(generarTiempoAleatorio());
        if(ATM.dequeue(cliente)){
            cout << "Termina el cliente" << endl;
        }else{
            cout << "ATM esta libre" << endl;
        }
        return true;
    }

}

void GuardarPosicionesEnX(Cliente& cliente, int& posX){
    posX -=4;
    int posFinal = posX;

    int tempX = posX;
    auto tiempoPrevio = chrono::high_resolution_clock::now();
    for(int i = 0 ; i < 22 ; i++){
        auto tiempoActual = chrono::high_resolution_clock::now();
        chrono::duration<float> deltaTime = tiempoActual - tiempoPrevio; //hacemos la variable detlatime
        tiempoPrevio = tiempoActual;
        float velocidad = 11.0f;
        tempX += velocidad * deltaTime.count();
        Sleep(50);
        posFinal = tempX+i;
    }
    cliente.posX(posFinal);

}

