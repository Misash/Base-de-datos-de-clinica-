#pragma once

#include <string>

class Persona
{
    public:
        std::string DNI;
        std::string Nombre;
        std::string Apellidos;
        std::string Direccion;
        std::string Edad;
        std::string Email;
        std::string NumeroTelefono;
        std::string Sexo;
        std::string Password;
    
        Persona();
        ~Persona();
        void set_DatosPersonales(std::string );
        void ver_DatosPersonales();

};


