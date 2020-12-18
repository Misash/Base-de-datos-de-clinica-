#pragma once
#include "Persona.cpp"

#include<string>

class Paciente : public Persona
{
    public:
        Paciente();
        ~Paciente();
        void crearCuenta();
        void iniciarSesion(std::string);
    
    private:
        float Talla,Peso;
        std::string sintomas; 
        void cuenta();
        void verPerfil();
        void solicitarCita();
		void verCitaMedica();
		void generadorCita(std::string,std::string);
        void generadorTriage(int);
        void verRecetaMedica();
        void verPostAtencion();
};



//FUNCTIONS
void pausa();
void error();

int nrocitasPaciente(std::string ,std::string );
bool is_DNI(const std::string& s);
std::string is_Null(std::string);
std::string NombreAreaMedica(int);
void modificarSintomas(std::string ,std::string);
std::string SI_NO(std::string);