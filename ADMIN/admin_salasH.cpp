# include "admin_salasH.h"

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

void pausa2(){
    cout<<"\nPresiona Enter para continuar...";
    getch();
    system(CLEAR);
}

void error2(){
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}


void admin_salasH::MenuSalasHosp(){
	int OpcionSHosp;
    do
    {
        cout<<"\t\t\t\t***A.S.INVENTARIO***\t\t\t\t\n\n";
        cout<<"1. Designar paciente a sala medica.\n\n";
        cout<<"2. Volver atras\n\n";
        cout<<"Opci\242n: ";
        cin>>OpcionSHosp;
        system(CLEAR);
        switch(OpcionSHosp)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            DesignarSalaMedica();
            break;

        case 2:
            break;
        }
    }
    while(OpcionSHosp!=2);
}

void admin_salasH::DesignarSalaMedica(){
	system(CLEAR);
	cout<<"\t\t\t\t***Designar sala medica***\t\t\t\t\n\n";
	cout<<"\n";
	cout<<"FUNCIONA!!!!";
	pausa2();
}

