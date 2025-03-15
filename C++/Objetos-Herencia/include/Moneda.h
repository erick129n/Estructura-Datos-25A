#ifndef MONEDA_H
#define MONEDA_H


class Moneda {
public:
    virtual double convertir() const = 0; // Funci�n virtual pura para convertir moneda.
    virtual ~Moneda() {}
};


#endif // MONEDA_H
