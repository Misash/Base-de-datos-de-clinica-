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
	    int medicina[10][3];
		// 0 MedicinaCardio;
		// 1 MedicinaNeumo;
		// 2 MedicinaOncolo;
		// 3 MedicinaHemato;
		// 4 MedicinaDermato;
		// 5 MedicinaOftalmo;
		// 6 MedicinaUrologia;
		// 7 MedicinaNefrolo;
		// 8 MedicinaReumato;
		// 9 MedicinaMedGeneral;
	public:
		void MenuInventarioM();
		void Asignarprecios();
		void PedidoMedicamentos();
	   	void RevisionStock();
	   	void EliminarStock();
        	void cargarInventario();
        	void SalvarInventario();
        	void AlarmadePedido();
        	void SetMinimos();
        	void Vendermedicamentos();
};