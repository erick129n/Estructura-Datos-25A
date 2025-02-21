#ifndef TEMPERATURA_H
#define TEMPERATURA_H


class Temperatura
{
    public:
        Temperatura();
        void setEscala(double escala);
        void setOpcionEscala(int opcionEscala);
        double getEscala();
        int getOpcionEscala();

        double toCelsius(double escala, int opcionEscala);
        double toFahrenheit(double escala, int opcionEscala);
        double toKelvin(double escala, int opcionEscala);

    private:
        double escala;
        int opcionEscala;
};

#endif // TEMPERATURA_H
