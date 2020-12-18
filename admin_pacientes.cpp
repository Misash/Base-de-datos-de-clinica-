# include "admin_pacientes.h"

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

void pausa();
void error();

void admin_pacientes::MenuPacientes(){
	int OpcionPac;
    do
    {
        cout<<"\t\t\t\t***A.S.PACIENTES***\t\t\t\t\n\n";
        cout<<"1. Historial medico.\n\n";
        cout<<"2. Volver atras\n\n";
        cout<<"Opci\242n: ";
        cin>>OpcionPac;
        system(CLEAR);
        switch(OpcionPac)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;
        case 1:
            HistorialMedico();
            break;

        case 2:
            break;
        }
    }
    while(OpcionPac!=2);
}


void admin_pacientes::HistorialMedico(){
	system(CLEAR);
	cout<<"\t\t\t\t***Historial Medico***\t\t\t\t\n\n";
	cout<<"\n";
	cout<<"Ingrese el DNI de paciente:";
	cout<<"DNI";
	cout<<"\n";
	cout<<"Nombre: ??????? ?????";
	cout<<"\n";
	cout<<"Edad: ??????? ?????";
	cout<<"\n";
	cout<<"Altura: ??????? ?????";
	cout<<"\n";
	cout<<"Peso: ??????? ?????";
	cout<<"\n";
	cout<<"Area Medica: ??????? ?????";
	cout<<"\n";
	cout<<"Sintomas: ??????? ?????";
	cout<<"\n";
	pausa();
}
