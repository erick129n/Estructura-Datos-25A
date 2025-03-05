// Yen.h
#ifndef YEN_H_INCLUDED
#define YEN_H_INCLUDED

#include "Moneda.h"

class Yen : public Moneda {
public:
    Yen(double cantidad);
    double convertir() const override;
};

#endif // YEN_H_INCLUDED
