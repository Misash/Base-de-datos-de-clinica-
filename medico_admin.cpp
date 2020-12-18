# include "medico_admin.h"

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

void pausa9(){
    cout<<"\nPresiona Enter para continuar...";
    getch();
    system(CLEAR);
}

void error9(){
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}



Medico::Medico(){
    cout << "\n>>Medico Creado...\n";
}

Medico::~Medico(){
    cout << "\n>>Medico Eliminado...\n";
}

void Medico::llenardatosmedicos(){
    string auxCodigo, numero, auxcmsp="00";
    int aux1=0, aux2=0,aux3=0;
        fflush(stdin);
        cin.ignore();
        cout<<"Ingresa el area medica del medico: ";
        cout<<"\n01.Cardiologia";
        cout<<"\n02.Neumologia";
        cout<<"\n03.Oncologia";
        cout<<"\n04.Hematologia";
        cout<<"\n05.Dermatologia";
        cout<<"\n06.Oftalmologia";
        cout<<"\n07.Urologia";
        cout<<"\n08.Nefrologia";
        cout<<"\n09.Reumologia";
        cout<<"\n10.Medicina general";
        cout<<"\nOpcion: ";cin>>aux1;
        cin.ignore();
        AreaMedica=CalcularAreaMedica(aux1);
        aux2=ContarMedicosArea(aux1);
        cout<<"\nnumero de medicos: "<<aux2;
        if (aux2<10){
            numero="0"+to_string(aux2);
        }else if(aux2>10){
            numero="0"+to_string(aux2);
        }
        cout <<numero << endl;
        cout<<"\nDNI="<<DNI<<endl;
        codigoMedico=AreaMedica+"-20-"+numero+"-"+DNI[4]+DNI[5]+DNI[6]+DNI[7];
        AreaM = stoi(AreaMedica);
        cout<<"\nCodigo medico: "<<codigoMedico;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el horario del medico: ";
        cout<<"\n01.8-14";
        cout<<"\n02.14-22";
        cout<<"\n03.22-24";
        cout<<"\nopcion: ";cin>>aux3;
        Horario=DefinirHorario(aux3);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el consultorio del medico: ";
        getline(cin,Consultorio);
        cout<<"\n\n";
        fflush(stdin);
        Activo="1";
        cout<<"\n\n";
    pausa9();
}

string Medico::CalcularAreaMedica(int opcion){
    string opcelegida;
    bool Listo=false;
    do{
        switch(opcion){
        default:
            cout<<"Ingrese una opcion valida";
            break;
        case 1:
            cout<<"01. Cardiologia";
            opcelegida="01";
            Listo=true;
            break;
        case 2:
            cout<<"02. Neumologia";
            opcelegida="02";
            Listo=true;
            break;
        case 3:
            cout<<"03. Oncologia";
            opcelegida="03";
            Listo=true;
            break;
        case 4:
            cout<<"04. Hematologia";
            opcelegida="04";
            Listo=true;
            break;
        case 5:
            cout<<"05. Dermatologia";
            opcelegida="05";
            Listo=true;
            break;
        case 6:
            cout<<"06. Oftalmologia";
            opcelegida="06";
            Listo=true;
            break;
        case 7:
            cout<<"07. Urologia";
            opcelegida="07";
            Listo=true;
            break;
        case 8:
            cout<<"08. Nefrologia";
            opcelegida="08";
            Listo=true;
            break;
        case 9:
            cout<<"09. Reumatologia";
            opcelegida="09";
            Listo=true;
            break;
        case 10:
            cout<<"10. Medicina general";
            opcelegida="10";
            Listo=true;
            break;
        }
    }
    while(Listo==false);

    return opcelegida;
}

string Medico::DefinirHorario(int opcion){
    string opcelegida;
    bool Listo=false;
    do{
        switch(opcion){
        default:
            cout<<"Ingrese una opcion valida";
            break;
        case 1:
            cout<<"01. 8-14";
            opcelegida="8-14";
            Listo=true;
            break;
        case 2:
            cout<<"02. 14-22";
            opcelegida="14-22";
            Listo=true;
            break;
        case 3:
            cout<<"03. 22-24";
            opcelegida="22-24";
            Listo=true;
            break;
        }
    }
    while(Listo==false);

    return opcelegida;
}

int Medico::ContarMedicosArea(int area){
    int i=0, aux1;
    ifstream lectura;
    string _DNI, _AreaMedica, _Activo, _Nombre, _Apellidos, _Horario, _Consultorio, _Direccion, _NumeroTelefono, _Email, _Sexo, _Edad, _codigoMedico;
    lectura.open("MEDICO//Datos_Medicos.txt",ios::in);
    if(lectura.is_open())
    {
        getline(lectura,codigoMedico);
        while(!lectura.eof())
        {

            getline(lectura,_Activo);
            getline(lectura,_Nombre);
            getline(lectura,_Apellidos);
            getline(lectura,_DNI);
            getline(lectura,_AreaMedica);
            getline(lectura,_Horario);
            getline(lectura,_Consultorio);
            getline(lectura,_Direccion);
            getline(lectura,_NumeroTelefono);
            getline(lectura,_Email);
            getline(lectura,_Sexo);
            getline(lectura,_Edad);
            getline(lectura,_codigoMedico);
            aux1=stoi(_AreaMedica);
            if(area==aux1){
                i++;
            }
        }
    }
    else
    {
        error9();
    }
    lectura.close();
    return i;
}


void Medico::IngresarMedicos(){
    ofstream datos_Medicos;
	ofstream COD_pass;

	datos_Medicos.open("MEDICO//Datos_Medicos.txt",ios::app);
	COD_pass.open("MEDICO//Credenciales_Medico.txt",ios::app);

	set_DatosPersonales("MEDICO//Datos_Medicos.txt");
	llenardatosmedicos();

	COD_pass<<codigoMedico<<"\n"<<Password<<"\n";

	datos_Medicos<<codigoMedico<<"\n"<<Activo<<"\n"<<Nombre<<"\n"<<Apellidos<<"\n"<<DNI<<"\n"
	<<AreaM<<"\n"<<Horario<<"\n"<<Consultorio<<"\n"<<Direccion<<"\n"
	<<NumeroTelefono<<"\n"<<Email<<"\n"<<Sexo<<"\n"<<Edad<<"\n";

	datos_Medicos.close();
	COD_pass.close();
}

void Medico::VerHorarioDoctores(){
    ifstream lectura;
    lectura.open("MEDICO//Datos_Medicos.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de horarios de los medicos***\t\t\t\t\n\n";
        getline(lectura,codigoMedico);
        while(!lectura.eof())
        {
            getline(lectura,Activo);
            getline(lectura,Nombre);
            getline(lectura,Apellidos);
            getline(lectura,DNI);
            getline(lectura,AreaMedica);
            getline(lectura,Horario);
            getline(lectura,Consultorio);
            getline(lectura,Direccion);
            getline(lectura,NumeroTelefono);
            getline(lectura,Email);
            getline(lectura,Sexo);
            getline(lectura,Edad);
            cout<<"Codigo: "<<codigoMedico<<endl;
            cout<<"Nombre: "<<Nombre<<endl;
            cout<<"Apellidos: "<<Apellidos<<endl;
            cout<<"DNI: "<<DNI<<endl;
            cout<<"Horario: "<<Horario<<endl;
            cout<<"\n\n";
            getline(lectura,codigoMedico);
        }
    }
    else
    {
        error9();
    }
    lectura.close();
    pausa9();
}
