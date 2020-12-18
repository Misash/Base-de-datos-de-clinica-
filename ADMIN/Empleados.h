// class admin_empleados

#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>

#include "medicos_admin.cpp"

using namespace std;

class admin_empleados{
    Medico med;
	private:
	    string codigoEmpleado;
	    string codigoMedico;
	    string consultorio;
	    string horario;
	    string activo;

    public:

		void MenuEmpleados();
		void RegistroEmpleados();
		void VerEmpleados();
		void DespedirEmpleados();
		void IngresarMedicos();
		void VerHorarioDoctores();
};


