#include "Persona.h"

#include<iostream>

using namespace std;

Persona::Persona()
{
    //ctor
}

Persona::~Persona()
{
    //dtor
}

Persona::Persona(const Persona& other) {
    nombre = other.nombre;
    id = other.id;
    numeroTel = other.numeroTel;
}


ostream& operator<<(ostream& os, const Persona& p){
    os << "ID: "<<p.id << " Nombre: " <<p.nombre;
    return os;
}

void Persona::setNombre(string nombre){
    this->nombre = nombre;
}

void Persona::setId(int id){
    this->id = id;
}

bool Persona::setNumeroTel(string numeroTel){
    if(numeroTel.length() != 10) return false;
    for(char c : numeroTel){
        if(!isdigit(c)) return false;
    }
    this->numeroTel = numeroTel;
    return true;
}

string Persona::getNombre(){
    return nombre;
}

int Persona::getId(){
    return id;
}

string Persona::getNumeroTelefono(){
    return numeroTel;
}


