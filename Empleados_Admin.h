#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>

#include "Persona.cpp"
using namespace std;

class Empleado: public Persona{
    private:
        string codigoEmpleado;
	    string Activo;
    public:
        void llenardatosempleado();
        Empleado();
        ~Empleado();
};
