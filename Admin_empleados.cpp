# include "Admin_Empleados.h"
#pragma once
//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

void pausa12(){
    cout<<"\nPresiona Enter para continuar...";
    getch();
    system(CLEAR);
}
void error12(){
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}

void admin_empleados::MenuEmpleados(){
	int OpcionEmpl;
    do
    {
        cout<<"\t\t\t\t***A.S.EMPLEADOS***\t\t\t\t\n\n";
        cout<<"1. Ingresar medicos.\n\n";
        cout<<"2. Ver horario de doctores.\n\n";
        cout<<"3. Volver atras\n\n";
        cout<<"Opci\242n: ";
        cin>>OpcionEmpl;
        system(CLEAR);
        switch(OpcionEmpl)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;
        case 1:
            IngresarMedicoscall();
            break;
        case 2:
            VerHorarioDoctorescall();
            break;

        case 3:
            break;
        }
    }
    while(OpcionEmpl!=3);
}

void admin_empleados::IngresarMedicoscall(){
   med.IngresarMedicos();
}

void admin_empleados::VerHorarioDoctorescall(){
    med.VerHorarioDoctores();
    med.ver_DatosPersonales();
    pausa12();
}

