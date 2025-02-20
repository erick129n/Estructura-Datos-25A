#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

class FiguraGeometrica
{
    public:
        FiguraGeometrica();
    FiguraGeometrica(double base, double altura);
        FiguraGeometrica(double lado);
        FiguraGeometrica(double lado, int numeroLados);
        void setBase(double base);
        void setAltura(double altura);
        void setLado(double lado);
        void setNumeroLados(int numeroLados);

        double getAltura();
        double getBase();
        double getPerimetro();
        double getApotema();
        double getLado();
        double getPerimetro(double base, double altura);
        double getPerimetro(int numeroLados,double lado);
        double getArea(double base,double  altura);
        double getArea(double apotema);
    protected:

    private:
        double base;
        double altura;
        double lado;
        double apotema;
        int numeroLados;
        double area;
        double perimetro;


};

#endif // FIGURAGEOMETRICA_H
