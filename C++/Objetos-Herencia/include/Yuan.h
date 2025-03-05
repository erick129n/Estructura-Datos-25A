// Yuan.h
#ifndef YUAN_H_INCLUDED
#define YUAN_H_INCLUDED

#include "Moneda.h"

class Yuan : public Moneda {
public:
    Yuan(double cantidad);
    double convertir() const override;
};

#endif // YUAN_H_INCLUDED
