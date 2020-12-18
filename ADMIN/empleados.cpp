# include "Empleados.h"

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

void pausa5(){
    cout<<"\nPresiona Enter para continuar...";
    getch();
    system(CLEAR);
}
void error5(){
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}

void admin_empleados::MenuEmpleados(){
	int OpcionEmpl;
    do
    {
        cout<<"\t\t\t\t***A.S.EMPLEADOS***\t\t\t\t\n\n";
        cout<<"1. Registro de empleados.\n\n";
        cout<<"2. Ingresar medicos.\n\n";
        cout<<"3. Ver empleados.\n\n";
        cout<<"4. Ver horario de doctores.\n\n";
        cout<<"5. Despedir empleados\n\n";
        cout<<"6. Volver atras\n\n";
        cout<<"Opci\242n: ";
        cin>>OpcionEmpl;
        system(CLEAR);
        switch(OpcionEmpl)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            RegistroEmpleados();
            break;

        case 2:
            IngresarMedicos();
            break;

        case 3:
            VerEmpleados();
            break;

        case 4:
            VerHorarioDoctores();
            break;

        case 5:
            DespedirEmpleados();
            break;

        case 6:
            break;
        }
    }
    while(OpcionEmpl!=6);
}

void admin_empleados::RegistroEmpleados(){
	ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("empleados.txt",ios::in);
    escritura.open("empleados.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\t\t\t\t***Registrar un empleado***\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresa el c\242digo del empleado: ";
        getline(cin,auxCodigo);
        if(auxCodigo=="")
            do
            {
                cout<<"c\242digo de cliente no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        do
        {
            verificador.seekg(0);
            getline(verificador,codigoEmpleado);
            while(!verificador.eof())
            {
                getline(verificador,Nombre);
                getline(verificador,Apellidos);
                getline(verificador,DNIEmpleado);
                getline(verificador,Direccion);
                getline(verificador,Celular);
                getline(verificador,Sexo);
                getline(verificador,Ocupacion);

                if(codigoEmpleado==auxCodigo)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un Empleado con ese c\242digo!\n\n";
                    cout<<"El empleado con ese c\242digo es: "<<Nombre<<" "<<Apellidos<<"\n\n";
                    cout<<"Ingresa un c\242digo v\240lido!: ";
                    getline(cin,auxCodigo);
                    if(auxCodigo=="")
                        do
                        {
                            cout<<"\nc\242digo de empleado no v\240lido!, intentalo nuevamente: ";
                            getline(cin,auxCodigo);
                        }
                        while(auxCodigo=="");

                    break;
                }

                getline(verificador,codigoEmpleado);
            }

            if(verificador.eof()&&auxCodigo!=codigoEmpleado)
                coincidencia=false;

        }
        while(coincidencia==true);
        system(CLEAR);
        codigoEmpleado=auxCodigo;
        cout<<"\t\t\t\t***Ingresar un empleado***\t\t\t\t\n\n";
        cout<<"Ingresa el DNI del empleado: ";
        getline(cin,DNIEmpleado);
        if(DNIEmpleado.length()!=8 )
		{
			do
			{
				cout<<"\nIngrese su DNI con 8 digitos";
				cout<<"\nDNI no v\240lido!, intentalo nuevamente: ";
				getline(cin,DNIEmpleado);

			}while(DNIEmpleado.length()!=8);
		}
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el c\242digo del empleado: ";
        cout<<codigoEmpleado;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa solo el nombre del empleado: ";
        getline(cin,Nombre);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa los apellidos del empleado: ";
        getline(cin,Apellidos);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la direccion del empleado: ";
        getline(cin,Direccion);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el Celular del empleado: ";
        getline(cin,Celular);
        if(Celular.length()!=9 )
		{
			do
			{
				cout<<"\n\tIngrese su celular con 9 digitos";
				cout<<"\n\tCelular no v\240lido!, intentalo nuevamente: ";
				getline(cin,Celular);

			}while(Celular.length()!=9);
		}
        cout<<"\n\n";
    	fflush(stdin);
        cout<<"Ingresa el sexo del empleado (masculino o femenino): ";
        getline(cin,Sexo);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la ocupacion del empleado: ";
        getline(cin,Ocupacion);
        cout<<"\n\n";
        fflush(stdin);

        escritura<<codigoEmpleado<<"\n"<<Nombre<<"\n"<<Apellidos<<"\n"<<DNIEmpleado<<"\n"<<Direccion<<"\n"<<Celular
        <<"\n"<<Sexo<<"\n"<<Ocupacion<<"\n";

        cout<<"El registro se ha completado correctamente.\n\n";
    }

    else
    {
        error5();
    }

    escritura.close();
    verificador.close();
    pausa5();
}

void admin_empleados::VerEmpleados(){
    int i=0;
    ifstream lectura;
    lectura.open("empleados.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de todos los empleados no medicos***\t\t\t\t\n\n";
        getline(lectura,codigoEmpleado);
        while(!lectura.eof())
        {
            i++;
            getline(lectura,Nombre);
            getline(lectura,Apellidos);
            getline(lectura,DNIEmpleado);
            getline(lectura,Direccion);
            getline(lectura,Celular);
            getline(lectura,Sexo);
            getline(lectura,Ocupacion);
            cout<<"Codigo: "<<codigoEmpleado<<endl;
            cout<<"Nombre: "<<Nombre<<endl;
            cout<<"Apellidos: "<<Apellidos<<endl;
            cout<<"DNI: "<<DNIEmpleado<<endl;
            cout<<"Direccion: "<<Direccion<<endl;
            cout<<"Celular: "<<Celular<<endl;
            cout<<"Sexo: "<<Sexo<<endl;
            cout<<"Ocupacion: "<<Ocupacion<<endl;
            cout<<"\n\n";
            getline(lectura,codigoEmpleado);
        }

        if(i==1)
            cout<<"Hay un solo Empleado registrado en esta clinica\n\n";

        else

            cout<<"Hay un total de "<<i<<" empleados registrados en esta clinica\n\n";
    }
    else
    {
        error5();
    }
    lectura.close();
    pausa5();
}

void admin_empleados::DespedirEmpleados(){
	ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    string auxCodigo;
    char respuesta[5];
    lectura.open("empleados.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Dar de baja un empleado***\t\t\t\t\n\n";
    if(lectura.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del empleado que deseas dar de baja: ";
        getline(cin,auxCodigo);
        getline(lectura,codigoEmpleado);
        while(!lectura.eof())
        {
            getline(lectura,Nombre);
            getline(lectura,Apellidos);
            getline(lectura,DNIEmpleado);
            getline(lectura,Direccion);
            getline(lectura,Celular);
            getline(lectura,Sexo);
            getline(lectura,Ocupacion);

            if(auxCodigo==codigoEmpleado)
            {
                encontrado=true;
                cout<<codigoEmpleado<<endl;
	            cout<<Nombre<<endl;
	            cout<<Apellidos<<endl;
	            cout<<DNIEmpleado<<endl;
	            cout<<Direccion<<endl;
	            cout<<Celular<<endl;
	            cout<<Sexo<<endl;
	            cout<<Ocupacion<<endl;
	            cout<<"\n\n";
                cout<<"Realmente deseas dar de baja a: "<<Nombre<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                    cout<<"\n\nEl empleado se ha dado de baja correctamente\n\n";
                }

                else
                {

                    cout<<"\n\empleado conservado\n\n";
                    auxiliar<<codigoEmpleado<<"\n"<<Nombre<<"\n"<<Apellidos<<"\n"<<DNIEmpleado<<"\n"<<Direccion
                            <<"\n"<<Celular<<"\n"<<Sexo<<"\n"<<Ocupacion<<"\n";

                }

            }
            else
            {
                auxiliar<<codigoEmpleado<<"\n"<<Nombre<<"\n"<<Apellidos<<"\n"<<DNIEmpleado<<"\n"<<Direccion
                            <<"\n"<<Celular<<"\n"<<Sexo<<"\n"<<Ocupacion<<"\n";
            }
            getline(lectura,codigoEmpleado);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
        }

    }
    else
    {
        error5();
    }
    lectura.close();
    auxiliar.close();
    remove("empleados.txt");
    rename("auxiliar.txt","empleados.txt");
    pausa5();
}

void admin_empleados::IngresarMedicos(){
    ofstream datos_Medicos;
	ofstream COD_pass;

	datos_Medicos.open("MEDICO//Datos_Medicos.txt",ios::app);
	COD_pass.open("MEDICO//Credenciales_Medicos.txt",ios::app);

	Medico.set_DatosPersonales(Datos_Medicos.txt);
	Medico.llenardatosmedicos();

	COD_pass<<codigoMedico<<"\n"<<Password<<"\n";

	datos_Medicos<<codigoMedico<<"\n"<<activo<<"\n"<<Nombre<<"\n"<<Apellidos<<"\n"<<DNI<<"\n";
	datos_Medicos<<AreaMedica<<"\n"<<Horario<<"\n"<<Consultorio<<"\n"<<Direccion<<"\n";
	datos_Medicos<<Numero<<"\n"<<Email<<"\n"<<Sexo<<"\n"<<Edad<<"\n";

	datos_Medicos.close();
	COD_pass.close();
}

void admin_empleados::VerHorarioDoctores(){
    ifstream lectura;
    lectura.open("MEDICO//Datos_Medicos.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de horarios de los medicos***\t\t\t\t\n\n";
        getline(lectura,codigoMedico);
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
            cout<<"Codigo: "<<codigoEmpleado<<endl;
            cout<<"Nombre: "<<Nombre<<endl;
            cout<<"Apellidos: "<<Apellidos<<endl;
            cout<<"DNI: "<<DNIEmpleado<<endl;
            cout<<"Horario: "<<AreaMedica<<endl;
            cout<<"\n\n";
            getline(lectura,codigoMedico);
        }
    }
    else
    {
        error5();
    }
    lectura.close();
    pausa5();
}

