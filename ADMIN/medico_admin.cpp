# include "medico.h"

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

Medico::Medico(){
    cout << "\n>>Medico Creado...\n";
}

Medico::~Medico(){
    cout << "\n>>Medico Eliminado...\n";
}

void Medico::llenardatosmedicos(){
    string auxCodigo, numero, aux8="00";
    int aux1=0, aux2=0,aux3=0;
        fflush(stdin);
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
        AreaMedica=CalcularAreaMedica(aux1);
        aux2=ContarMedicosArea(aux1);
        cout<<"\nnumero de medicos: "<<aux2;
        if (aux2<10){
            numero="0"+to_string(aux2);
        }else if(aux2>10){
            numero="0"+to_string(aux2);
        }
        for (int i = 0; i < 2; i++){
        aux8[i] = AreaMedica[i];}
        codigoMedico=aux8+"-"+"20"+"-"+numero+"-"+DNI[5]+DNI[6]+DNI[7]+DNI[8];
        cout<<"\nCodigo medico: "<<codigoMedico;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el horario del medico: ";
        cout<<"\n01.8-14";
        cout<<"\n02.14-22";
        cout<<"\n03.22-24";
        cout<<"opcion:";cin>>aux3:
        Horario=DefinirHorario(aux3)
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el consultorio del medico: ";
        getline(cin,Consultorio);
        cout<<"\n\n";
        fflush(stdin);
        activo="Yes"
        cout<<"\n\n";
    pausa();
}

char* Medico::CalcularAreaMedica(int opcion){
    char* opcelegida;
    bool Listo=false;
    do{
        switch(opcion){
        default:
            cout<<"Ingrese una opcion valida";
            break;
        case 1:
            cout<<"01. Cardiologia";
            opcelegida="1";
            Listo=true;
            break;
        case 2:
            cout<<"02. Neumologia";
            opcelegida="2";
            Listo=true;
            break;
        case 3:
            cout<<"03. Oncologia";
            opcelegida="3";
            Listo=true;
            break;
        case 4:
            cout<<"04. Hematologia";
            opcelegida="4";
            Listo=true;
            break;
        case 5:
            cout<<"05. Dermatologia";
            opcelegida="5";
            Listo=true;
            break;
        case 6:
            cout<<"06. Oftalmologia";
            opcelegida="6";
            Listo=true;
            break;
        case 7:
            cout<<"07. Urologia";
            opcelegida="7";
            Listo=true;
            break;
        case 8:
            cout<<"08. Nefrologia";
            opcelegida="8";
            Listo=true;
            break;
        case 9:
            cout<<"09. Reumatologia";
            opcelegida="9";
            Listo=true;
            break;
        case 10:
            cout<<"10. Medicina general";
            opcelegida="10.Medicina general";
            Listo=true;
            break;
        }
    }
    while(Listo==false);

    return opcelegida;
}

char* Medico::DefinirHorario(int opcion){
    char* opcelegida;
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
    lectura.open("MEDICO//Datos_Medicos.txt",ios::in);
    if(lectura.is_open())
    {
        getline(lectura,codigoEmpleado);
        while(!lectura.eof())
        {

            getline(lectura,activo);
            getline(lectura,Nombre);
            getline(lectura,Apellidos);
            getline(lectura,DNI);
            getline(lectura,AreaMedica);
            getline(lectura,Horario);
            getline(lectura,Consultorio);
            getline(lectura,Direccion);
            getline(lectura,Numero);
            getline(lectura,Email);
            getline(lectura,Sexo);
            getline(lectura,Edad);
            aux1=stoi(AreaMedica)
            if(area==aux1){
                i++;
            }
        }
    }
    else
    {
        error();
    }
    lectura.close();
    return i;
}
