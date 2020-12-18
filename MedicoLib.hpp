#pragma once
#include "Persona.cpp"

class Medicos : public Persona{

    public:
    
        Medicos();
        ~Medicos();

        bool cargar_datos_medico(string, string, int);
        void menu_principal();

    private:
        string Horario, Consultorio, Codigo;
        bool Activo;
        int  nroOrden, AreaMedica;

        string ficheroCitas = "CITAS/Citas_";

        void informacion_medico();
        void modificar();
        bool modificar_base_datos_personales(char[], string, int, int);
        bool buscar_citas();
        void visualizar_citas();
        void busqueda_dni(string);
        bool cargar_datos_paciente(string, string&, string&, string&, string&, string&, string&, string&, int&, float&, float&);
        void datos_paciente(string);
        void estado_atencion(string, bool&);
        void obtener_registros(string, string, string, int, float, float);
        void generar_receta_medica(string, string, string, int, float, float);
        void modificar_db_post(string, int , string);
        void modificar_post_atencion(string);
        void fecha();
        void hora();
        void continuar();
};
