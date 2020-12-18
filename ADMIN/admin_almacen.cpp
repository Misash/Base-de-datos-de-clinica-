# include "admin_inventario.h"

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

void pausa1(){
    cout<<"\nPresiona Enter para continuar...";
    getch();
    system(CLEAR);
}

void error1(){
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}


void admin_inventario::MenuInventarioM(){
	int OpcionInv;
    do
    {
        cout<<"\t\t\t\t***A.S.INVENTARIO***\t\t\t\t\n\n";
        cout<<"1. Pedido de medicamentos.\n\n";
        cout<<"2. Revision de stock.\n\n";
        cout<<"3. Eliminar stock.\n\n";
        cout<<"4. Volver atras\n\n";
        cout<<"Opci\242n: ";
        cin>>OpcionInv;
        system(CLEAR);
        switch(OpcionInv)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            PedidoMedicamentos();
            break;

        case 2:
            RevisionStock();
            break;
            
        case 3:
        	EliminarStock();
            break;
        
        case 4:
            break;
        }
    }
    while(OpcionInv!=4);
}

void admin_inventario::PedidoMedicamentos(){
	int plus=0;
        cout<<"\t\t\t\t***Pedido de medicamentos***\t\t\t\t\n";
        cout<<"\t\t\t\t***Ingrese la cantidad de medicina que desea***\t\t\t\t\n\n";
			//stoi revisar para volver int
        cout<<"Medicina de Cardiologia: ";
        cin>>plus;
		MedicinaCardio+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Neumologia: ";
        cin>>plus;
		MedicinaNeumo+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de oncologia: ";
        cin>>plus;
        MedicinaHemato+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Dermatologia: ";
        cin>>plus;
		MedicinaDermato+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Oftalmologia: ";
        cin>>plus;
        MedicinaOftalmo+=plus;
        cout<<"\n";
        cout<<"Medicina de Urologia: ";
        cin>>plus;
        MedicinaUrologia+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Nefrologia: ";
        cin>>plus;
        MedicinaNefrolo+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Reumatologia: ";
        cin>>plus;
        MedicinaReumato+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de General: ";
        cin>>plus;
        MedicinaMedGeneral+=plus;
        cout<<"\n";
    pausa1();

}

void admin_inventario::RevisionStock(){
        cout<<"\t\t\t\t***Stock disponible***\t\t\t\t\n\n";
        cout<<"Medicina de Cardio: "<<MedicinaCardio<<endl;
        cout<<"Medicina de Neumologia: "<<MedicinaNeumo<<endl;
        cout<<"Medicina de Hematologia: "<<MedicinaHemato<<endl;
        cout<<"Medicina de Dermato: "<<MedicinaDermato<<endl;
        cout<<"Medicina de Oftalmologia: "<<MedicinaOftalmo<<endl;
        cout<<"Medicina de Urologia: "<<MedicinaUrologia<<endl;
        cout<<"Medicina de Nefrologia: "<<MedicinaNefrolo<<endl;
        cout<<"Medicina de Reumatologia: "<<MedicinaReumato<<endl;
        cout<<"Medicina de General: "<<MedicinaMedGeneral<<endl;
        cout<<"\n\n";
    pausa1();
}

void admin_inventario::EliminarStock(){
	MedicinaCardio=0;
    MedicinaNeumo=0;
    MedicinaHemato=0;
  	MedicinaDermato=0;
    MedicinaOftalmo=0;
    MedicinaUrologia=0;
    MedicinaNefrolo=0;
    MedicinaReumato=0;
    MedicinaMedGeneral=0;
    cout<<"\n\n";
    pausa1();
    cout<<"\t\t\t\t***Stock disponible***\t\t\t\t\n\n";
    cout<<"Medicina de Cardio: "<<MedicinaCardio<<endl;
    cout<<"Medicina de Neumologia: "<<MedicinaNeumo<<endl;
    cout<<"Medicina de Hematologia: "<<MedicinaHemato<<endl;
    cout<<"Medicina de Dermato: "<<MedicinaDermato<<endl;
    cout<<"Medicina de Oftalmologia: "<<MedicinaOftalmo<<endl;
    cout<<"Medicina de Urologia: "<<MedicinaUrologia<<endl;
    cout<<"Medicina de Nefrologia: "<<MedicinaNefrolo<<endl;
    cout<<"Medicina de Reumatologia: "<<MedicinaReumato<<endl;
    cout<<"Medicina de General: "<<MedicinaMedGeneral<<endl;
    cout<<"\n\n";
    pausa1();
}

