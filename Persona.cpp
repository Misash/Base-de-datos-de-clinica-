#pragma once
#include "Persona.hpp"
#include <string>
#include <iostream>
#include <fstream>
                       
using namespace std;

//Limpiar pantalla en SO
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif


Persona::Persona(){

    cout<<"\nClase Persona Creada ...";
}

Persona::~Persona(){
    cout<<"\nClase Persona Eliminada...";
}


void Persona::set_DatosPersonales( string credenciales_txt )
{
    
    ifstream verificador;

    bool coincidencia=false;
    string _DNI;

    verificador.open(credenciales_txt.c_str(),ios::in);

    if( verificador.is_open())
    {

        system(CLEAR);
        cout<<"\n\t\t\t\t***INGRESAR DATOS***\t\t\t\t\n\n";
        cout<<"\n\tIngrese su DNI: ";
        cin.ignore();
        getline(cin,_DNI);

        if(_DNI.length()!=8 )
        {
            do
            {
                system(CLEAR);
                cout<<"\n\t\t\t\t***INGRESAR DATOS***\t\t\t\t\n\n";
                cout<<"\n\tIngrese su DNI con 8 digitos";
                cout<<"\n\tDNI no valido!, intentalo nuevamente: ";
                getline(cin,_DNI);

            }while(_DNI.length()!=8);
        }

        do
        {
            verificador.seekg(0);
            int i=0;
            while(getline(verificador,DNI))
            {
                if(_DNI == DNI && i%2==0)
                {
                    coincidencia=true;
                    system(CLEAR);
                    cout<<"\n\t\t\t\t***INGRESAR DATOS***\t\t\t\t\n\n";
                    cout<<"\n\tYa existe un Usuario con el DNI: "<<_DNI<<" \n\n";
                    cout<<"\n\tIngresa un DNI valido!: ";
                    getline(cin,_DNI);

                    while(_DNI.length()!=8)
                    {
                        system(CLEAR);
                        cout<<"\n\t\t\t\t***INGRESAR DATOS***\t\t\t\t\n\n";
                        cout<<"\n\tIngrese su DNI con 8 digitos ";
                        cout<<"\n\tDNI no valido!, intentalo nuevamente: ";
                        getline(cin,_DNI);
                    }
                    break;
                }
                i++;
            }
            if(verificador.eof() && _DNI!=DNI)
                coincidencia=false;

        } while(coincidencia == true);

        system(CLEAR);
		DNI=_DNI;

        cout<<"\n\t\t\t\t***INGRESAR DATOS***\t\t\t\t\n\n";
		cout<<"\n\tDNI  v\240lido! :\n";
		cout<<"\n\tIngrese su DNI: "<<DNI;
		cout<<"\n";
        cout<<"\n\tIngrese su Password: ";
		getline(cin,Password);
		cout<<"\n\tIngrese su Nombre: ";
		getline(cin,Nombre);
		cout<<"\n\tIngrese sus Apellidos: ";
		getline(cin,Apellidos);
        cout<<"\n\tIngrese su Edad: ";
		getline(cin,Edad);
        cout<<"\n\tIngrese su Sexo: ";
		getline(cin,Sexo);
		cout<<"\n\tIngrese su Telefono/celular: ";
		getline(cin,NumeroTelefono);
		cout<<"\n\tIngrese su Direccion: ";
		getline(cin,Direccion);
		cout<<"\n\tIngrese su Correo: ";
		getline(cin,Email);
    }
    else{
        cout<<"\n\tError al abrir "<<credenciales_txt;
    }
     //cerrar y guardar datos

    verificador.close();
}

void Persona::ver_DatosPersonales()
{

    cout << "\n\t\t\t\t\t _____________________________\n";
    cout << "\t\t\t\t\t|     DATOS PERSONALES        |\n";
    cout << "\t\t\t\t\t|_____________________________|\n";
                                       
    cout << "\n\t+---------------------+------------------------------------+\n";
    cout << "\t|     Nombre          | "<<Nombre<<"\n";
    cout << "\t+---------------------+------------------------------------+\n";
    cout << "\t|     Apellidos       | "<<Apellidos<<"\n";
    cout << "\t+---------------------+------------------------------------+\n";
    cout << "\t|     DNI             | "<<DNI<<"\n";
    cout << "\t+---------------------+------------------------------------+\n";
    cout << "\t|     Direccion       | "<<Direccion<<"\n";
    cout << "\t+---------------------+------------------------------------+\n";
    cout << "\t|     Edad            | "<<Edad<<"\n";
    cout << "\t+---------------------+------------------------------------+\n";
    cout << "\t|     Email           | "<<Email<<"\n";
    cout << "\t+---------------------+------------------------------------+\n";
    cout << "\t|     Telefono        | "<<NumeroTelefono<<"\n";
    cout << "\t+---------------------+------------------------------------+\n";
    cout << "\t|     Genero          | "<<Sexo<<"\n";
    cout << "\t+---------------------+------------------------------------+\n";
    
}