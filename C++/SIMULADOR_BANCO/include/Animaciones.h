#ifndef ANIMACIONES_H_INCLUDED
#define ANIMACIONES_H_INCLUDED

#include <vector>
#include <iostream>
using namespace std;


void moverPersonaje(int x, int* y, int& ban);
void animarPersona(Cliente& cliente, int& posXInicial);
void personajeRecepcionista();
void borrarPersonajeEnRecepcion();

class Cliente;

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
void animarColaClientes(Cola<Cliente>& cola) {
    if (cola.estaVacia()) return; // Si no hay clientes, no animamos nada.
    static int ban = 1;
    Cliente clienteAtendido;
    if (!cola.dequeue(clienteAtendido)) return; // Extraemos al primer cliente de la cola

    // Borrar su posición de la pantalla
    clearArea(clienteAtendido.getPosX(), clienteAtendido.getPosY());

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
}

#endif // ANIMACIONES_H_INCLUDED
