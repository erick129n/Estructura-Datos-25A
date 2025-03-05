// Euro.h
#ifndef EURO_H_INCLUDED
#define EURO_H_INCLUDED

#include "Moneda.h"

class Euro : public Moneda {
public:
    Euro(double cantidad);
    double convertir() const override;
};

#endif // EURO_H_INCLUDED
