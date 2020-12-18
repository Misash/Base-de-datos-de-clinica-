//Administrador de sistemas en clinica

#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>

//invocar a los otros submenus

#include "Admin_empleados.cpp"
#include "admin_pacientes.cpp"
#include "admin_almacen.cpp"

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

using namespace std;

class menuadministrador
{
admin_empleados emple;
admin_pacientes paci;
admin_inventario alma;

public:
void MenuPrincipal();
};


void menuadministrador::MenuPrincipal(){
	int OpcionEmpl;
    do
    {
        system("cls");
        cout<<"\t\t\t\t***A.S.EMPLEADOS***\t\t\t\t\n\n";
        cout<<"1. Empleados.\n\n";
        cout<<"2. Pacientes\n\n";
        cout<<"3. Farmacia\n\n";
        cout<<"4. Cerrar el programa\n\n";
        cout<<"Opci\242n: ";
        cin>>OpcionEmpl;
        system(CLEAR);
        switch(OpcionEmpl){

        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            emple.MenuEmpleados();
            break;

        case 2:
            paci.MenuPacientes();
            break;

        case 3:
            alma.cargarInventario();
            alma.MenuInventarioM();
            break;

        case 4:
            break;
        }
    }
    while(OpcionEmpl!=4);
    alma.SalvarInventario();
}
