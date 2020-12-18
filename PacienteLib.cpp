#include <iostream>
#include <fstream> // ficheros
#include <string.h>
#include <conio.h> //getch()
#include <ctime>//citas
#include "myVector.cpp"
#include <iomanip>//formato tablas 
#include<stdlib.h> //time()
#include<time.h>//rand()


#include "Paciente.hpp"
using namespace std;

//Limpiar pantalla en SO
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif


Paciente::Paciente(){
    cout << "\n>>Paciente Creado...\n";
}

Paciente::~Paciente(){
    cout << "\n>>Paciente Eliminado...\n";
}


void Paciente::iniciarSesion(string _DNI)
{
	
	ifstream datosPaciente;
	ifstream talla_peso;
	datosPaciente.open("PACIENTE//Datos_Pacientes.txt",ios::in);
	//Cargar Datos del Paciente
	datosPaciente.seekg(0);

	while(!datosPaciente.eof())
	{
		getline(datosPaciente,DNI);
		getline(datosPaciente,Nombre);
		getline(datosPaciente,Apellidos);
		getline(datosPaciente,Direccion);
		getline(datosPaciente,Edad);
		getline(datosPaciente,Email);
		getline(datosPaciente,NumeroTelefono);
		getline(datosPaciente,Sexo);
		if(DNI == _DNI){
			break;
		}
	}
	
	//cargar Peso-Talla
	talla_peso.open("PACIENTE//Triage.txt",ios::in);
	talla_peso.clear();
	talla_peso.seekg(0);
	
	while(!talla_peso.eof())
	{
		getline(talla_peso,DNI);
		talla_peso>>Peso;talla_peso.ignore();
		talla_peso>>Talla;talla_peso.ignore();
		getline(talla_peso,sintomas);
		getline(talla_peso,Edad);
	
		if(DNI == _DNI){
			break;
		}
	}

	DNI=_DNI;

	datosPaciente.close();
	talla_peso.close();
	cuenta();

}


void Paciente::crearCuenta(){

    ofstream datos_Pacientes;
	ofstream DNI_pass;
    ofstream post_atencion;

	datos_Pacientes.open("PACIENTE//Datos_Pacientes.txt",ios::app);
	DNI_pass.open("PACIENTE//Credenciales_Paciente.txt",ios::app);
	post_atencion.open("MEDICO//Post_Atencion.txt",ios::app);

	//establecer valores de datos Paciente
	set_DatosPersonales("PACIENTE//Credenciales_Paciente.txt");


	DNI_pass<<DNI<<"\n"<<Password<<"\n";
	datos_Pacientes<<DNI<<"\n"<<Nombre<<"\n"<<Apellidos<<"\n"<<Direccion<<"\n";
	datos_Pacientes<<Edad<<"\n"<<Email<<"\n"<<NumeroTelefono<<"\n"<<Sexo<<"\n";
	post_atencion<<DNI<<"\n"<<false<<"\n"<<false<<"\n"<<-1<<"\n"<<false<<"\n"<<false<<"\n";
 		
	//triage
	generadorTriage(0);

	//cerrar y guardar datos
	datos_Pacientes.close();
	DNI_pass.close();
	post_atencion.close();

	//abrir cuenta
	cuenta();


}


//*******************CUENTA ***********************
void Paciente::cuenta()
{

        int opcion;
        do{
            system(CLEAR);
            cout<<"\n\t\t\t\t***CENTRO MEDICO VIDA***\t\t\t\t\n\n";
            cout<<"\n\tBienvenid@ "<<Nombre<<" "<<Apellidos;
            cout<<"\n\n\n\t1.Ver Perfil";
			cout<<"\n\n\t2.Solicitar Cita";
			cout<<"\n\n\t3.Ver Cita Medica";
            cout<<"\n\n\t4.Ver Receta Medica";
            cout<<"\n\n\t5.Ver Post-Atencion";
            cout<<"\n\n\t6.Salir";
            cout<<"\n\n\n\tOpci\242n: ";
            cin>>opcion;

			cin.ignore();

            switch(opcion)
            {
                default:
                    cout<<"Ha ingresado una opci\242n no valida!\n\n";
                    break;
                case 1:
					verPerfil();
					break;
				case 2:
                    solicitarCita();
                    break;
				case 3:
                    verCitaMedica();
                    break;
                case 4:
                    verRecetaMedica();
                    break;
                case 5:
					verPostAtencion();
                    break;
            }
        }while(opcion!=6);


}

void Paciente::verPerfil()
{
	system(CLEAR);
	ver_DatosPersonales();

 	cout << "\t|     Talla           | "<<Talla<<" m\n";
    cout << "\t+---------------------+------------------------------------+\n";
    cout << "\t|     Peso            | "<<Peso<<" Kg\n";
    cout << "\t+---------------------+------------------------------------+\n\n";

	pausa();

}


void Paciente::solicitarCita()
{

	int opcion;

    do
    {
		system(CLEAR);
        cout<<"\n\t\t\t\t***CENTRO MEDICO VIDA***\t\t\t\t\n\n";
        cout<<"\n\tBienvenid@ "<<Nombre<<" "<<Apellidos;
        cout<<"\n\n\n\tArea Medica que desea cita: \n";
        cout<<"\n\t1.Cardiologia";
        cout<<"\n\t2.Neumologia";
        cout<<"\n\t3.Oncologia";
        cout<<"\n\t4.Hematologia";
        cout<<"\n\t5.Dermatologia";
        cout<<"\n\t6.Oftalmologia";
        cout<<"\n\t7.Urologia";
        cout<<"\n\t8.Nefrologia";
        cout<<"\n\t9.Reumatologia";
        cout<<"\n\t10.Medicina general";
        cout<<"\n\n\t11.Salir";
        cout<<"\n\n\n\tOpci\242n: ";
        cin>>opcion;

		cin.ignore();

        switch(opcion)
        {
            default:cout<<"Ha ingresado una opci\242n no valida!\n\n";break;
            case 1: generadorCita("CITAS//Citas_Cardiologia.txt","1");break;
			case 2: generadorCita("CITAS//Citas_Neumologia.txt","2");break;
			case 3: generadorCita("CITAS//Citas_Oncologia.txt","3");break;
			case 4: generadorCita("CITAS//Citas_Hematologia.txt","4");break;
			case 5: generadorCita("CITAS//Citas_Dermatologia.txt","5");break;
			case 6: generadorCita("CITAS//Citas_Oftalmologia.txt","6");break;
			case 7: generadorCita("CITAS//Citas_Urologia.txt","7");break;
			case 8: generadorCita("CITAS//Citas_Nefrologia.txt","8");break;
			case 9: generadorCita("CITAS//Citas_Reumatologia.txt","9");break;
			case 10: generadorCita("CITAS//Citas_MedicinaGeneral.txt","10");break;

        }

    }while(opcion!=11);

}


void Paciente::generadorCita(string NombreArchivo,string areaMedica)
{

	time_t now = time(NULL); //hoy
	int day,month,year;

	string codigoMedico,nroinforme,NombreMedico,ApellidosMedico,consultorio;

	ifstream medicos;//lectura
	ifstream citas;	//lectura
	medicos.open("MEDICO//Datos_Medicos.txt",ios::in);
	citas.open(NombreArchivo.c_str(),ios::in);

	//auxiliares
	string activo,aux,_codigo,aux_horario,_nombre,_apellido,_areaMedica,_horario,_consultorio;

	myVector codigos,horarios,Nombres,Apellidoss,consultorios;


	medicos.clear();
	medicos.seekg(0);
	while(!medicos.eof())
	{
		getline(medicos,_codigo);
		getline(medicos,activo);
		getline(medicos,_nombre);
		getline(medicos,_apellido);
		getline(medicos,aux);
		getline(medicos,_areaMedica); 
		getline(medicos,_horario);
		getline(medicos,_consultorio);
		for(int i=0;i<5;++i) getline(medicos,aux); 
	
		if((activo=="true" || activo=="1") && _areaMedica==areaMedica)
		{
			Nombres.push_back(_nombre);
			Apellidoss.push_back(_apellido);
			codigos.push_back(_codigo);
			horarios.push_back(_horario); 
			consultorios.push_back(_consultorio);
		}
		
	}

	medicos.close();
	int menorCitas,maxCitas,hora,numeroCitas;
	
	if(codigos.Size() != 0)
	{
	
		do
		{
		
			system(CLEAR);
			now += 86400; // mañana
			struct tm nowlocal;
			nowlocal=*localtime(&now);
			day=nowlocal.tm_mday;
			month=nowlocal.tm_mon+1;
			year=nowlocal.tm_year+1900;

			menorCitas=0;

			//medico con menos citas en el dia de mañana
			string dia,mes,anio;
			string  aux_hora,last_hora;

			for (int i=0;i<codigos.Size();i++)
			{
				int aux_day,aux_month,aux_year;
				int _maxCitas;

				numeroCitas=0;

				citas.close();//reset
				citas.open(NombreArchivo.c_str(),ios::in);
				citas.seekg(0);

				//definir los horarios default y max de citas
				if(horarios.operator[](i) == "8-14"){_maxCitas=12; last_hora="480";}
				if(horarios.operator[](i) == "14-22"){_maxCitas=16; last_hora="840";}
				if(horarios.operator[](i) == "22-24"){_maxCitas=4; last_hora="1320";}

				//lectura
				while(getline(citas,_codigo))
				{
					getline(citas,aux);//estado de la cita
					getline(citas,aux);//nro de informe
					getline(citas,aux);//DNI paciente
					getline(citas,aux);aux_day=stoi(aux);//dia
					getline(citas,aux);aux_month=stoi(aux);//mes
					getline(citas,aux);aux_year=stoi(aux);//anio
					getline(citas,aux_hora);//hora minutos
					if(_codigo == codigos.operator[](i) && aux_day==day && aux_month==month && aux_year==year)
					{
						numeroCitas++;
						last_hora=aux_hora;
					}

				}
				int citasPosibles=_maxCitas-numeroCitas;

				if(citasPosibles>menorCitas)
				{
					menorCitas = citasPosibles;
					codigoMedico = codigos.operator[](i);// guarda el codigo
					NombreMedico = Nombres[i];
					ApellidosMedico = Apellidoss.operator[](i);
					consultorio = consultorios.operator[](i);
					maxCitas =_maxCitas;
					hora = (numeroCitas!=0)? stoi(last_hora)+30: stoi(last_hora);
					//PRUEBAS
					/*
					cout<<"\n---resultados---\n";
					cout<<"Citas posibles= "<<menorCitas<<" maximoCitas= "<<maxCitas<<endl;
					cout<<"hora= "<<hora<<" codigo= "<<codigoMedico<<endl;
					*/
				}
			}
		}while(menorCitas==0);

		citas.close();


		//generador de nroinforme mes-numerodecitadelmes
		citas.open(NombreArchivo.c_str(),ios::in);
		citas.seekg(0);
		int contador=0;
		string mes;

		while(getline(citas,aux)){if(stoi(aux)==month){contador++;mes=aux;}}
		citas.close();

		string cont = to_string(contador);
		nroinforme=mes+cont;
		//-------------------------------------------------

		//asignar cita
		ofstream citastxt,historial;
		citastxt.open(NombreArchivo.c_str(),ios::app);
		historial.open("CITAS//Historial.txt",ios::app);
		

		citastxt<<codigoMedico<<endl;
		citastxt<<0<<endl;
		citastxt<<nrocitasPaciente(NombreArchivo,DNI)<<endl;
		citastxt<<DNI<<endl;
		citastxt<<day<<endl;
		citastxt<<month<<endl;
		citastxt<<year<<endl;
		citastxt<<hora<<endl;

		int hour=hora/60;
		int min=hora%60;
		string minutos = (min==0)? "00":to_string(min);
		

		historial<<DNI<<endl;
		historial<<year<<"/"<<month<<"/"<<day<<endl;
		historial<<hour<<":"<<minutos<<endl;
		historial<<NombreMedico<<endl;
		historial<<ApellidosMedico<<endl;
		historial<<NombreAreaMedica(stoi(areaMedica))<<endl;
		historial<<consultorio<<endl;

		citastxt.close();
		historial.close();
		generadorTriage(stoi(areaMedica));
		

		cout<<"\n\n\tCentro Medico Vida";
		cout<<"\n\t\t\t\t\tCITA MEDICA  \t\t\t\t";
		cout<<"\n\n\t---------------------------------------------------------------------------------------";
		cout<<"\n\n\tPACIENTE: "<<Nombre<<" "<<Apellidos<<"\t\tDNI: "<<DNI<<"\t\tTEL: "<<NumeroTelefono;
		cout<<"\n\n\t---------------------------------------------------------------------------------------";
		cout<<"\n\tMEDICO: "<<NombreMedico<<" "<<ApellidosMedico;
		cout<<"\n\n\n\t\tDIA"<<"\t\t\tHORA"<<"\t\tESPECIALIDAD"<<"\t\tCONSULTORIO";
		cout<<"\n\n\t      "<<day<<"/"<<month<<"/"<<year<<"\t\t"<<hour<<":"<<minutos<<"\t\t"<<NombreAreaMedica(stoi(areaMedica))<<"\t\t   "<<consultorio;
		cout<<"\n\n\t-------------------------------------------------------------------------------------";
		cout<<"\n\t\t\t\tAsistir 15 minutos antes de su cita";
		cout<<"\n\t\tSI EL PACIENTE LLEGA DESPUES DE LA HORA DE CITA PERDERA SU TURNO\n";
		cout<<"\n\t--------------------------------------------------------------------------------------\n\n";

		pausa();

	}else
	{
		system(CLEAR);
		cout<<"\n\n\t+--------------------------------------------------+";
		cout<<"\n\t|  Area Medica sin personal Medico momentaneamente | ";
		cout<<"\n\t+--------------------------------------------------+\n\n";
		pausa();
	}	
	
}



void Paciente::generadorTriage(int areaMedica)
{
	string sintomas;
	switch(areaMedica)
	{
		case 0: sintomas="Null";break;
		case 1: sintomas="Dolor en el pecho, presión en el pecho y fatiga";break;
		case 2: sintomas="Dolor en el pecho al respirar o toser";break;
		case 3: sintomas="Sangrado o hemorragias anormales";break;
		case 4: sintomas="Palidez, cansancio y dificultad respiratoria ";break;
		case 5: sintomas="Enrojecimiento e hinchazón de la piel";break;
		case 6: sintomas="Dolores repentinos en los ojos";break;
		case 7: sintomas="Dolor o sangrado en las micciones.";break;
		case 8: sintomas="Espasmos y calambres musculares.";break;
		case 9: sintomas="Reducción de la movilidad articular";break;
		case 10: sintomas="Fatiga y debilidad";break;
	}
	if(areaMedica == 0)
	{
		srand(time(NULL));
		Peso = 70+rand()%(31);
		Talla = (double)rand()/(RAND_MAX+1)*(2-1.5)+1.5;
	
		ofstream datosTriage;
		datosTriage.open("PACIENTE//Triage.txt",ios::app);

		datosTriage.clear();
		datosTriage.precision(3);		
		datosTriage<<DNI<<endl;
		datosTriage<<Peso<<endl;
		datosTriage<<Talla<<endl;
		datosTriage<<sintomas<<endl;
		datosTriage<<Edad<<endl;
		datosTriage.close();
	}else{
		modificarSintomas(DNI,sintomas);
	}

}


void Paciente::verCitaMedica()
{
	
    system(CLEAR);
	string fecha,hora,NombreMedico,ApellidosMedico,areaMedica,consultorio;

	ifstream in("CITAS//Historial.txt");
	
	if (in.is_open())
	{
		string  verificador,_DNI,_fecha="0",_hora,_NombreMedico,_ApellidosMedico,_areaMedica,_consultorio;
		myVector reverse;
		string line;	
		in.clear();
		in.seekg(0);
		while (getline(in, _DNI))
		{
			getline(in,_fecha);
			getline(in,_hora);
			getline(in,_NombreMedico);
			getline(in,_ApellidosMedico);
			getline(in,_areaMedica);
			getline(in,_consultorio);
			
			if(DNI == _DNI)
			{
				verificador=_DNI;
				reverse.push_back(_consultorio);
				reverse.push_back(_areaMedica);
				reverse.push_back(_ApellidosMedico);
				reverse.push_back(_NombreMedico);
				reverse.push_back(_hora);
				reverse.push_back(_fecha);
				
			}
		}

		in.close();

							
		cout << "\n\t\t\t\t\t _____________________________\n";
		cout << "\t\t\t\t\t|     HISTORIAL DE CITAS      |\n";
		cout << "\t\t\t\t\t|_____________________________|\n";

		if(DNI == verificador)
		{
			cout << "\n\t+-------------+--------+----------------------------------------------+-------------------+--------------+\n";
			cout << "\t|     Fecha   |  hora  |               Nombre del Medico              |    Especialidad   |  Consultorio |\n";
			cout << "\t+-------------+--------+----------------------------------------------+-------------------+--------------+\n";
			
			for(int i=reverse.Size()-1;i>0;i-=6)
			{
				char separator  = ' ';
				
				cout<< "\t|";
				cout << right << setw(12) << setfill(separator) <<reverse.operator[](i)<<" |";
				cout << right << setw(7) << setfill(separator) << reverse.operator[](i-1)<<" |";
				cout << right << setw(45) << setfill(separator) << reverse.operator[](i-2)+" "+reverse.operator[](i-3)<<" |";
				cout << right << setw(18) << setfill(separator) << reverse.operator[](i-4)<<" |";
				cout << right << setw(5) << setfill(separator) << reverse.operator[](i-5)<<"         |";
				cout << "\n\t+-------------+--------+----------------------------------------------+-------------------+--------------+";
				cout << endl;
			}
			
			

		}else{
            cout<<"\n\n\t+-----------------------------------+";
			cout<<"\n\t|  Usted No tiene Citas registradas | ";
            cout<<"\n\t+-----------------------------------+\n\n";
		}

	}
    pausa();
	   
}
						




void Paciente::verRecetaMedica()
{
	system(CLEAR);
	fstream receta("MEDICO//receta.txt");
	string aux,examen,fecha,codigoMedico,Nombre_Apellidos,areaMedica,_fecha,peso,talla,edad;
	int nroMedicamentos,op,opcion;


	fecha="0000/00/00";
	do
	{	
		myVector fechas;
		receta.clear();
		receta.seekg(0);
		
								
		while(!receta.eof())
		{
			getline(receta,aux); //puntero DNI
			myVector medicamentos,cantidades,comentarios,examenes;
							
			if(is_DNI(aux) && aux==DNI )
			{	
				getline(receta,Nombre_Apellidos);
				getline(receta,aux); areaMedica=NombreAreaMedica(stoi(aux));
				getline(receta,codigoMedico);
				getline(receta,aux);//nroinforme
				getline(receta,_fecha); fechas.push_back(_fecha);

				receta>>nroMedicamentos;receta.ignore();
                while(nroMedicamentos>0)//numero de Medicamentos
                {
                    getline(receta,aux);medicamentos.push_back(aux);
                    getline(receta,aux);cantidades.push_back(aux);
                    getline(receta,aux);comentarios.push_back(aux);
                    nroMedicamentos--;
                }
					getline(receta,aux);
                    getline(receta,examen);
                do
                {
                    examenes.push_back(examen);
                    getline(receta,examen);

                }while(examen!="end");


				if(fecha == _fecha  )
				{
					system(CLEAR);
					cout<<"\n\n\n\t"<<fecha<<endl;
					cout<<"\n\n\t\tDR(A): "<<Nombre_Apellidos;
					cout<<"\n\t\t\t"<<areaMedica;
					cout<<"\n\t\t\t "<<codigoMedico;
					cout<<"\n\t---------------------------------------------------\n";
					cout<<"\tPACIENTE: "<<Nombre<<" "<<Apellidos;
					cout<<"\n\n\tPESO: "<<Peso<<"\tTALLA: "<<Talla<<"\tEDAD: "<<Edad;
					cout<<"\n\t---------------------------------------------------\n";
					cout<<"\tRp/\n\n";
					for(int i=0;i<medicamentos.Size();++i)
					{
						cout<<"\t\t"<<medicamentos.operator[](i)<<"\t";
						cout<<cantidades.operator[](i)<<endl;
						cout<<"\n\t\t"<<is_Null(comentarios.operator[](i))<<"\n\n";
					}
					cout<<"\n\t---------------------------------------------------\n";
					cout<<"\n\tEXAMENES:\n\n";
					for(int j=0;j<examenes.Size();++j)
					{
						cout<<"\t\t"<<examenes.operator[](j)<<endl;
					}
					cout<<"\n\t----------------------------------------------------\n";
				}
			}
		}

		cout << "\n\t\t\t\t\t ______________________________________\n";
		cout << "\t\t\t\t\t|     HISTORIAL DE RECETAS MEDICAS     |\n";
		cout << "\t\t\t\t\t|______________________________________|\n";
		cout<<"\n\n\t+------------+";
		cout<<"\n\t|   FECHAS   |";
		cout<<"\n\t+------------+\n";
		for(op=0;op<fechas.Size();++op){
			cout<<"\t|"<<op+1<<"."<<fechas.operator[](op)<<"|"<<endl;
			cout<<"\t--------------\n";
		}
		cout<<"\t|"<<op+1<<".Salir     |\n";
		cout<<"\t+------------+\n";

		cout<<"\n\tingrese su opcion: ";
		cin>>opcion;

		fecha=fechas.operator[](opcion-1);

	}while( opcion!=op+1 );
}

void Paciente::verPostAtencion()
{
	system(CLEAR);
	ifstream estado("MEDICO//Post_Atencion.txt");

	int codAreaMedica;
	string _DNI,habilitado,reqExamen,reqCita,reqHospitalizacion;

	estado.clear();
	estado.seekg(0);

	while(getline(estado,_DNI))
	{
		if(_DNI == DNI)
		{
			getline(estado,habilitado);
			getline(estado,reqExamen);
			estado>>codAreaMedica; estado.ignore();	
			getline(estado,reqCita);
			getline(estado,reqHospitalizacion);
			break;
		}
	
	}
	estado.close();

	cout << "\n\t\t\t\t\t ______________________________________\n";
	cout << "\t\t\t\t\t|     ESTADO   DE  POST-ATENCION       |\n";
	cout << "\t\t\t\t\t|______________________________________|\n";

	if(habilitado == "true")
	{
		cout<<"\n\t\t__________________________________________________\n";
		cout<<"\n\t\tRequiere Examenes:\t\t"<<SI_NO(reqExamen);
		cout<<"\n\t\tDerivacion a otro especialista:\t"<<NombreAreaMedica(codAreaMedica);
		cout<<"\n\t\tRequiere otras citas:\t\t"<<SI_NO(reqCita);
		cout<<"\n\t\t__________________________________________________\n";
		cout<<"\n\t\tRequiere Hospitalizacion:\t"<<SI_NO(reqCita);
		cout<<"\n\t\t__________________________________________________\n\n\n";

	}
	else{
		cout<<"\n\n\t\t_____________________________________________________________\n";
		cout<<"\n\t\t El estado de Post-Atencion no esta habilitado por su Medico";
		cout<<"\n\t\t_____________________________________________________________\n\n\n";
	}

	pausa();
}

 			



//************FUNCTIONS***********************

string SI_NO(string p)
{
	return(p =="true")? "SI":"NO";
}

void modificarSintomas(string DNI,string sintomas)
{
    ifstream l("PACIENTE//Triage.txt");
    ofstream o("PACIENTE//auxiliar.txt");

    l.clear();
    l.seekg(0);
    string aux,peso,talla,_sintomas,edad,_DNI;
    while(getline(l,_DNI))
    {
        getline(l,peso);
        getline(l,talla);
        getline(l,_sintomas);
        getline(l,edad);
        if(_DNI==DNI)
        {
            o<<_DNI<<endl;
            o<<peso<<endl;
            o<<talla<<endl;
            o<<sintomas<<endl;
            o<<edad<<endl;
        }else{
            o<<_DNI<<endl;
            o<<peso<<endl;
            o<<talla<<endl;
            o<<_sintomas<<endl;
            o<<edad<<endl;
        }
    }    
    l.close();
    o.close();
    remove("PACIENTE//Triage.txt");
    rename("PACIENTE//auxiliar.txt","PACIENTE//Triage.txt");
}


bool is_Date(string fecha)
{
    return (fecha > "0000/00/00")? true:false;
}


string is_Null(string word)
{
	return (word =="Null")? "": word;
}


string NombreAreaMedica(int codigo)
{
	string areaMedica;

	switch(codigo)
	{
		case -1: areaMedica="NO";break;
		case 1: areaMedica="Cardiologia";break;
		case 2: areaMedica="Neumologia";break;
		case 3: areaMedica="Oncologia";break;
		case 4: areaMedica="Hematologia";break;
		case 5: areaMedica="Dermatologia";break;
		case 6: areaMedica="Oftalmologia";break;
		case 7: areaMedica="Urologia";break;
		case 8: areaMedica="Nefrologia";break;
		case 9: areaMedica="Reumatologia";break;
		case 10: areaMedica="Medicina general";break;
	}

	return areaMedica;
}


int nrocitasPaciente(string areaMedicatxt ,string DNI )
{
	ifstream contador(areaMedicatxt);
	int cont=0;
	string _DNI;
	contador.clear();
	contador.seekg(0);

	while(getline(contador,_DNI))
	{
		if( DNI == _DNI)
			cont++;
	}

	return cont;
}

bool is_DNI(const std::string& s)
{	
	return( strspn( s.c_str(), "0123456789" ) == s.size() ) && (s.length()==8);
}


void gentxt(string name){

	ofstream archivo; //como cout
	archivo.open(name.c_str(),ios::app);
	archivo.close();

}
void pausa()
{
    cout<<"\n\n\tPresiona Enter para Salir...";
    getch();
    system(CLEAR);
}


