// libreria medico 

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <ctime>
#include <cstring>
#include "Persona.cpp"

using namespace std;

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

Medicos::Medicos(){
    cout << "\nMedico creado\n";
}

Medicos::~Medicos(){
    cout << "\nMedico eliminado\n";
}

bool Medicos::cargar_datos_medico(string codigo, string password, int nOrden){

    Codigo = codigo;
    Password = password;
    ifstream db_medicos;
    nroOrden = nOrden;
    db_medicos.open("MEDICO/Datos_Medicos.txt");

    if (db_medicos.fail()){

        cout << "No se ha podido contactar con la base de datos. Por favor contacte al soporte\n";
        continuar();
        return false;
    }

    string codigoMedicoTemp;
    string null;

    while (!db_medicos.eof()){
        
        getline(db_medicos, codigoMedicoTemp);

        if (codigoMedicoTemp == Codigo){
            db_medicos >> Activo; db_medicos.ignore();

            if (Activo){
                getline(db_medicos, Nombre);
                getline(db_medicos, Apellidos);
                getline(db_medicos, DNI);
                db_medicos >> AreaMedica; db_medicos.ignore();
                getline(db_medicos, Horario);
                getline(db_medicos, Consultorio);
                getline(db_medicos, Direccion);
                getline(db_medicos, NumeroTelefono);
                getline(db_medicos, Email);
                getline(db_medicos, Sexo);
                db_medicos >> Edad; db_medicos.ignore();
                db_medicos.close();
                switch(AreaMedica){

                    case 1: ficheroCitas += "Cardiologia.txt"; break;
                    case 2: ficheroCitas += "Neumologia.txt"; break;
                    case 3: ficheroCitas += "Oncologia.txt"; break;
                    case 4: ficheroCitas += "Hematologia.txt"; break;
                    case 5: ficheroCitas += "Dermatologia.txt"; break;
                    case 6: ficheroCitas += "Oftalmologia.txt"; break;
                    case 7: ficheroCitas += "Urologia.txt"; break;
                    case 8: ficheroCitas += "Nefrologia.txt"; break;
                    case 9: ficheroCitas += "Reumatología.txt"; break;
                    case 10: ficheroCitas += "MedicinaGeneral.txt";
                }
                return true;
            }
            cout << "\nUsted no tiene permitido el ingreso al sistema\n";
            db_medicos.close();       
            continuar();
            return false;
        }
        else{
            for (int i = 0; i < 12; i++){
                getline(db_medicos, null);               
            }
        }
    }

    db_medicos.close();
    cout << "\nNo se han podido cargar sus datos\n";
    continuar();

    return false;
}

void Medicos::menu_principal(){
    
    while (true){

        system("cls");
        cout << "Men\163 principal\n";
        fecha();
        hora();
        cout << "\n1. Informaci\242n principal\n2. Visualizar Citas\n3. Salida\n";

        int seleccion = 0;
        do{
            cout << "Seleccione > "; cin >> seleccion;
        }while(seleccion != 1 && seleccion != 2 && seleccion != 3);
        cin.ignore();
        switch(seleccion){
            case 1: 
                informacion_medico();
                break;
            case 2:
                visualizar_citas();
                break;
            case 3:
                return;  
        }
    }
}

void Medicos::informacion_medico(){

    // imprimir los datos del medicos y permitir su modificacion

    while (true){

        system("cls");

        ver_DatosPersonales(); 
        cout << "\t|     Codigo          | "<< Codigo  << endl;
        cout << "\t+---------------------+------------------------------------+\n";
        cout << "\t|     Area medica     | ";
        switch(AreaMedica){

            case 1: cout << "Cardiologia\n"; break;
            case 2: cout << "Neumologia\n"; break;
            case 3: cout << "Oncologia\n"; break;
            case 4: cout << "Hematologia\n"; break;
            case 5: cout << "Dermatologia\n"; break;
            case 6: cout << "Oftalmologia\n"; break;
            case 7: cout << "Urologia\n"; break;
            case 8: cout << "Nefrologia"; break;
            case 9: cout << "Reumatología\n"; break;
            case 10:cout << "Medicina general\n";
        }
        cout << "\t+---------------------+------------------------------------+\n";
        cout << "\t|     Consultorio     | " << Consultorio << endl;
        cout << "\t+---------------------+------------------------------------+\n";
        cout << "\t|     Horario         | " << Horario << endl;
        cout << "\t+---------------------+------------------------------------+\n";

        int seleccion = 0;

        cout << "\n1. Modificar\n2. Retroceder\n";

        do {
            cout << "Seleccione > "; cin >> seleccion;
        }while(seleccion != 1 && seleccion != 2);

        cin.ignore();

        switch(seleccion){

            case 1:
                modificar();
                break;
            case 2:
                return;
        }
    }
}

void Medicos::modificar(){
    
    char db_medicos[40] = "MEDICO/Datos_Medicos.txt"; 
    char db_medicos_cred[40] = "MEDICO/Credenciales_Medico.txt";

    while (true){

        system("cls");

        int opcion = 0;

        cout << "1. Password\n2. Correo Electronico\n3. Numero telefonico\n4. Retroceder\n";
        do {
            cout << "Seleccionar > "; cin >> opcion;
        }while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);

        cin.ignore();
        string  nuevaContrasena, nuevoEmail, nuevoNumero, confirmacion;

        system("cls");

        switch(opcion){

            case 1:

                // password

                cout << "Reingrese su password > "; getline(cin, nuevaContrasena);
                if (nuevaContrasena == Password){

                    cout << "Ingrese su nuevo password > "; getline(cin, nuevaContrasena);
                    cout << "Confimar el nuevo password > "; getline(cin, confirmacion);
                    if (nuevaContrasena == confirmacion){
                        
                        if (modificar_base_datos_personales(db_medicos_cred, nuevaContrasena, 2, 2)){
                            Password = nuevaContrasena;
                            continuar();
                            return;
                        }
                    }
                    else{
                        cout << "Passwords desiguales.";
                        cin.get();
                        continue;
                    }
                }
                else{
                    cout << "Password errado.";
                    cin.get();
                    continue;
                }

            case 2:
                // e-mail
                cout << "Ingrese el nuevo correo electronico > "; getline(cin, nuevoEmail);
                cout << "Confirmar el nuevo correo electronico > "; getline(cin, confirmacion);
                if (nuevoEmail == confirmacion){
                    if (modificar_base_datos_personales(db_medicos, nuevoEmail, 13, 11)){
                        Email = nuevoEmail;    
                        continuar();
                        return;
                    }
                }
                else{
                    cout << "Correos electronicos desiguales.";
                    cin.get();
                    continue;
                }

            case 3:

                //numero
                cout << "Numero telefonico > "; getline(cin, nuevoNumero);
                if (modificar_base_datos_personales(db_medicos, nuevoNumero, 13, 10)){
                    NumeroTelefono = nuevoNumero;
                    continuar();     
                }
                return;

            case 4:
                return;
        }
    }
}

bool Medicos::modificar_base_datos_personales(char baseDatos[40], string contenido, int cantidad, int nElemento){

    ofstream temp;
    ifstream db;
    temp.open("temp.txt");
    db.open(baseDatos);
    if (db.fail() || temp.fail()){

        cout << "No se ha podido contactar con la base de datos. Por favor contacte al soporte\n";
        db.close();
        temp.close();
        cin.get();
        return false;
    }
    else{

        string dato;
        int i = 0;

        while(!db.eof()){
            if (i == (nroOrden * cantidad) + nElemento - 1){ // (nOrden * n° elementos por individuo en la base de datos + n° orden del elemento a modificar)

                temp << contenido << endl;
                getline(db, dato);
            }
            else{
                getline(db, dato);
                if (dato != ""){
                    temp << dato << endl;
                }
            }
            i++;
        }
        db.close();
        temp.close();
        remove(baseDatos);
        rename("temp.txt", baseDatos);
        return true;
    }
}

void una_palabra(string &cadena){

    // obtener la primera palabra de una cadena
    int i = 0;
    for (i; i < cadena.length(); i++){
        
        if (cadena[i] == ' ') break;
    }

    cadena.resize(i);
}

void una_cadena(string cadena1, string  cadena2, string &cadena3, int cant){

    // construir una cadena apartir de otras dos, rellenando lo faltante con " " 
    string temp;
    int i = cadena1.length(), j = cadena2.length(), max = 0;

    int resto = cant - i - j - 1;

    if (resto  < 0){

        return;
    }
    else{
        if ((resto) % 2 == 0){
            max = resto / 2;
            for (int i = 0; i < max; i++){
                temp += ' ';   
            }
        }
        else{

            max = (resto + 1)/ 2; 
            for (int i = 0; i < max; i++){
                temp += ' ';   
            }
            max -= 1;
        }
        
        temp += cadena1 + ' ' + cadena2;
        for (int i = 0; i < max; i++){
            temp += ' ';
        }
        cadena3 = temp;
        return;
    }
}

bool Medicos::buscar_citas(){

    ifstream db_citas, db_paciente;
    db_citas.open(ficheroCitas);
    db_paciente.open("PACIENTE/Datos_Pacientes.txt");
    if (db_citas.fail() || db_paciente.fail()){

        cout << "No se ha podido contactar con la base de datos. Por favor contacte al soporte\n";
        continuar();
        return false;
    }
    else{
        time_t ahora = time(0);
        tm *times = localtime(&ahora);

        string CodigoTemp, NombrePaciente, ApellidosPaciente, DniTemp, nCita, DNI_paciente, null;
        int estado,  DiaPaciente, MesPaciente, AnioPaciente, HoraPaciente;
        int hora, minutos;
        
        while (!db_citas.eof()){

            getline(db_citas, CodigoTemp);
            if (CodigoTemp == Codigo){

                db_citas >> estado; db_citas.ignore();
                getline(db_citas, nCita);
                getline(db_citas, DNI_paciente);
                db_citas >> DiaPaciente >> MesPaciente >> AnioPaciente >> HoraPaciente;
                db_citas.ignore();

                if(DiaPaciente == times->tm_mday && MesPaciente == (times->tm_mon + 1) && AnioPaciente == times->tm_year + 1900){

                    hora = HoraPaciente / 60;
                    minutos = HoraPaciente % 60;

                    cout << "|  ";  
                    if (hora < 10){
                        cout << "0";
                    }
                    cout << hora << ":";
                    if (minutos < 10){
                        cout << "0";
                    }
                    db_paciente.clear();
                    db_paciente.seekg(0);
                    cout << minutos <<"  | " << DNI_paciente << " |" ;

                    while (!db_paciente.eof()){
                        getline(db_paciente, DniTemp);
                        
                        if (DniTemp == DNI_paciente){
                            getline(db_paciente, NombrePaciente);
                            getline(db_paciente, ApellidosPaciente);

                            una_palabra(NombrePaciente);
                            una_palabra(ApellidosPaciente);

                            string nombreApellido;
                            una_cadena(NombrePaciente, ApellidosPaciente, nombreApellido, 25);
                            cout << nombreApellido << "|";
                            
                            switch(estado){
                                case 0:
                                    cout << "     En espera      |\n"; break;
                                case 1:
                                    cout << "      Atendido      |\n"; break;
                                case 2:
                                    cout << "    No atendido     |\n"; break;
                                case 3:
                                    cout << "     Cancelado      |\n";
                            }
                            cout << "+---------+----------+-------------------------+--------------------+\n";
                            break;
                        }
                        else{
                            for (int i = 0; i < 7; i++){
                               getline(db_paciente, null);
                               
                            }
                        }
                    }
                }
            }
            else{
                for (int i = 0; i < 7; i++){
                    getline(db_paciente, null);
                }
            }
        }
        cout << endl;
        db_paciente.close();
        db_citas.close();
        return true;
    }
}

void Medicos::visualizar_citas(){
    
    bool entrar = true;
    while(entrar){

        system("cls");
        fecha();
        hora();
        cout << "\n+---------+----------+-------------------------+--------------------+\n";
        cout << "|   Hora  |   DNI    |   Nombre del paciente   | Estado de atenci\242n |\n";
        cout << "+---------+----------+-------------------------+--------------------+\n";
        entrar = buscar_citas();

        if (entrar){

            int opcion = 0;
            string busquedaDNI;

            cout << "1. Detalles de paciente\n2. Retroceder\n";

            do {
                cout << "Seleccionar > "; cin >> opcion;

            }while((opcion != 1) && (opcion  != 2));

            cin.ignore();

            switch(opcion){
                
                case 1:    
                    cout << "Ingrese el DNI del paciente > "; getline(cin, busquedaDNI);
                    busqueda_dni(busquedaDNI);
                    break;
                case 2:
                    return;
            }
        }
    }
}

void Medicos::busqueda_dni(string DNIPaciente){

    if (DNIPaciente.length() == 8){  
        
        ifstream db_paciente, db_citas;
        db_paciente.open("PACIENTE/Datos_Pacientes.txt");
        db_citas.open(ficheroCitas);

        if (db_paciente.fail() || db_citas.fail()){
            cout << "No se ha podido contactar con la base de datos. Por favor contacte al soporte\n";
            continuar();
            return ;
        }
        else{

            string codigoTemp, DNITemp, null;
            int estado;
            while(!db_paciente.eof()){

                getline(db_paciente, DNITemp);
                if (DNITemp == DNIPaciente){

                    db_paciente.close();
                    while(!db_citas.eof()){
                        
                        getline(db_citas, codigoTemp);

                        if (codigoTemp == Codigo){

                            db_citas >> estado; db_citas.ignore();
                            getline(db_citas, null);
                            getline(db_citas, DNITemp);
                            getline(db_citas, null);
                            getline(db_citas, null);
                            getline(db_citas, null);
                            getline(db_citas, null);

                            if (estado == 0){
                                db_citas.close();
                                datos_paciente(DNIPaciente);
                                return;
                            }
                        }
                        else{
                            for (int i = 0; i < 7; i++){
                                getline(db_citas, null);
                            }
                        }
                    }
                    db_citas.close();
                    cout << "No hay una cita pendiente con el paciente\n";
                    continuar();
                    return;
                }
                else{
                    for (int i = 0; i < 7; i++){

                        getline(db_paciente, null);
                    }
                }
            }
            cout << "No se ha encontrado el DNI";
            continuar();
            db_paciente.close();
            return ;
        }
    }
    else{
        cout << "La longitud del DNI es invalido\n";
        continuar();
        return;
    }
}

void Medicos::datos_paciente(string DNIPaciente){

    system("cls");
    string nombreP, apellidosP, direccionP, numeroP, emailP, sexo, sintomasP;
    float pesoP, alturaP;
    int edadP;

    if(!cargar_datos_paciente(DNIPaciente, nombreP, apellidosP, direccionP, numeroP, emailP, sexo, sintomasP, edadP, pesoP, alturaP)){
        return;
    }
    else{
        bool ingresar = false;
        while (true){
            
            system("cls");
            fecha();
            hora();
            int opcion = 0;
            cout << "////////////////////////////////////////////////////////////////////////////////////\n";
            cout << "Datos del paciente:\n";
            cout << "\nNombre: " << nombreP << "  Apellidos: " << apellidosP;
            cout << "\nDNI: " << DNIPaciente;
            cout << "\n\nSintomas: " << sintomasP;
            cout << "\n\nPeso: " << pesoP << "  Altura: " << alturaP << "  Edad: " << edadP;
            cout << "\nDirecci\242n: " << direccionP << "  Numero: " << numeroP;
            cout << "\nCorreo electr\242nico: " << emailP;
            cout << "\n////////////////////////////////////////////////////////////////////////////////////\n";

            cout << "\n1. Cambiar estado\n2. Obtener registro del paciente\n3. Post-atencion\n4. Receta medica\n5. Retroceder\n\n";
            do{
                cout << "Seleccione > "; cin >> opcion;
            }while(opcion < 1 || opcion > 5);

            cin.ignore();
            switch(opcion){
                case 1:
                    estado_atencion(DNIPaciente, ingresar);
                    break;
                case 2:
                    obtener_registros(DNIPaciente, nombreP, apellidosP, edadP, pesoP, alturaP);
                    break;
                case 3:
                    modificar_post_atencion(DNIPaciente);
                    break;
                case 4:
                    generar_receta_medica(DNIPaciente, nombreP, apellidosP, edadP, pesoP, alturaP);
                    break;
                case 5:
                    return;
            }   
        }
    }
}

bool Medicos::cargar_datos_paciente(string DNIPaciente, string &nombre, string &apellidos, string &direccion, string &numero, string &email, string &sexo, string &sintomas, int &edad, float &peso, float &altura){

    ifstream db_triage, db_paciente;
    db_paciente.open("PACIENTE/Datos_Pacientes.txt", ios::in);
    db_triage.open("PACIENTE/Triage.txt");


    string DNITemp, null;

    if (db_paciente.fail() || db_triage.fail()){

            cout << "No se ha podido contactar con la base de datos. Por favor contacte al soporte\n";
            continuar();
            return false;
    }
    else{
        
        while(!db_paciente.eof()){

            getline(db_paciente, DNITemp);

            if(DNIPaciente == DNITemp){ 
                getline(db_paciente, nombre);
                getline(db_paciente, apellidos);
                getline(db_paciente, direccion);
                db_paciente >> edad; db_paciente.ignore();
                getline(db_paciente, email);
                getline(db_paciente, numero);
                getline(db_paciente, sexo);
                break;
            }
            else{
                for (int i = 0; i < 7; i++){
                    getline(db_paciente, null);
                }
            }
        }

        while(!db_triage.eof()){

            getline(db_triage, DNITemp);

            if(DNIPaciente == DNITemp){

                db_triage >> peso >> altura; db_triage.ignore();
                
                getline(db_triage, sintomas);
                db_triage >> edad; db_triage.ignore();
                break;
            }
            else{
                for (int i = 0; i < 4; i++){
                    getline(db_triage, null);
                }
            }
        }
        db_paciente.close();
        db_triage.close();
        return true;
    }
}

void Medicos::estado_atencion(string DNIPaciente, bool &ingresar){

    if (!ingresar){
        char db[10][40] = {
            "CITAS/Citas_Cardiologia.txt",
            "CITAS/Citas_Neumologia.txt",
            "CITAS/Citas_Oncologia.txt",
            "CITAS/Citas_Hematologia.txt",
            "CITAS/Citas_Dermatologia.txt",
            "CITAS/Citas_Oftalmologia.txt",
            "CITAS/Citas_Urologia.txt",
            "CITAS/Citas_Nefrologia.txt",
            "CITAS/Citas_Reumatología.txt",
            "CITAS/Citas_MedicinaGeneral.txt"};
        
        int opcion1, opcion2;
        string modificar;

        
        system("cls");
        cout << "Cambiar a \n";
        cout << "1. ATENDIDO\n2. NO ATENDIDO\n3. Cancelar\n\n";
        do{
            cout << "Seleccionar > "; cin >> opcion1;
        }while(opcion1 < 0 || opcion1 > 3);
        cin.ignore();
        if (opcion1 == 1 || opcion1 == 2){
            cout << "\nESTA SEGURO DE ELLO?, NO PODRA VOVER A MODIFICAR ESTE CAMPO.\n\n";
            cout << "1. Si\n2. Cancelar.\n\n"; 

            do{
                cout << "Seleccione > "; cin >> opcion2;

            }while(opcion2 != 1 && opcion2 != 2);
            cin.ignore();
        }   

        if (opcion2 == 1){
            switch(opcion1){

                case 1:
                    modificar = "1"; break;
                case 2: 
                    modificar = "2"; break;
                case 3:
                    continuar();
                    return;
            }
        }
        else{
            continuar();
            return;
        }
        
        ingresar = true;
        ofstream temp;
        ifstream db_citas;

        temp.open("CITAS/temp.txt");
        db_citas.open(ficheroCitas);

        if (db_citas.fail() || temp.fail()){
            cout << "No se ha podido contactar con la base de datos. Por favor contacte al soporte\n";
            continuar();
            return;
        }
        else{

            string codigoTemp, DNITemp, null, estado, nCita;
            bool activado = false;
            while(!db_citas.eof()){

                getline(db_citas, codigoTemp);
                if (codigoTemp != ""){

                    temp << codigoTemp << endl;
                    if (codigoTemp == Codigo && !activado){ 
                        getline(db_citas, estado);
                        
                        if (estado == "0"){
                            getline(db_citas, nCita);
                            getline(db_citas, DNITemp);

                            if (DNIPaciente == DNITemp){

                                temp << modificar << endl << nCita << endl <<DNITemp << endl;
                                activado = true;
                            }
                            else{

                                temp << estado << endl << nCita << endl <<DNITemp << endl;
                            }
                            for (int i = 0; i < 4; i++){

                                getline(db_citas, null);
                                temp << null << endl;
                            }
                        }
                        else{
                            temp << estado << endl;
                            for (int i = 0; i < 6; i++){
                                getline(db_citas, null);
                                temp << null << endl;    
                            }
                        }
                    }
                    else{
                        
                        for (int i = 0; i < 7; i++){

                            getline(db_citas, null);
                            temp << null << endl;

                        }
                    }
                }
            }
            db_citas.close();
            temp.close();
            continuar();
            remove(db[AreaMedica - 1]);
            rename("CITAS/temp.txt", db[AreaMedica - 1]);
            return;
        }
    }
    else{
        cout << "Usted MODIFICO este campo anteriormente, por lo que no podra volver a hacerlo\n";
        continuar();
        return;
    }
}

void Medicos::obtener_registros(string DNIPaciente, string nombreP, string apellidoP, int edadP, float pesoP, float alturaP){

    ifstream db_citas, db_receta;
    int cantidad = 0; 

    db_receta.open("MEDICO/Receta.txt");
    db_citas.open(ficheroCitas);

    string codigoTemp, DNITemp, _fecha, null;
    int nroCita;

    if (db_receta.fail() || db_citas.fail()){

        cout << "No se ha podido contactar con la base de datos. Por favor contacte al soporte\n";
        continuar();
        return;
    }

    while(!db_citas.eof()){

        getline(db_citas, codigoTemp); 

        if (codigoTemp == Codigo){
            getline(db_citas, null); 
            getline(db_citas, null); 
            getline(db_citas, DNITemp); 
            getline(db_citas, null);
            getline(db_citas, null); 
            getline(db_citas, null); 
            getline(db_citas, null); 
            if (DNITemp == DNIPaciente){
                cantidad += 1;
            }
        }
        else{

            for (int i = 0; i < 7; i++){

                getline(db_citas, null);
            }
        }
    }

    // almacenamiento dinamico 

    int **datos = new int *[cantidad];
    
    for (int i = 0; i < cantidad; i++){

        datos[i] = new int [6];   
    }

    int indice = 0;

    db_citas.clear();
    db_citas.seekg(0);

    while(!db_citas.eof()){

        getline(db_citas, codigoTemp); // codigo

        if (codigoTemp == Codigo){

            db_citas >> datos[indice][0] >> datos[indice][1];
            db_citas.ignore(); 
            getline(db_citas, DNITemp);  // DNI
            db_citas >> datos[indice][2] >> datos[indice][3] >> datos[indice][4] >> datos[indice][5];
            db_citas.ignore();

            if (DNITemp == DNIPaciente){

                indice++;
            }
        }
        else{

            for (int i = 0; i < 7; i++){
                getline(db_citas, null);
            }
        }
    }
    
    db_citas.close();
    while(true){

        system("cls");
        fecha();
        hora();
        int opcion = 0;

        cout << "Su historial con el paciente\n";
        cout << "+-----+------------+-------+--------------------+\n";
        cout << "| Nro |   Fecha    | Hora  |       Estado       |\n";
        cout << "+-----+------------+-------+--------------------+\n";

        for (int i = cantidad - 1; i >= 0; i--){
            
            if (datos[i][1] < 10){
                cout << "|  " << datos[i][1] << "  ";
            }
            else if(datos[i][1] < 100){
                cout << "|  " << datos[i][1] << " ";
            }
            else{
                cout << "| " << datos[i][1] << " ";
            }
            cout <<  "| " ;

            if (datos[i][2] < 10) cout << "0";

            cout << datos[i][2] << "/";

            if (datos[i][3] < 10) cout << "0" ;

            cout << datos[i][2] << "/" << datos[i][4] << " | "; 

            int hora = datos[i][5] / 60, minutos = datos[i][5] % 60;

            if (hora < 10) cout << "0";

            cout << hora << ":";

            if (minutos < 10) cout << "0";

            cout << minutos << " |";

            switch(datos[i][0]){
                case 0: cout << "     En espera      |\n"; break;
                case 1: cout << "      Atendido      |\n"; break;
                case 2: cout << "    No atendido     |\n"; break;
                case 3: cout << "     Cancelado      |\n";

            }
            cout << "+-----+------------+-------+--------------------+\n";
        }

        cout << "\n1. Revisar receta\n2. Retroceder\n\n";

        do {

            cout << "Seleccione > "; cin >> opcion;

        }while(opcion != 1 && opcion != 2);
        
        if (opcion == 1){

            int nro;
            bool salir = true;

            while(salir){
                cout << "Ingrese el Nro > "; cin >> nro;
                cin.ignore();
                for (int i = 0; i < cantidad; i++){
                    if (datos[i][1] == nro) salir = false;   
                }
            }
            int nExamenes, nMedicamentos;
            
            db_receta.clear();
            db_receta.seekg(0);
            while(!db_receta.eof()){
                
                getline(db_receta, DNITemp);
                cout << DNITemp << " " <<db_receta.tellg()<<endl;
                continuar();
                if (DNITemp == DNIPaciente){

                    getline(db_receta, null); // nombre y apellido
                    getline(db_receta, null); // area medica
                    getline(db_receta, codigoTemp); 
                    db_receta >> nroCita; db_receta.ignore();
                    getline(db_receta, _fecha);

                    db_receta >> nMedicamentos; db_receta.ignore();
                    string **medicina = new string *[nMedicamentos];

                    for (int i = 0; i < nMedicamentos; i++){
                        medicina[i] = new string [3];
                        for (int j = 0; j < 3; j++){

                            getline(db_receta, medicina[i][j]);
                        }
                    }

                    db_receta >> nExamenes; db_receta.ignore();
                    string *examenes = new string [nExamenes];

                    for (int i = 0; i < nExamenes; i++){
                        getline(db_receta, examenes[i]);
                    }
                    getline(db_receta, null); // end
                    
                    if (nroCita == nro){

                        // impresion 
                        system("cls");
                        cout << "CENTRO MEDICO VIDA\n";
                        cout << _fecha << endl;
                        cout << "\t\t\t\tDR(A)" << Nombre << " " << Apellidos << endl;
                        cout << "\t\t\t\t\t";
                        switch(AreaMedica){

                            case 1: cout << "Cardiologia\n"; break;
                            case 2: cout << "Neumologia\n"; break;
                            case 3: cout << "Oncologia\n"; break;
                            case 4: cout << "Hematologia\n"; break;
                            case 5: cout << "Dermatologia\n"; break;
                            case 6: cout << "Oftalmologia\n"; break;
                            case 7: cout << "Urologia\n"; break;
                            case 8: cout << "Nefrologia"; break;
                            case 9: cout << "Reumatología\n"; break;
                            case 10:cout << "Medicina general\n";

                        }

                        cout << "--------------------------------------------------------------------------------------\n";
                        cout << " PACIENTE: " << nombreP << " " << apellidoP << endl;
                        cout << " PESO: " << pesoP <<"\t\t\tTALLA: " << alturaP << "\t\t\tEDAD: " << edadP << endl;
                        cout << "--------------------------------------------------------------------------------------\n";
                        cout << "MEDICAMENTOS \n\n";
                        for (int i = 0; i < nMedicamentos; i++){
                            
                            cout << medicina[i][1] << " U(s) - " << medicina[i][0] << endl;
                            if (medicina[i][2].size() == 0){
                                cout << "Comentario vacio\n\n";
                            }
                            else{
                                cout << medicina[i][2] << endl << endl;
                            }
                        }
                        cout << "--------------------------------------------------------------------------------------\n";
                        cout << "EXAMENES\n\n";
                        for (int i = 0; i < nExamenes; i++){
                            cout << examenes[i] << endl;
                        }
                        cout << "--------------------------------------------------------------------------------------\n";
                        continuar();
                    }   
                    
                    for (int i = 0; i < nMedicamentos; i++){
                        
                        delete [] medicina[i];
                    }
                    
                    delete [] examenes;
                
                }
                else{

                    // omision
                    for(int i = 0; i < 5; i++){
                        getline(db_receta, null);
                    }

                    db_receta >> nMedicamentos; db_receta.ignore();

                    for (int i = 0; i < nMedicamentos; i++){
                        
                        getline(db_receta, null);
                        getline(db_receta, null);
                        getline(db_receta, null);
                    }

                    db_receta >> nExamenes; db_receta.ignore();

                    for(int i = 0; i < nExamenes; i++){

                        getline(db_receta, null);
                    }
                    getline(db_receta, null);
                }
            }     
        }
        else{
            break;
        }
    }

    db_receta.close();
    for (int i = 0; i < cantidad; i++){
        
        delete[] datos[i];
    }

    return;
}

void Medicos::generar_receta_medica(string DNIPaciente, string nombreP, string apellidoP, int edadP, float pesoP, float alturaP){

    int opcion = 0;
    system("cls");
    ofstream db_receta;
    ifstream db_citas;
    string ficheroCitas = "CITAS/Citas_";
    switch(AreaMedica){

        case 1: ficheroCitas += "Cardiologia.txt"; break;
        case 2: ficheroCitas += "Neumologia.txt"; break;
        case 3: ficheroCitas += "Oncologia.txt"; break;
        case 4: ficheroCitas += "Hematologia.txt"; break;
        case 5: ficheroCitas += "Dermatologia.txt"; break;
        case 6: ficheroCitas += "Oftalmologia.txt"; break;
        case 7: ficheroCitas += "Urologia.txt"; break;
        case 8: ficheroCitas += "Nefrologia.txt"; break;
        case 9: ficheroCitas += "Reumatología.txt"; break;
        case 10: ficheroCitas += "MedicinaGeneral.txt";
    }
    db_receta.open("MEDICO/Receta.txt", ios::app);
    db_citas.open(ficheroCitas);

    if (db_receta.fail() || db_citas.fail()){

        cout << "No se ha podido contactar con la base de datos. Por favor contacte al soporte\n";
        continuar();
        return;
    }
    else{

        string  medicamentos[15], examenes[15], comentariosMed[15];
        int cantidadMed[15];

        time_t ahora = time(0);
        tm *times = localtime(&ahora); 

        int indiceMed = 0, indiceExa = 0;
        bool modificado = false;
        while(true){

            system("cls");
            
            cout << "CENTRO MEDICO VIDA\n";
            cout << times->tm_year + 1900 << "/" << times->tm_mon + 1 << "/" << times->tm_mday << endl;
            cout << "\t\t\t\tDR(A)" << Nombre << " " << Apellidos << endl;
            cout << "\t\t\t\t\t";

            switch(AreaMedica){

                case 1: cout << "Cardiologia\n"; break;
                case 2: cout << "Neumologia\n"; break;
                case 3: cout << "Oncologia\n"; break;
                case 4: cout << "Hematologia\n"; break;
                case 5: cout << "Dermatologia\n"; break;
                case 6: cout << "Oftalmologia\n"; break;
                case 7: cout << "Urologia\n"; break;
                case 8: cout << "Nefrologia"; break;
                case 9: cout << "Reumatología\n"; break;
                case 10:cout << "Medicina general\n";

            }

            cout << "--------------------------------------------------------------------------------------\n";
            cout << " PACIENTE: " << nombreP << " " << apellidoP << endl;
            cout << " PESO: " << pesoP <<"\t\t\tTALLA: " << alturaP << "\t\t\tEDAD: " << edadP << endl;
            cout << "--------------------------------------------------------------------------------------\n";
            cout << "MEDICAMENTOS \n\n";

            for (int i = 0; i < indiceMed; i++){
                
                cout << cantidadMed[i] << " U(s) - " << medicamentos[i] << endl;
                if (comentariosMed[i].size() == 0){
                    cout << "Comentario vacio\n\n";
                }
                else{
                    cout << comentariosMed[i] << endl << endl;
                }
            }
            cout << "--------------------------------------------------------------------------------------\n";
            cout << "EXAMENES\n\n";
            for (int i = 0; i < indiceExa; i++){
                cout << examenes[i] << endl;
            }
            cout << "--------------------------------------------------------------------------------------\n";
            
            cout << "\n1. Adicionar medicamentos\n2. Adicionar examenes\n3. Generar\n4. Cancelar\n\n";

            do{
                cout << "Seleccionar > "; cin >> opcion;
            }while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);

            cin.ignore();

            switch(opcion){

                case 1:
                    // Añadir medicamentos
                    modificado = true;
                    while (indiceMed <= 15){

                        cout << "Ingrese el medicamento: "; getline(cin, medicamentos[indiceMed]);
                        cout << "Ingrese la cantidad: "; cin >> cantidadMed[indiceMed];
                        cin.ignore();
                        cout << "Ingrese algun comentario: "; getline(cin, comentariosMed[indiceMed]);
                        indiceMed++;
                        
                        cout << "\n1. Seguir ingresando: \n";
                        cout << "2. Terminar\n";

                        do{
                            cout << "Seleccionar > "; cin >> opcion;
                        }while(opcion != 1 && opcion != 2); 
                        
                        cin.ignore();
                        if (opcion == 2){
                            break;
                        }
                    }
                    if (indiceMed > 15){

                        cout << "Se llego al limite de medicamnentos. Ya no se podra seguir ingresando datos\n";
                        continuar();
                    }
                    
                    break;
                
                case 2:

                    modificado = true;

                    // añadir examenes
                    while (indiceExa <= 15){

                        cout << "Ingrese el Examen: "; getline(cin, examenes[indiceExa]);
                        indiceExa++;
                        cout << "1. Seguir ingresando: \n";
                        cout << "2. Terminar\n";

                        do{
                            cout << "Seleccionar > "; cin >> opcion;
                        }while(opcion != 1 && opcion != 2); 
                        
                        cin.ignore();
                        if (opcion == 2){
                            break;
                        }
                    }
                    if (indiceExa > 15){

                        cout << "Se llego al limite de Examenes. Ya no se podra seguir ingresando datos\n";
                    }
                    break;

                case 3:
                    if (!modificado){
                        
                        cout << "No se han hecho modificaciones\n";
                        return;
                    }   
                    else{

                        // subir datos al fichero al fichero

                        string CodigoTemp, DniTemp, nCita, DNI_paciente, null;
                        int estado,  DiaPaciente, MesPaciente, AnioPaciente, HoraPaciente;
                        int hora, minutos;

                        while (!db_citas.eof()){

                            getline(db_citas, CodigoTemp);
                            if (CodigoTemp == Codigo){

                                db_citas >> estado; db_citas.ignore();
                                getline(db_citas, nCita);
                                getline(db_citas, DNI_paciente);
                                db_citas >> DiaPaciente;
                                db_citas >> MesPaciente;
                                db_citas >> AnioPaciente;
                                db_citas >> HoraPaciente; db_citas.ignore();

                                if(estado == 0){
                                    
                                    db_receta << DNIPaciente << "\n" << Nombre << " " << Apellidos << "\n" << AreaMedica << "\n" << Codigo << "\n" << nCita << "\n" << AnioPaciente << "/" << MesPaciente << "/" << DiaPaciente << "\n" << indiceMed << "\n";
                                    
                                    for (int i = 0; i < indiceMed; i++){
                                        db_receta << medicamentos[i] << "\n" << cantidadMed[i] << "\n";
                                        if (comentariosMed[i].size() == 0){
                                            db_receta << "Null" << "\n";
                                        }
                                        else{
                                            db_receta << comentariosMed[i] << "\n";
                                        } 
                                    }
                                    db_receta << indiceExa << "\n";
                                    for (int i = 0; i < indiceExa; i++){
                                        db_receta << examenes[i] << "\n" ;
                                    }
                                    db_receta << "end" << "\n";
                                    break;
                                }
                            }
                            else{

                                for (int i = 0; i < 7; i++){

                                    getline(db_citas, null);
                                }
                            }
                        }
                        db_receta.close();
                        db_citas.close();
                        continuar();                     
                        return;
                    }
                case 4:

                    db_receta.close();
                    db_citas.close();
                    continuar();
                    return;
            }
        }
    }
}

void Medicos::modificar_db_post(string DNIPaciente, int posicion, string contenido){

    ifstream db_post_atencion;
    ofstream temp;
    db_post_atencion.open("MEDICO/Post_Atencion.txt");
    temp.open("temp.txt");
    if (db_post_atencion.fail()){

        cout << "No se ha podido contactar con la base de datos. Por favor contacte al soporte\n";
        continuar();
        return;
    }
    else{

        string DNITemp, null;
        while(!db_post_atencion.eof()){

            getline(db_post_atencion, DNITemp);
            if (DNITemp != ""){
            temp << DNITemp << endl;
                if (DNITemp == DNIPaciente){
                    
                    for (int i = 1; i < 6; i++){
                        if ( i == posicion - 1){
                            getline(db_post_atencion, null);
                            temp << contenido << endl;
                        }
                        else{
                            getline(db_post_atencion, null);
                            temp << null << endl;
                        }
                    }
                }
                else{
                    for (int i = 0; i < 5; i++){
                        getline(db_post_atencion, null);
                        temp << null << endl;
                    }
                }
            }
        }

        db_post_atencion.close();
        temp.close();

        remove("MEDICO/Post_Atencion.txt");
        rename("temp.txt", "MEDICO/Post_Atencion.txt");
    }
}

void Medicos::modificar_post_atencion(string DNIPaciente){

    while(true){
        system("cls");
        ifstream db_post_atencion;
        char db_post[30] = "MEDICO/Post_Atencion.txt";
        db_post_atencion.open(db_post);
        
        if(db_post_atencion.fail()){
            cout << "No se ha podido contactar con la base de datos. Por favor contacte al soporte\n";
            continuar();
            return;
        }
        else{
            string DNITemp, null;
            bool habilitado, reqExamen, reqCita, reqHospitalizacion;
            int codEspecialista;
            string modificar;

            while(!db_post_atencion.eof()){

                getline(db_post_atencion, DNITemp);
                

                if(DNITemp == DNIPaciente){

                    db_post_atencion >> habilitado >> reqExamen >> codEspecialista >> reqCita >> reqHospitalizacion;
                    
                    
                    if (habilitado){
                        
                        cout << "Esta HABILITADO\n";
                        cout << "1. Requiere examenes > ";
                        if(reqExamen){
                            cout << "Si\n";
                        }
                        else{
                            cout << "No\n";
                        }
                        cout << "2. Derivacion a otro especialista > ";
                        switch(codEspecialista){

                            case 1: cout << "Cardiologia\n"; break;
                            case 2: cout << "Neumologia\n"; break;
                            case 3: cout << "Oncologia\n"; break;
                            case 4: cout << "Hematologia\n"; break;
                            case 5: cout << "Dermatologia\n"; break;
                            case 6: cout << "Oftalmologia\n"; break;
                            case 7: cout << "Urologia\n"; break;
                            case 8: cout << "Nefrologia\n"; break;
                            case 9: cout << "Reumatología\n"; break;
                            case 10:cout << "Medicina general\n"; break;
                            case -1: cout << "No\n";                     
                        }
                        cout << "3. Requiere otras citas > ";

                        if (reqCita){
                            cout << "Si\n";
                        }
                        else{
                            cout << "No\n";
                        }
                        cout << "4. Requiere hospitalizacion > ";
                        if(reqHospitalizacion){
                            cout << "Si\n";
                        }
                        else{
                            cout << "No\n";
                        }
                        cout << "5. Deshabilitar\n";
                        cout << "6. Retroceder\n";
                        
                        int opcion = 0;
                        do {
                            cout << "Modificar > "; cin >> opcion;
                        }while(opcion < 1 || opcion > 6);
                        
                        cin.ignore();
                        db_post_atencion.close();

                        switch(opcion){
                            case 1:
                                if (reqExamen){
                                    modificar_db_post(DNIPaciente, 3, "0");
                                }
                                else{
                                    modificar_db_post(DNIPaciente, 3, "1");
                                }
                                break;
                            case 2:
                    
                                cout << "1. Cardiologia\n"; 
                                cout << "2. Neumologia\n"; 
                                cout << "3. Oncologia\n"; 
                                cout << "4. Hematologia\n";
                                cout << "5. Dermatologia\n"; 
                                cout << "6. Oftalmologia\n"; 
                                cout << "7. Urologia\n"; 
                                cout << "8. Nefrologia\n"; 
                                cout << "9. Reumatología\n"; 
                                cout << "10. Medicina general\n"; 
                                cout << "11. Eliminar\n\n";  
                                do {                   
                                    cout << "Seleccione > "; cin >> opcion;
                                }while(opcion < 1 || opcion > 11);

                                cin.ignore();
                                switch(opcion){

                                    case 1: modificar_db_post(DNIPaciente, 4, "1"); break;
                                    case 2: modificar_db_post(DNIPaciente, 4, "2"); break;
                                    case 3: modificar_db_post(DNIPaciente, 4, "3"); break;
                                    case 4: modificar_db_post(DNIPaciente, 4, "4"); break;
                                    case 5: modificar_db_post(DNIPaciente, 4, "5"); break;
                                    case 6: modificar_db_post(DNIPaciente, 4, "6"); break;
                                    case 7: modificar_db_post(DNIPaciente, 4, "7"); break;
                                    case 8: modificar_db_post(DNIPaciente, 4, "8"); break;
                                    case 9: modificar_db_post(DNIPaciente, 4, "9"); break;
                                    case 10: modificar_db_post(DNIPaciente, 4, "10"); break;
                                    case 11: modificar_db_post(DNIPaciente, 4, "-1"); 
                                }
                                break;
                            case 3:
                                if (reqCita){
                                    modificar_db_post(DNIPaciente, 5, "0");
                                }
                                else{
                                    modificar_db_post(DNIPaciente, 5, "1");
                                }
                                break;
                            case 4:
                                if (reqHospitalizacion){
                                    modificar_db_post(DNIPaciente, 6, "0");
                                }
                                else{
                                    modificar_db_post(DNIPaciente, 6, "1");
                                }
                                break;
                            case 5:
                                modificar_db_post(DNIPaciente, 2, "0");
                                break;
                            case 6:
                                return;
                        }
                        break;
                    }
                    else{
                        cout << "\nEsta INHABILITADO\n";
                        cout << "1. Habilitar\n2. Retroceder\n";
                        int opcion = 0;

                        do {
                            cout << "Seleccione > "; cin >> opcion;
                        }while((opcion != 1) && (opcion != 2));

                        cin.ignore();

                        db_post_atencion.close();
                
                        switch(opcion){

                            case 1:  
                                modificar_db_post(DNIPaciente, 2, "1");
                                break;
                            case 2:   
                                return;
                        }
                    }
                    break;
                }
                else{
                    for(int i = 0; i < 5; i++){
                        getline(db_post_atencion, null);
                    }
                }
            }
        }
    }
}

void Medicos::fecha(){

    time_t ahora = time(0);
    tm *times = localtime(&ahora);
     // dia de la semana "mod 7"
    int year = 1900 + times->tm_year; 
    string nombreDias[7] = {"Domingo","Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"},
    mes[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre" , "Diciembre"};
    cout << "Fecha: " << nombreDias[times->tm_wday] << " " << times->tm_mday << " de " << mes[times->tm_mon] << " del " << year << "." << endl;
}

void Medicos::hora(){

    time_t ahora = time(0);
    tm *times = localtime(&ahora);
    cout << "Hora: ";
    if (times->tm_hour < 10){
        cout << "0";
    }
    cout <<  times->tm_hour << ":" ;
    if (times->tm_min < 10){
        cout << "0";
    }        
    cout << times->tm_min << endl;
}

void Medicos::continuar(){

    cout << "\nHecho, presione Enter "; cin.get();
}