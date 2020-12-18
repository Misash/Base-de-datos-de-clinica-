# include "Admin_empleados.h"

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

void pausa10(){
    cout<<"\nPresiona Enter para continuar...";
    getch();
    system(CLEAR);
}

void error10(){
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}

void llenardatosempleado(){
    string auxCodigo;
    cout<<"Ingrese codigo de empleado";cin>>codigoEmpleado;
    Activo="Yes"
    pausa10();
}
