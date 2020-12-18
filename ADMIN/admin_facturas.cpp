#include "admin_facturas.h"

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

void pausa3(){
    cout<<"\nPresiona Enter para continuar...";
    getch();
    system(CLEAR);
}

void error3(){
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}


void admin_facturas::MenuEntregaFact(){
	int OpcionEFact;
    do
    {
        cout<<"\t\t\t\t***A.S.Entrega de Facturas***\t\t\t\t\n\n";
        cout<<"1. Entregar Factura.\n\n";
        cout<<"2. Volver atras\n\n";
        cout<<"Opci\242n: ";
        cin>>OpcionEFact;
        system(CLEAR);
        switch(OpcionEFact)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            EntregarFactura();
            break;

        case 2:
            break;
        }
    }
    while(OpcionEFact!=2);
}

void admin_facturas::EntregarFactura(){
	system(CLEAR);
	cout<<"\t\t\t\t***Entregar factura***\t\t\t\t\n\n";
	cout<<"\n";
	cout<<"FUNCIONA!!!!";
	pausa3();
}
