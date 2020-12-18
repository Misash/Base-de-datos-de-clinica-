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
        cout<<"1. LLenar triage.\n\n";
        cout<<"2. Historial medico.\n\n";
        cout<<"3. Volver atras\n\n";
        cout<<"Opci\242n: ";
        cin>>OpcionPac;
        system(CLEAR);
        switch(OpcionPac)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            Llenartriage();
            break;

        case 2:
            HistorialMedico();
            break;
            
        case 3:
            break;
        }
    }
    while(OpcionPac!=3);
}

void admin_pacientes::Llenartriage(){
	system(CLEAR);
	cout<<"\t\t\t\t***TRIAGE***\t\t\t\t\n\n";
	cout<<"\n";
	cout<<"Ingrese el DNI de paciente:";
	cout<<"Dni de paciente";
	cout<<"\n";
	cout<<"Ingrese la ALTURA del paciente (cm):";
	cin>>Altura;
	cout<<"\n";
	cout<<"Ingrese la PESO del paciente (kg):";
	cin>>Peso;
	cout<<"\n";
	cout<<"Temperatura";
	cout<<"\n";
	cout<<"Saturacion de oxigeno";
	cout<<"\n";
	cout<<"presion";
	cout<<"\n";
	cout<<"Alergias";
	pausa();
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
