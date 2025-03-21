#ifndef ANIMACIONES_H_INCLUDED
#define ANIMACIONES_H_INCLUDED

#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;


void moverPersonaje(int x, int* y, int& ban);
void animarPersona(int& posX, int* posY);
void animarPersona(Cliente& cliente, int& posXInicial);
void personajeRecepcionista();
void borrarPersonajeEnRecepcion();
void mostrarLosClientesEnCola(int* contador, int x, int* y);
void borrarClientesEnRecepcion(int& posXFinal,int* posY);
void moverY(int* y);
void mostrarGerente(int x);
void mostrarCajero(int x);
void mostrarAtencionCliente(int x);
int posFinalX[3];

///CODIGO LOCO Y ASQUEROSO :(
//aqui es donde se realiza la animacion real, recibe como referencia al cliente, para que guarde su posicion
//aplicamos tambien deltatime para que el reloj no afecte en la animacion  del movimiento del personaje
///PROBABLEMENTE NO NECESITE GUARDAR LAS POSICIONES DE CADA CLIENTE
void animarPersona(Cliente& cliente, int& posXInicial) {
     posXInicial-=4; // para que los clientes no colisionen, se reducen 4 espacios en x
     int posY[3] = {20, 21, 22}; // son las posiciones donde se situaran las personajes. /Deberan ser costantes
     cliente.posX(posXInicial); //guarda la posicion
     cliente.posY(posY);
     int tempX = cliente.getPosX(); // hacemos una variable que guarde la posicoin de x para mayor flexibilidad
     static int ban = 1; // una bandera estatica, para que no afecte en el movimiento de los demas personajes
     hideCursor(DESACTIVAR); //desactivamos el cursor, asi la animacion se vera limpia
     auto tiempoPrevio = chrono::high_resolution_clock::now();
     for(int j = 0 ; j < 12 ; j++){
        auto tiempoActual = chrono::high_resolution_clock::now();
        chrono::duration<float> deltaTime = tiempoActual - tiempoPrevio; //hacemos la variable detlatime
        tiempoPrevio = tiempoActual;
        float velocidad = 10.0f;
        tempX += velocidad * deltaTime.count(); //calculamos el delta time con respecto a la velocidad de movimiento
        moverPersonaje(tempX+j, cliente.getPosY(), ban);
        this_thread::sleep_for(chrono::milliseconds(50)); // pequenio retardo de 50 milisegundos
     }

     hideCursor(ACTIVAR); //activamos el cursor
}


void animarPersona(int& posX, int* posY) {
     posX-=4;
     int tempX = posX; // hacemos una variable que guarde la posicoin de x para mayor flexibilidad
     static int ban = 1; // una bandera estatica, para que no afecte en el movimiento de los demas personajes
     hideCursor(DESACTIVAR); //desactivamos el cursor, asi la animacion se vera limpia
     auto tiempoPrevio = chrono::high_resolution_clock::now();
     for(int j = 0 ; j < 12 ; j++){
        auto tiempoActual = chrono::high_resolution_clock::now();
        chrono::duration<float> deltaTime = tiempoActual - tiempoPrevio; //hacemos la variable detlatime
        tiempoPrevio = tiempoActual;
        float velocidad = 10.0f;
        tempX += velocidad * deltaTime.count(); //calculamos el delta time con respecto a la velocidad de movimiento
        moverPersonaje(tempX+j, posY, ban);
        this_thread::sleep_for(chrono::milliseconds(50)); // pequenio retardo de 50 milisegundos
     }

     hideCursor(ACTIVAR); //activamos el cursor
}


//esta funcion hace que simule el movimiento
void moverPersonaje(int x, int* y, int& ban){
    if (ban == 0) {
        clearArea(x, y);  // Limpia ANTES de dibujar
        gotoxy(x, y[0]);   cout << "  0 ";
        gotoxy(x, y[1]);   cout << " /|\\\n";
        gotoxy(x, y[2]);   cout << " / \\\n";
        ban = 1;
    } else {
        ban = 0;
        clearArea(x, y);
        gotoxy(x, y[0]); cout << "  0";
        gotoxy(x, y[1]); cout << " /|\\\n";
        gotoxy(x, y[2]); cout << " //\n";  // Moviendo correctamente la pierna

    }
}

void personajeRecepcionista(){
    gotoxy(72, 18);cout << "+-recep-+" ;
    gotoxy(72, 19);cout <<"|-------|" ;
    gotoxy(72, 20);cout <<"|   o   |";
    gotoxy(72, 21);cout <<"|  /|\\  |";
    gotoxy(72, 22);cout <<"|-------|";
    gotoxy(72, 23);cout <<"|>>>>>>>|";
    gotoxy(72, 24);cout <<"+-------+";


}

///FUNCION DESABILITADA, SI TODO FUNICONA CORRECTAMENTE, MEJORAMOS ESTA FUNCION
void animarColaClientes(Cola<Cliente> cola) {
    if (cola.estaVacia()) return; // Si no hay clientes, no animamos nada.
    static int ban = 1;
    Cliente clienteAtendido;
    if (!cola.dequeue(clienteAtendido)) return; // Extraemos al primer cliente de la cola

    // Borrar su posición de la pantalla
    clearArea(clienteAtendido.getPosX()+4, clienteAtendido.getPosY());

    vector<Cliente> clientesRestantes;

    // Extraemos los demás clientes y los desplazamos visualmente
    while (!cola.estaVacia()) {
        Cliente cliente;
        if (cola.dequeue(cliente)) {
            // Borrar la posición actual del cliente
            clearArea(cliente.getPosX(), cliente.getPosY());

            // Mover a la nueva posición (más cerca del inicio de la cola)
            int nuevaPosX = cliente.getPosX() - 4;
            cliente.posX(nuevaPosX);

            // Dibujar en la nueva posición
            moverPersonaje(nuevaPosX, cliente.getPosY(), ban);

            // Guardar en la lista temporal
            clientesRestantes.push_back(cliente);

            // Pequeño retardo para animar el movimiento
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    // Volvemos a insertar los clientes en la cola con sus nuevas posiciones
    for (Cliente& cliente : clientesRestantes) {
        cola.enqueue(cliente);
    }
}



/*
    Borra los personajes que estan en la animacion, simulando que se desplazan en la cola
    Pero en realidad borra desde el ultimo, o el de atras, hasta terminar con todos los personajes

*/
void borrarClientesEnRecepcion(int& posXFinal,int* posY){
    posXFinal += 4;
    hideCursor(DESACTIVAR);
    clearArea(posXFinal+1, posY);
    hideCursor(ACTIVAR);
}

void borrarClientes(int& posXFinal, int* posY){
    posXFinal +=4;
    hideCursor(DESACTIVAR);
    clearArea(posXFinal+1, posY);
    hideCursor(ACTIVAR);
}

void mostrarLosClientesEnCola(int* contador, int x, int* y) {
    hideCursor(DESACTIVAR);
    mostrarCajero(x);
    mostrarAtencionCliente(x);
    mostrarGerente(x);
    int tempy = y[0];
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < contador[i]; j++) {
            int tempX = x - (j * 5);
            int tempY[3] = {y[0], y[1], y[2]};
            animarPersona(tempX, tempY);  // Pasamos x correctamente
            posFinalX[i-1] = tempX;
        }
        moverY(y);  // Asegurar que actualiza la posición Y
        gotoxy(x, tempy + 6);  // Esto podría no ser necesario si moverY() ya cambia la posición
    }
    hideCursor(ACTIVAR);
}

void moverY(int* y){
    for(int i = 0 ; i < 3 ; i++){
        y[i] = y[i]+4;
    }
}

void mostrarGerente(int x){
    x+=12;
        gotoxy(x, 15);cout << "+-Gerente-+" ;
    gotoxy(x, 16);cout <<"|---------|" ;
    gotoxy(x, 17);cout <<"|    o    |";
    gotoxy(x, 18);cout <<"|   /|\\   |";
    gotoxy(x, 19);cout <<"+---------+";
}

void mostrarCajero(int x){
    x+=12;
    gotoxy(x, 5);cout << "+-Cajero-+" ;
    gotoxy(x, 6);cout <<"|---------|" ;
    gotoxy(x, 7);cout <<"|    o    |";
    gotoxy(x, 8);cout <<"|   /|\\   |";
    gotoxy(x, 9);cout <<"+---------+";
}

void mostrarAtencionCliente(int x){
    x+=12;
    gotoxy(x, 10);cout << "+-Atencion-+" ;
    gotoxy(x, 11);cout <<"|---------|" ;
    gotoxy(x, 12);cout <<"|    o    |";
    gotoxy(x, 13);cout <<"|   /|\\   |";
    gotoxy(x, 14);cout <<"+---------+";
}

#endif // ANIMACIONES_H_INCLUDED
