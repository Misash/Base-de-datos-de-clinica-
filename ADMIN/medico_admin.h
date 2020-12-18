#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>

#include <Persona.cpp>
using namespace std;

class Medico: public Persona{
    private:
        string codigoMedico;
	    string Consultorio;
	    string Horario;
	    string Activo;
    public:
        void llenardatosmedicos();
        char* CalcularAreaMedica(int opcion);
        char* DefinirHorario(int opcion);
        int ContarMedicosArea (int area);
        Medico();
        ~Medico();
};
