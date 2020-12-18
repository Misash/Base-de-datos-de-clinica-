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

class admin_inventario{
	private:
		int MedicinaCardio;
		int MedicinaNeumo;
		int MedicinaOncolo;
		int MedicinaHemato;
		int MedicinaDermato;
		int MedicinaOftalmo;
		int MedicinaUrologia;
		int MedicinaNefrolo;
		int MedicinaReumato;
		int MedicinaMedGeneral;
	public:
		void MenuInventarioM(); 
		void PedidoMedicamentos();
	    void RevisionStock();
	    void EliminarStock();
};
