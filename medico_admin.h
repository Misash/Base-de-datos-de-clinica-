
#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>

#include "Persona.cpp"

using namespace std;

class Medico: public Persona{
    private:
        string AreaMedica;
        int AreaM;
        string codigoMedico;
	    string Consultorio;
	    string Horario;
	    string Activo;
    public:
        void llenardatosmedicos();
        string CalcularAreaMedica(int opcion);
        string DefinirHorario(int opcion);
        int ContarMedicosArea (int area);
        void IngresarMedicos();
        void VerHorarioDoctores();
        Medico();
        ~Medico();
};
