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
        cout<<"1. Asignar precios de medicina.\n\n";
        cout<<"2. Pedido de medicamentos.\n\n";
        cout<<"3. Revision de stock.\n\n";
        cout<<"4. Eliminar stock.\n\n";
        cout<<"5. Volver atras\n\n";
        cout<<"Opci\242n: ";
        cin>>OpcionInv;
        system(CLEAR);
        switch(OpcionInv)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            Asignarprecios();
            break;

        case 2:
            PedidoMedicamentos();
            break;

        case 3:
            RevisionStock();
            break;

        case 4:
        	EliminarStock();
            break;

        case 5:
            break;
        }
    }
    while(OpcionInv!=5);
}

void admin_inventario::cargarInventario(){
    int M_aux2[10][2];
    string M_aux[10][2];
    ifstream lectura;
    lectura.open("ADMIN//almacen.txt",ios::in);
    if(lectura.is_open())
    {
        getline(lectura,M_aux[0][0]);//1
        while(!lectura.eof())
        {
            getline(lectura,M_aux[0][1]);
            getline(lectura,M_aux[1][0]);//2
            getline(lectura,M_aux[1][1]);
            getline(lectura,M_aux[2][0]);//3
            getline(lectura,M_aux[2][1]);
            getline(lectura,M_aux[3][0]);//4
            getline(lectura,M_aux[3][1]);
            getline(lectura,M_aux[4][0]);//5
            getline(lectura,M_aux[4][1]);
            getline(lectura,M_aux[5][0]);//6
            getline(lectura,M_aux[5][1]);
            getline(lectura,M_aux[6][0]);//7
            getline(lectura,M_aux[6][1]);
            getline(lectura,M_aux[7][0]);//8
            getline(lectura,M_aux[7][1]);
            getline(lectura,M_aux[8][0]);//9
            getline(lectura,M_aux[8][1]);
            getline(lectura,M_aux[9][0]);//10
            getline(lectura,M_aux[9][1]);
        }
        M_aux2[0][0]=stoi(M_aux[0][0]);
        //M_aux2[0][1]=stoi(M_aux[0][1]);
        M_aux2[1][0]=stoi(M_aux[1][0]);
        //M_aux2[1][1]=stoi(M_aux[1][1]);
        M_aux2[2][0]=stoi(M_aux[2][0]);
        //M_aux2[2][1]=stoi(M_aux[2][1]);
        M_aux2[3][0]=stoi(M_aux[3][0]);
        //M_aux2[3][1]=stoi(M_aux[3][1]);
        M_aux2[4][0]=stoi(M_aux[4][0]);
        //M_aux2[4][1]=stoi(M_aux[4][1]);
        M_aux2[5][0]=stoi(M_aux[5][0]);
        //M_aux2[5][1]=stoi(M_aux[5][1]);
        M_aux2[6][0]=stoi(M_aux[6][0]);
        //M_aux2[6][1]=stoi(M_aux[6][1]);
        M_aux2[7][0]=stoi(M_aux[7][0]);
        //M_aux2[7][1]=stoi(M_aux[7][1]);
        M_aux2[8][0]=stoi(M_aux[8][0]);
        //M_aux2[8][1]=stoi(M_aux[8][1]);
        M_aux2[9][0]=stoi(M_aux[9][0]);
        //M_aux2[9][1]=stoi(M_aux[9][1]);
        medicina[0][0]=M_aux2[0][0];
        //medicina[0][1]=M_aux2[0][1];
        medicina[1][0]=M_aux2[1][0];
        //medicina[1][1]=M_aux2[1][1];
        medicina[2][0]=M_aux2[2][0];
        //medicina[2][1]=M_aux2[2][1];
        medicina[3][0]=M_aux2[3][0];
        //medicina[3][1]=M_aux2[3][1];
        medicina[4][0]=M_aux2[4][0];
        //medicina[4][1]=M_aux2[4][1];
        medicina[5][0]=M_aux2[5][0];
        //medicina[5][1]=M_aux2[5][1];
        medicina[6][0]=M_aux2[6][0];
        //medicina[6][1]=M_aux2[6][1];
        medicina[7][0]=M_aux2[7][0];
        //medicina[7][1]=M_aux2[7][1];
        medicina[8][0]=M_aux2[8][0];
        //medicina[8][1]=M_aux2[8][1];
        medicina[9][0]=M_aux2[9][0];
        //medicina[9][1]=M_aux2[9][1];
    }
    else
    {
        error1();
    }
    lectura.close();
    pausa1();
}


void admin_inventario::SalvarInventario(){
    ofstream auxiliar;
    auxiliar.open("ADMIN//auxiliar.txt",ios::out);
    if(auxiliar.is_open())
    {
        auxiliar<<medicina[0][0]<<"\n"<<medicina[0][1]<<"\n"<<medicina[1][0]<<"\n"<<medicina[1][1]<<"\n"
                <<medicina[2][0]<<"\n"<<medicina[2][1]<<"\n"<<medicina[3][0]<<"\n"<<medicina[3][1]<<"\n"
                <<medicina[4][0]<<"\n"<<medicina[4][1]<<"\n"<<medicina[5][0]<<"\n"<<medicina[5][1]<<"\n"
                <<medicina[6][0]<<"\n"<<medicina[6][1]<<"\n"<<medicina[7][0]<<"\n"<<medicina[7][1]<<"\n"
                <<medicina[8][0]<<"\n"<<medicina[8][1]<<"\n"<<medicina[9][0]<<"\n"<<medicina[9][1]<<"\n";
    }
    else
    {
        error1();
    }
    auxiliar.close();
    remove("ADMIN//almacen.txt");
    rename("ADMIN//auxiliar.txt","ADMIN//almacen.txt");
    pausa1();
}

void admin_inventario::Asignarprecios(){
    int precio;
    cout<<"\t\t\t\t***Ingreso de precios***\t\t\t\t\n";
    cout<<"\t\t\t\t***Ingrese el precio de las medicinas en soles***\t\t\t\t\n\n";
    cout<<"Medicina de Cardiologia: Actual: "<<medicina[0][1]<<" soles"<<"\t precio nuevo: ";
        cin>>precio;
		medicina[0][1]=precio;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Neumologia: Actual: "<<medicina[1][1]<<" soles"<<"\t precio nuevo: ";
        cin>>precio;
		medicina[1][1]=precio;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de oncologia: Actual: "<<medicina[2][1]<<" soles"<<"\t precio nuevo: ";
        cin>>precio;
        medicina[2][1]=precio;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de hermatologia: Actual: "<<medicina[3][1]<<" soles"<<"\t precio nuevo: ";
        cin>>precio;
		medicina[3][1]=precio;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Dermatologia: Actual: "<<medicina[4][1]<<" soles"<<"\t precio nuevo: ";
        cin>>precio;
		medicina[4][1]=precio;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Oftalmologia: Actual: "<<medicina[5][1]<<" soles"<<"\t precio nuevo: ";
        cin>>precio;
        medicina[5][1]=precio;
        cout<<"\n";
        cout<<"Medicina de Urologia: Actual: "<<medicina[6][1]<<" soles"<<"\t precio nuevo: ";
        cin>>precio;
        medicina[6][1]=precio;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Nefrologia: Actual: "<<medicina[7][1]<<" soles"<<"\t precio nuevo: ";
        cin>>precio;
        medicina[7][1]=precio;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Reumatologia: Actual: "<<medicina[8][1]<<" soles"<<"\t precio nuevo: ";
        cin>>precio;
        medicina[8][1]=precio;;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de General: Actual: "<<medicina[9][1]<<" soles"<<"\t precio nuevo: ";
        cin>>precio;
        medicina[9][1]=precio;
        cout<<"\n";
        pausa1();
}
void admin_inventario::PedidoMedicamentos(){
	int plus;
        cout<<"\t\t\t\t***Pedido de medicamentos***\t\t\t\t\n";
        cout<<"\t\t\t\t***Ingrese la cantidad de medicina que desea***\t\t\t\t\n\n";
			//stoi revisar para volver int
        cout<<"Medicina de Cardiologia: ";
        cin>>plus;
		medicina[0][0]+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Neumologia: ";
        cin>>plus;
		medicina[1][0]+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de oncologia: ";
        cin>>plus;
        medicina[2][0]+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de hermatologia: ";
        cin>>plus;
		medicina[3][0]+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Dermatologia: ";
        cin>>plus;
		medicina[4][0]+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Oftalmologia: ";
        cin>>plus;
        medicina[5][0]+=plus;
        cout<<"\n";
        cout<<"Medicina de Urologia: ";
        cin>>plus;
        medicina[6][0]+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Nefrologia: ";
        cin>>plus;
        medicina[7][0]+=plus;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de Reumatologia: ";
        cin>>plus;
        medicina[8][0]+=plus;;
        cout<<"\n";
        fflush(stdin);
        cout<<"Medicina de General: ";
        cin>>plus;
        medicina[9][0]+=plus;
        cout<<"\n";
    pausa1();

}

void admin_inventario::RevisionStock(){
        cout<<"\t\t\t\t***Stock disponible***\t\t\t\t\n\n";
        cout<<"Medicina de Cardio: "<<medicina[0][0]<<"\t Precio: "<<medicina[0][1]<<" soles"<<endl;
        cout<<"Medicina de Neumologia: "<<medicina[1][0]<<"\t Precio: "<<medicina[1][1]<<" soles"<<endl;
        cout<<"Medicina de Oncologia: "<<medicina[2][0]<<"\t Precio: "<<medicina[2][1]<<" soles"<<endl;
        cout<<"Medicina de Hematologia: "<<medicina[3][0]<<"\t Precio: "<<medicina[3][1]<<" soles"<<endl;
        cout<<"Medicina de Dermatologia: "<<medicina[4][0]<<"\t Precio: "<<medicina[4][1]<<" soles"<<endl;
        cout<<"Medicina de Oftalmologia: "<<medicina[5][0]<<"\t Precio: "<<medicina[5][1]<<" soles"<<endl;
        cout<<"Medicina de Urologia: "<<medicina[6][0]<<"\t Precio: "<<medicina[6][1]<<" soles"<<endl;
        cout<<"Medicina de Nefrologia: "<<medicina[7][0]<<"\t Precio: "<<medicina[7][1]<<" soles"<<endl;
        cout<<"Medicina de Reumatologia: "<<medicina[8][0]<<"\t Precio: "<<medicina[8][1]<<" soles"<<endl;
        cout<<"Medicina de General: "<<medicina[9][0]<<"\t Precio: "<<medicina[9][1]<<" soles"<<endl;
        cout<<"\n\n";
    pausa1();
}

void admin_inventario::EliminarStock(){
    for(int i=0; i<10; i++){
        medicina[i][0]=0;
    }
    cout<<"\n\n";
    pausa1();
    RevisionStock();
    pausa1();
    }
