#include <iostream>
#include <conio.h>
#include <fstream>
//#include "myVector.cpp"

#include "MedicoLib.cpp"
#include "PacienteLib.cpp"
#include "BDAdmin.cpp"

using namespace std;

class Clinica{

    private:
        Medicos medico;
        Paciente paciente;
        menuadministrador administrador;

    public:
        Clinica();
        ~Clinica();

        void menu_seleccion();
        bool login(int, string&, string&, int&);

};

Clinica::Clinica(){

    cout << "Clase clinica creada\n";
}
Clinica::~Clinica(){

    cout << "Clase clinica eliminada\n";
}

void Clinica::menu_seleccion(){

    while(true){
        system("cls");
        int opcion, nroOrden = 0;
        string id, password;





        cout << "\n\t #####  #       ### #     # ###  #####     #    "<<endl;
        cout << "\t#    #  #        #  ##    #  #  #     #   # #   "<<endl;
        cout << "\t#       #        #  # #   #  #  #        #   #  "<<endl;
        cout << "\t#       #        #  #  #  #  #  #       #     # "<<endl;
        cout << "\t#       #        #  #   # #  #  #       ####### "<<endl;
        cout << "\t#    #  #        #  #    ##  #  #     # #     # "<<endl;
        cout << "\t #####  ####### ### #     # ###  #####  #     # "<<endl;




        cout << "\n\tSeleccion de inicio de sesion\n";
        cout << "\t1. Empleados\n";
        cout << "\t2. Pacientes\n";
        cout << "\t3. Salir\n\n";

        do{
            cout << "\tSeleccione > "; cin >> opcion;
        }while(opcion != 1 && opcion != 2 && opcion != 3);
        // cin.ignore();

        switch(opcion){

            case 1:
                system("cls");
                cout << "\n\tSeleccione el tipo de empleado\n";
                cout <<"\t1. Medicos\n";
                cout <<"\t2. Administracion\n";
                cout <<"\t3. Retroceder\n\n";

                do {

                    cout << "\tSeleccione > "; cin >> opcion;
                }while(opcion != 1 && opcion != 2 && opcion != 3);

                switch(opcion){

                    case 1:
                        if(login(1, id, password, nroOrden)){
                            
                            if (medico.cargar_datos_medico(id, password, nroOrden)){
                                medico.menu_principal();
                            }

                        }
                        break;
                    case 2:
                        if(login(2, id, password, nroOrden)){
                            // ejecutar codigo de Admin
                            administrador.MenuPrincipal();
                            system("pause");
                        }
                        break;
                }
                break;

            case 2:
                system("cls");
                cout<<"\n\t\t\t\t  ____CLINICA  VIDA____\t\t\t\t\n\n";
                cout<<"\t1. Iniciar Sesi\242n\n\n";
                cout<<"\t2. Crear Cuenta\n\n";
                cout<<"\t3. Retroceder\n\n";

                do {
                    cout << "\tSeleccionar > "; cin >> opcion;
                }while(opcion != 1 && opcion != 2 && opcion != 3);

                switch(opcion){
                    case 1:
                        if(login(3, id, password, nroOrden))
                           paciente.iniciarSesion(id);
                        break;
                    case 2:
                        paciente.crearCuenta();
                        break;
                }
                break;
            case 3:
                return;
        }
    }
}

bool Clinica::login(int opc, string &code, string &password, int &nroOrden){

    string user,pass;
	int contador=0;
	bool ingresa=false, admin = false;

	ifstream db_credenciales;

    switch(opc){
        case 1:
            db_credenciales.open("MEDICO/Credenciales_Medico.txt"); break;
        case 2:
            admin = true;
            code = "admin";
            password = "admin";
            break;
        case 3:
            db_credenciales.open("PACIENTE/Credenciales_Paciente.txt");

    }

    if(db_credenciales.fail() && !admin){

        cout << "No se ha podido contactar con la base de datos. Por favor contacte al soporte\n";
        system("pause");
        return false;
    }


    cin.ignore();// limpia buffer

    do{
        nroOrden = 0;
        system("cls");

        switch(opc){
           case 1: cout << "\n\t***LOGIN DE MEDICOS***\n"; break;
           case 2: cout << "\n\t***LOGIN ADMINISTRADOR***\n"; break;
           case 3: cout<<"\n\n\t\t\t***LOGIN DE PACIENTES***\n"; break;
        }
        cout << "\n\tUser > ";
        getline(cin,user);
        cout<<"\n\tPassword > ";

        char caracter;
        pass = "";
        caracter= getch();
        while(caracter !=13){

            if(caracter != 8){
                pass.push_back(caracter);
                cout<<"*";
            }
            else{
                if(pass.length() > 0){
                    cout<<"\b \b";
                    pass.pop_back();
                }
            }

            caracter=getch();
        }
        if (!admin){
            db_credenciales.clear();
            //busqueda de dni y password en txt
            db_credenciales.seekg(0);
            while(!db_credenciales.eof()){
                getline(db_credenciales, code);
                getline(db_credenciales, password);
                if(code == user && password == pass){
                    ingresa=true;
                    break;
                }
                nroOrden++;
            }
        }
        else{
            if(code == user && password == pass){
                ingresa=true;
                break;
            }
        }
        //intentos
        contador++;
        if (!ingresa){
            cout << "\n\n\tLe quedan " << 3 - contador << " intentos";
            cin.get();
        }

    } while(ingresa !=true && contador <3);

    db_credenciales.close();

    if(ingresa == false){
        cout<<"\n\n\tEl User o password son incorrectos";
        cout<<"\n\tUsted no puedo ingresar al sistema .ADIOS";
        cin.get();
        return false;
    }
    else
    {
        return true;
    }

}
