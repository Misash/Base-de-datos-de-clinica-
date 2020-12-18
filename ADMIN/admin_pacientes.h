#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

using namespace std;

class admin_pacientes{
	private:
		string Altura;
	    string Peso;
	    string Temperatura;
	    string Saturacion_Oxigeno;
	    string Presion;
	    string alergias;
	public:
		void MenuPacientes();
		void Llenartriage();
		void HistorialMedico();
};
