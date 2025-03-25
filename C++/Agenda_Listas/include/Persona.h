#ifndef PERSONA_H
#define PERSONA_H
#include <istream>
using namespace std;

class Persona
{
    public:
        Persona();
        Persona(const Persona& other);

        virtual ~Persona();
        void setNombre(string nombre);
        void setId(int id);
        bool setNumeroTel(string numeroTel);
        string getNumeroTelefono();
        string getNombre();
        int getId();
        friend ostream& operator<<(ostream& os, const Persona& p);

    protected:

    private:
        string nombre;
        int id;
        string numeroTel;
};

#endif // PERSONA_H
