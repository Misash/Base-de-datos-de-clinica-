#include <iostream>
#include <fstream> // ficheros
#include <string>
#include <conio.h> //getch()

using namespace std;


//Limpiar pantalla en SO
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif



class Paciente{
    private:
        string dni,password,nombre,apellido,numeroTelefono,direccion,correo;
    public:
        void login();
        void iniciarSesion();
        void crearCuenta();
        void cuenta();
        //void solicitarCita();
        /*
        void recetaMedica();
        void postAtencion();
        void factura();
        */

};

void pausa();
void error();

void Paciente::login()
{
    int opcion;

    do
    {
        cout<<"\n\t\t\t\t ___CENTRO MEDICO VIDA___\t\t\t\t\n\n";
        cout<<"\t\t\t\t\t**LOGIN**\t\t\t\t\n\n";
        cout<<"\t1. Iniciar Sesi\242n\n\n";
        cout<<"\t2. Crear Cuenta\n\n";
        cout<<"\t3. Salir\n\n";
        cout<<"\tOpci\242n: ";
        cin>>opcion;

        switch(opcion)
        {

        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;
        case 1:
            iniciarSesion();
            break;
        case 2:
            crearCuenta();
            break;
        case 3:
            break;

        }

    }while(opcion !=3);

}


void Paciente::iniciarSesion()
{

    string user,pass;
	int contador=0;
	bool ingresa=false;

	ifstream datosPaciente;
	ifstream lectura;
	lectura.open("DNI-PASS.txt",ios::in);
    datosPaciente.open("Datos_Pacientes.txt",ios::in);

	if(lectura.is_open() && datosPaciente.is_open())
	{
	    cin.ignore();// limpia buffer
		do{
			system(CLEAR);
			cout<<"\n\n\t\t\tLOGIN DE PACIENTES";
			cout<<"\n\t\t\t------------------";
			cout<<"\n\tDNI: ";
			getline(cin,user);
			cout<<"\tPassword: ";

			char caracter;
			pass = "";
			caracter= getch();
			while(caracter !=13){

				if(caracter != 8){
					pass.push_back(caracter);
					cout<<"*";
				}
				else{
					if(pass.length() >0){
						cout<<"\b \b";
						pass.pop_back();
					}
				}

				caracter=getch();
			}
			//busqueda de dni y password en txt
			lectura.seekg(0);
			while(!lectura.eof()){
				getline(lectura,dni);
				getline(lectura,password);
				if(dni == user && password == pass){
					ingresa=true;
					break;
				}
			}
			//intentos
			contador++;

		} while(ingresa !=true && contador <3);


		if(ingresa == false){
			cout<<"\n\n\tEl DNI o password son incorrectos";
			cout<<"\n\tUsted no puedo ingresar al sistema .ADIOS";
		}
		else
		{
		    //obtenemos los datos del paciente
            datosPaciente.seekg(0);
            string aux_dni;
            while(!datosPaciente.eof())
            {
                getline(datosPaciente,aux_dni);
                getline(datosPaciente,nombre);
                getline(datosPaciente,apellido);
                getline(datosPaciente,numeroTelefono);
                getline(datosPaciente,direccion);
                getline(datosPaciente,correo);
                if(dni==aux_dni){
                        dni=aux_dni;break;
                }
            }

            lectura.close();
            datosPaciente.close();

			cuenta();
		}
	}
	else{
		cout<<"\n\tError en abrir  DNI-PASS.txt";
	}

    lectura.close();
    datosPaciente.close();
    //pausa();
}

void Paciente::crearCuenta(){

    ofstream escritura;
	ofstream dni_pass;
	ifstream verificador;

	bool coincidencia=false;
	string aux_dni;

	escritura.open("Datos_Pacientes.txt",ios::app);
	dni_pass.open("DNI-PASS.txt",ios::app);
	verificador.open("DNI-PASS.txt",ios::in);

	if(escritura.is_open() && verificador.is_open())
	{
	    cin.ignore();
	    system(CLEAR);
		cout<<"\t\t\t\t***CREAR CUENTA***\t\t\t\t\n\n";
		cout<<"\n\tIngrese su DNI: ";
		getline(cin,aux_dni);

		if(aux_dni.length()!=8 )
		{
			do
			{
				system(CLEAR);
				cout<<"\t\t\t\t***CREAR CUENTA***\t\t\t\t\n\n";
				cout<<"\n\tIngrese su DNI con 8 digitos";
				cout<<"\n\tDNI no v\240lido!, intentalo nuevamente: ";
				getline(cin,aux_dni);

			}while(aux_dni.length()!=8);
		}

		do
		{
			verificador.seekg(0);
			int i=0;
			while(getline(verificador,dni))//hasta que acabe de recibir
			{
				if(aux_dni == dni && i%2==0)
				{
					coincidencia=true;
					system(CLEAR);
					cout<<"\t\t\t\t***CREAR CUENTA***\t\t\t\t\n\n";
					cout<<"\n\tYa existe un Paciente con el DNI: "<<aux_dni<<" \n\n";
					cout<<"\n\tIngresa un DNI v\240lido!: ";
					getline(cin,aux_dni);

					while(aux_dni.length()!=8)
					{
						system(CLEAR);
						cout<<"\t\t\t\t***CREAR CUENTA***\t\t\t\t\n\n";
						cout<<"\n\tIngrese su DNI con 8 digitos ";
						cout<<"\n\tDNI no v\240lido!, intentalo nuevamente: ";
						getline(cin,aux_dni);
					}

					break;
				}

				i++;
			}
			if(verificador.eof() && aux_dni!=dni)
				coincidencia=false;

		} while(coincidencia == true);


		system(CLEAR);
		dni=aux_dni;

		cout<<"\t\t\t\t***CREAR CUENTA***\t\t\t\t\n\n";
		cout<<"\n\tDNI  v\240lido! :\n";
		cout<<"\n\tIngrese su DNI: "<<dni;
		cout<<"\n";
		fflush(stdin);
		cout<<"\n\tIngrese su Password: ";
		getline(cin,password);
		fflush(stdin);
		cout<<"\n\tIngrese su Nombre: ";
		getline(cin,nombre);
		fflush(stdin);
		cout<<"\n\tIngrese su Apellido: ";
		getline(cin,apellido);
		fflush(stdin);
		cout<<"\n\tIngrese su Telefono/celular: ";
		getline(cin,numeroTelefono);
		fflush(stdin);
		cout<<"\n\tIngrese su Direccion: ";
		getline(cin,direccion);
		cout<<"\n\tIngrese su Correo: ";
		getline(cin,correo);
		fflush(stdin);

		dni_pass<<"\n"<<dni<<"\n"<<password;
		escritura<<dni<<"\n"<<nombre<<"\n"<<apellido;
		escritura<<"\n"<<numeroTelefono<<"\n"<<direccion<<"\n"<<correo<<"\n";

		//cerrar y guardar datos
        escritura.close();
        dni_pass.close();
        verificador.close();
        //abrir cuenta
		cuenta();

	}
	else{
		cout<<"\n\tError al abrir <DNI-PASS.txt> y/o <Datos_Pacientes.txt> ";
	}

    escritura.close();
    dni_pass.close();
    verificador.close();
    //pausa();
}


void Paciente::cuenta()
{

        int opcion;
        do{
            system(CLEAR);
            cout<<"\n\t\t\t\t***CENTRO MEDICO VIDA***\t\t\t\t\n\n";
            cout<<"\n\tBienvenid@ "<<nombre<<" "<<apellido;
            cout<<"\n\n\n\t1.Solicitar Cita";
            cout<<"\n\n\t2.Ver Receta Medica";
            cout<<"\n\n\t3.Ver Post-Atencion";
            cout<<"\n\n\t4.Ver Facturas";
            cout<<"\n\n\t5.Salir";
            cout<<"\n\n\n\tOpci\242n: ";
            cin>>opcion;

            switch(opcion)
            {
                default:
                    cout<<"Ha ingresado una opci\242n no valida!\n\n";
                    break;
                case 1:
                    //solicitarCita();
                    /*
                    system(CLEAR);
                    cout<<"\n\topcion1";
                    pausa();*/
                    break;
                case 2:
                    //recetaMedica();
                    break;
                case 3:
                    //postAtencion();
                    break;
                case 4:
                    //factura();
                    break;
                case 5:
                    break;
            }
        }while(opcion!=5);

	pausa();


}



void solicitarCita()
{

    string nombre="Aaron",apellido="Apaza";
    /*
    do
    {*/
        int opcion;
        string areaMedica;

        cout<<"\n\t\t\t\t***CENTRO MEDICO VIDA***\t\t\t\t\n\n";
        cout<<"\n\tBienvenid@ "<<nombre<<" "<<apellido;
        cout<<"\n\n\n\tArea Medica que desea cita: \n";
        cout<<"\n\t1.Cardiologia";
        cout<<"\n\t2.Neumologia";
        cout<<"\n\t3.Oncologia";
        cout<<"\n\t4.Hematologia";
        cout<<"\n\t5.Dermatologia";
        cout<<"\n\t6.Oftalmologia";
        cout<<"\n\t7.Urologia";
        cout<<"\n\t8.Nefrologia";
        cout<<"\n\t9.Pediatria";
        cout<<"\n\t10.Medicina general";
        cout<<"\n\n\t11.Salir";
        cout<<"\n\n\n\tOpci\242n: ";
        cin>>opcion;


        switch(opcion)
        {
            default:
                cout<<"Ha ingresado una opci\242n no valida!\n\n";
                break;
            case 1:
                break;


        }
    /*
    }while(opcion!=);
    */
}


void Paciente::generadorCita(){



	string codigo,areaMedica="cardiologia",dni="12345678";


	//el dia de hoy----------
	time_t now = time(NULL);
	now += 86400; // mañana
	struct tm nowlocal;
	nowlocal=*localtime(&now);
	int day,month,year;
	day=nowlocal.tm_mday;
	month=nowlocal.tm_mon+1;
	year=nowlocal.tm_year+1900;


	//-------------------------

	ifstream medicos;//lectura
	ifstream citas;	//lectura
	//ofstream citastxt;
    //citastxt.open("Citas_Cardiologia.txt",ios::app);

	medicos.open("Medicos.txt",ios::in);
	citas.open("Citas_Cardiologia.txt",ios::in);
	//citastxt.open("Citas_Cardiologia.txt",ios::app);
	medicos.seekg(0);

	string aux,aux_codigo;
	string aux_hora="0";

	vector<string> codigos;

	while(!medicos.eof())
	{
		cout<<"Medicos"<<endl;
		getline(medicos,aux_codigo);
		getline(medicos,aux);
		getline(medicos,aux);
		getline(medicos,aux);
		transform(aux.begin(),aux.end(),aux.begin(),::tolower);
		if(aux == areaMedica ){
			//almacenar codigos
			codigos.push_back(aux_codigo);
		}
		getline(medicos,aux);
		getline(medicos,aux);
		getline(medicos,aux);
		getline(medicos,aux);
		getline(medicos,aux);
		getline(medicos,aux);
	}

	medicos.close();
	//medico con menos citas en el dia de mañana
	string dia,mes,anio;
	int hora=510;
	int menor=1000,numeroCitas;


	for (int i=0;i<codigos.size();i++)
	{
		numeroCitas=0;
		citas.close();
        citas.open("Citas_Cardiologia.txt",ios::in);
        citas.seekg(0);



		while(!citas.eof())
        {
            getline(citas,aux_codigo);
			getline(citas,aux);
			getline(citas,aux);
			getline(citas,aux);
			getline(citas,aux);
			getline(citas,aux_hora);
			if(aux_codigo == codigos[i]){
				numeroCitas+=1;
			}

		}

		if(numeroCitas<menor)
		{
			menor=numeroCitas;
			codigo=codigos[i];
			hora= stoi(aux_hora);

		}


	}

	citas.close();

	//asignar cita suponiendo max citas = 16 de 30 min
    ofstream citastxt;
    citastxt.open("Citas_Cardiologia.txt",ios::app);


	if(menor==16){
		now += 86400; // pasado mañana
		day=nowlocal.tm_mday;
		month=nowlocal.tm_mon+1;
		year=nowlocal.tm_year+1900;

		citastxt<<codigo<<endl;
		citastxt<<dni<<endl;
		citastxt<<day<<endl;
		citastxt<<month<<endl;
		citastxt<<year<<endl;
		citastxt<<hora<<endl;
	}
	else
	{
		citastxt<<codigo<<endl;
		citastxt<<dni<<endl;
		citastxt<<day<<endl;
		citastxt<<month<<endl;
		citastxt<<year<<endl;
		citastxt<<hora+30<<endl;

	}
	citastxt.close();


}






int main(){

    //Paciente inicio;

    //inicio.login();

    solicitarCita();




return 0;
}

void pausa()
{
    cout<<"\n\n\tPresiona Enter para Salir...";
    getch();
    system(CLEAR);
}



