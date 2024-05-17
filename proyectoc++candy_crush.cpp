#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

// Constantes
#define MAX_JUGADORES 20
#define MAX_STRING_CHARACTERS 100
#define MAX_PARTIDAS 20

/* Estructuras del proyecto */

struct partida {
int nivel;  //1-facil,2-principiante,3-dificil,4-personalizado
string nombre;
double tiempo;
int puntaje;
int win;
};
struct jugador        //j[pod].partidas[j[pod].tamp].puntaje
{
string nombre;
string alias;
string apellido;
string correo; /*datos del usuario en un arreglo de estructuras*/
partida partidas[MAX_PARTIDAS ];//las jugadas del usuario
int tamp;//tamp
int num_partidas;

};


/* Firma de funciones */
void menuprincipal(int  tabla[][60],int tamf,int tamc,jugador j[],int tam,int p);
int configuracion();
void crearUsuario(jugador j[], int tam);
void mostrarUsuarios(jugador j[], int tam); /*muestra usuarios registrados*/
void nivelesDeJuego(int t[][60], int tamf, int tamc,jugador j[],int tam);//pod es el indice del jugador
void personalizarTablero(int t[][60], int tamf, int tamc,jugador j[],int tam); /*personalizar tablero*/
//void jugar(jugador j, uint8_t nivel);
void  jugar(int t[][60],int tamf,int tamc,jugador j[],int tam,int p  );
int seguir(int t[][60],int tamf,int tamc );
void Estadisticas(jugador j[],int tam, int op1, int op2);
//--------------------------------------------------------------------------
int main()
{
// Variables de juego
jugador j[MAX_JUGADORES]; //arreglo de informacion de los jugadores

int tabla[20][60], tamf, tamc,pod;
int tam = 0;
string op;
{

 system("color D");
cout<<R"(
/==============================================================================================/
 ______  __    __  ______  ______  ______     ______  __  __  ______  __  ______  ______
/\  ___\/\ -./  \/\  __ \/\  == \/\__  _\   /\  ___\/\ \_\ \/\  __ \/\ \/\  ___\/\  ___\
\ \___  \ \ \-./\ \ \  __ \ \  __<\/_/\ \/   \ \ \___\ \  __ \ \ \/\ \ \ \ \ \___\ \  __\
 \/\_____\ \_\ \ \_\ \_\ \_\ \_\ \_\ \ \_\    \ \_____\ \_\ \_\ \_____\ \_\ \_____\ \_____\
  \/_____/\/_/  \/_/\/_/\/_/\/_/ /_/  \/_/     \/_____/\/_/\/_/\/_____/\/_/\/_____/\/_____/
/==============================================================================================/
)";

                 cout<<"        karol Geraldine Ceballos "<<endl;
                 cout<<"   \t        Sara Camila castiblanco "<<endl;
                 cout<<"    \t        Laura Sofia Rozo "<<endl;
                 cout<<endl;
system("pause");
system("cls");

cout <<endl<< "'Bienvenido al programa'" << endl;
cout<<endl;

cout << "* Primer usuario! " << endl;
cout << "Ingrese su nombre: ";
getline(cin, j[0].nombre, '\n');//
cout << "Ingrese su apellido: ";
getline(cin, j[0].apellido, '\n');
cout << "Ingrese el alias: ";
cin >> j[0].alias;
cout << "Ingrese su correo: ";
cin >> j[0].correo;
cout<<endl;
cout<<"registro completado :)!"<<endl;
tam++;
system("pause");//presionar cualquier tecla
system("cls");//borrar la consola
  cin.ignore(MAX_STRING_CHARACTERS, '\n');
}

j[tam].tamp=0;
j[tam].partidas[j[tam].tamp].win=0;
cout<<"desea personalizar el tablero o escoger un nivel de dificultad: "<<endl;
cout<<"opcion 1 ingrese (1) opcion 2 ingrese(2):";
cin>>op;
while(op!="1"&&op!="2"){
 cout<<"error opcion invalida "<<endl;
 cout<<endl;
cout<<"desea personalizar el tablero o escoger un nivel de dificultad: "<<endl;
cout<<"opcion 1 ingrese (1) opcion 2 ingrese(2):"<<endl;
cin>>op;

}
 cout<<endl;
  system("pause");//
  system("cls");

if(op=="1"){
  personalizarTablero(tabla,tamf,tamc,j,tam); //personalizar tablero
}
if(op=="2"){
 //escoger el nivel de dificultad
 nivelesDeJuego(tabla,tamf,tamc,j,tam );
}



menuprincipal(  tabla, tamf,tamc, j,tam,pod);

}

void menuprincipal(int tabla[][60],int tamf,int tamc,jugador j[],int tam,int p){

int z ,opece1 ; // z:opcion del switch del menu principal y tabla es el juego
string op3, eliminar, opc, op, r,respi,op4; //op4 opcion del caso 1 de jugar opc: opcion del usuario para el menu
int opc2, cont = 0, verificar, est1=1, est2=1; //opc2 es opcion menu configuracion
int tamp = 0, tami = 0, tama = 0,pod=-1;
char re='x';
string nom,opece2;
jugador auxia,auxit,auxic;//auxiliar ascentente como descendente
char resp; /*r eliminar usuario*///respi opcion del caso 4 del menu
int sep=0;//tamanio de arreglo de apellidos
string apellidosest[100];//arreglo de apellidos
string auxp;//para ordenar es el aux del apellido


do
{

cout << endl;
cout << "//Menu //" << endl;
cout << endl;
cout << "1.jugar " << endl;
cout << "2.configuracion " << endl;
cout << "3.estadistica" << endl;
cout << "4.salir  " << endl;
cout << "opcion (numero):";

cin >> opc;

cout<<endl;

    system("pause");
    system("cls");

while (opc != "1" && opc != "2" && opc != "3" && opc != "4")

{
cout << endl;
cout << "ERROR: Opcion no valida" << endl;
cout << endl;
cout << "//menu //" << endl;
cout << endl;
cout << "1.Jugar " << endl;    //digita mal
cout << "2.Configuracion " << endl;
cout << "3.Estadistica" << endl;
cout << "4.Salir  " << endl;
cout << "opcion (numero):";

cin >> opc;

system("pause");
system("cls");

}

if (opc == "1"){
z = 1;
}
if (opc == "2"){
z = 2;
}
if (opc == "3"){
z = 3;
}
if (opc == "4"){
z = 4;
}
switch (z)
{
case 1:

    cout<<"'jugar'"<<endl;
    cout<<endl;

    cout<<"desea comenzar un juego nuevo(n) "<<endl;
    cout<<"cargar juego anterior(a) "<<endl;
    cout<<"devolverse(d)"<<endl;
    cin>>op4;

    system("pause");
    system("cls");

    while(op4!="n"&&op4!="N"&&op4!="a"&&op4!="A"&&op4!="d"&&op4!="D")
        {
        cout<<"opcion invalida "<<endl;
        cout<<"desea comenzar un juego nuevo(n) "<<endl;
        cout<<"cargar juego anterior(a) "<<endl;
        cin>>op4;
        system("pause");
        system("cls");
        }
    cout<<"El tiempo guardado es: "<<j[p].partidas[j[p].tamp-1].tiempo<<endl;
    if(op4=="a"||op4=="A")
        {
    jugar( tabla, tamf, tamc , j, tam ,p);
        }

    if(op4=="n"||op4=="N")
        {
          nivelesDeJuego(tabla, tamf, tamc,j,tam);
        }

break;

//---------------------CONFIGURACION-------------------------------

case 2://

    do
    {
    opc2 = configuracion();
    switch (opc2)
    {
    r = "i";
    case 1://

    cout << "nivel de dificultad: " << endl;
    cout << "seguro que deseas cambiar el nivel de dificultad?" << endl;
    cout << "Aviso:Tu partida sera eliminada. Ingresa S para si y N para no: ";
    cin >> r;

    cout<<endl;

    system("pause");
    system("cls");

    //-------------------------NIVEL------------------------

    while (r != "s" && r != "S" && r != "N" && r != "n")

    {
    cout << endl;
    cout << "ERROR. Opcion no valid" << endl;
    cout << "seguro que deseas cambiar el nivel de dificultad?" << endl;
    cout << "Tu partida sera eliminada. Ingresa S para si y N para no: ";
    cin >> r;

    cout<<endl;
    system("pause");
    system("cls");
    }

    if (r == "s" || r == "S")
    {
    cout << endl;
    nivelesDeJuego(tabla, tamf, tamc,j,tam);//niveles de l juego
    cout<<endl;
    }

    break;

//--------------------------PERSONALIZAR------------------------

    case 2: //tablero
    cout << "Personalizar tablero: " << endl;
    cout << "seguro que deseas personalizar el tablero?" << endl;
    cout << "Tu partida sera eliminada. Ingresa S para si y N para no: "<<endl;
    cout<<"opcion: ";

    cin >> r;

    cout<<endl;

    system("pause");
    system("cls");

    while (r != "s" && r != "S" && r != "N" && r != "n")
    {
        cout << endl;
        cout << "ERROR. Opcion no valid" << endl;
        cout << "seguro que deseaspersonalizar el tablero?" << endl;
        cout << "Tu partida sera eliminada. Ingresa S para si y N para no: ";
        cin >> r;

        cout<<endl;
        system("pause");
        system("cls");
    }

    if (r == "s" || r == "S")
    {
    cout << endl;
    personalizarTablero(tabla, tamf, tamc,j,tam);//personalizar tablero
    cout<<endl;
    }
    break;

//--------------------------JUGADOR------------------------
    case 3:

    do

    {       // ciclo del menu de jugadores
    cout << endl;
    cout << "//jugadores//" << endl;
    cout << "- Crear un nuevo usuario ingrese 'c'" << endl; /*menu del admin*/
    cout << "- Eliminar un jugador 'e'" << endl;
    cout << "- Mostrar estadisticas 'm'" << endl;
    cout << "- Devolverse 'd'" << endl;
    cout << "opcion: ";
    cin >> op3;

    cout << endl;

    system("pause");
    system("cls");

    while (op3 != "c" && op3 != "e" && op3 != "C" && op3 != "E" && op3 != "M" && op3 != "m" && op3 != "d" && op3 != "D")
    {
    cout << "error opcion invalida " << endl;
    cout << "crear jugador ingrese 'c'" << endl;
    cout << "eliminar un jugador 'e'" << endl;
    cout << "mostrar estadisticas 'm'" << endl;
    cout << "devolverse 'd'" << endl;
    cout << "opcion: ";

    cin >> op3;
    cout << endl;
    system("pause");
    system("cls");
    }
//---------------------CREAR USUARIO------------------------
    if (op3 == "c" || op3 == "C")

    {
    crearUsuario(j, tam);
    cout<<endl;

    tam++;
    cout << endl;
    cout << "desea ver los usuarios registrados?(s/n): ";
    cin >> resp;
    cout << endl;

    system("pause");
    system("cls");

    while (resp != 's' && resp != 'S' && resp != 'n' && resp != 'N')

    {
    cout << "respuesta no valida" << endl;
    cout << "desea ver los usuarios registrados?(s/n) ";
    cin >> resp;
    cout<<endl;

    system("pause");
    system("cls");

    }

    cout << endl;

//-----------------MIRAR USUARIO------------------------

    if (resp == 's' || resp == 'S')

    {
    mostrarUsuarios(j, tam);
    cout<<endl;
    }

    cout << endl;

    }

//--------------ELIMINAR USUARIO--------------------

    if (op3 == "e" || op3 == "E")

    {
    verificar = -1;
    r = "s";
    while ((verificar == -1) && (r == "s" || r == "S"))
    {
        cout << "ingrese el alias del usuario que desea eliminar " << endl;
        cin >> eliminar;
        cout<<endl;

        system("pause");
        system("cls");

    for (int i = 0; i < tam; i++)
    {
        if (eliminar == j[i].alias)
        {
            verificar = i;//guarda el indice de la persona que se va a eliminar
            i = tam + 1;//para salirse del for
            tam = tam - 1; /*disminuye el tamanio*/
        }
    }

    if (verificar == -1)
    {
        cout << "error el alias no existe " << endl;
        cout << "desea eliminar otro usuario ?(s/n) " << endl;
        cin >> r;
        cout<<endl;
        system("pause");
        system("cls");
    }

    }

    if (verificar != -1)//encontraste a la persona
    {
    for (int i = verificar; i < tam; i++)
    {
        j[i] = j[i + 1];
    }
    cout << endl;
    cout << "desea ver los usuarios registrados?(s/n) ";//verifica si se elimino
    cin >> resp;
    cout << endl;
    system("pause");
    system("cls");

    while (resp != 's' && resp != 'S' && resp != 'n' && resp != 'N')
    {
        cout << "respuesta no valida" << endl;
        cout << "desea ver los usuarios registrados?(s/n) ";
        cin >> resp;
        cout<<endl;

        system("pause");
        system("cls");

    }
//--------------VER USUARIOS--------------------
    cout << endl;
    if (resp == 'S' || resp == 's')
    {
        mostrarUsuarios(j, tam);
    }
    cout << endl;
    }

    }
//--------------ESTADISTICAS--------------------

if (op3 == "m" || op3 == "M")
{
    cout<<endl;
    system("pause");
    system("cls");

/*mostrar estadistica*/

    do{
    cout<<"estadisticas"<<endl;
    cout<<"-orden de cantidad de juegos presione 1"<<endl;
    cout<<"-orden por tiempos presione 2"<<endl;
    cout<<"-orden por puntajes presione 3"<<endl;
    cout<<"-orden por apellido presione 4"<<endl;
    cout<<"-devolverse presione 5"<<endl;
    cout<<"opcion: "; cin>>opece2;

    while(opece2!="1"&&opece2!="2"&&opece2!="3"&&opece2!="4"&&opece2!="5"){

        cout<<endl;
        cout<<"opcion invalida! "<<endl;
        cout<<"-orden de cantidad de juegos presione 1"<<endl;
        cout<<"-orden por tiempos presione 2"<<endl;
        cout<<"-orden por puntajes presione 3"<<endl;
        cout<<"-orden por apellido ascendentemente presione 4"<<endl;
        cout<<"-devolverse presione 5"<<endl;
        cout<<"opcion: "; cin>>opece2;

        }

    if(opece2=="1")
    {
    cout<<"Estadisticas por jugador se organizaran por la cantidad de juegos"<<endl;
    est2=2;
    system("pause");
     system("cls");
    }

    if(opece2=="2")
    {
    cout<<"Los mejores puntajes y tiempos seran organizados por puntaje"<<endl;
    est1=1;
    system("pause");
     system("cls");
    }

    if(opece2=="3")
    {
    cout<<"Los mejores puntajes y tiempos seran organizados por puntaje"<<endl;
    est1=2;
    system("pause");
     system("cls");
    }

    if(opece2=="4")
    {
    cout<<"Estadisticas por jugador se organizaran por apellido ascendentemente"<<endl;
    est2=1;
    system("pause");
     system("cls");
    }

    if(opece2=="5")
        opece1=5;


    }while(opece1!=5);


}//es del if de estadistica


} while (op3 != "D" && op3 != "d"); /*ciclo do while caso 3*/



break;

system("pause");
     system("cls");


}

//------------------------------------------------------------------switch

    }  while (opc2 != 4);
//------------------------FINAL DEL CASO 2----------------------------------
    break;

case 3:

//estadisticas
Estadisticas(j,tam, est1, est2);
            cout<<endl;

system("pause");
system("cls");

//----------------------------------------------------------

break;



case 4:

cout<<"seguro que desea salir del juego(s/n)?:"<<endl;

cin>>respi;
system("pause");
system("cls");

        while(respi!="s"&&respi!="S"&&respi!="N"&&respi!="n"){
        cout<<"error opcion no valida "<<endl;
        cout<<"?seguro que desea salir del juego? : "<<endl;
        cin>>respi;

        system("pause");
        system("cls");
        }

 if(respi=="s"||respi=="S")
    {
cout<<R"(
                                                                 / /
   _    _    ____ _____  _      _        _      ____  ____   _____  _____ __  __    _    _
| | | |  / \  / ___|_   _|/ \    | |      / \    |  _ \|  _ \ / _ \ \/ |_ _|  \/  |  / \  | |
| |_| | / _ \ \___ \ | | / _ \   | |     / _ \   | |_) | |_) | | | \  / | || |\/| | / _ \ | |
|  _  |/ ___ \ ___) || |/ ___ \  | |___ / ___ \  |  __/|  _ <| |_| /  \ | || |  | |/ ___ \|_|
|_| |_/_/   \_|____/ |_/_/   \_\ |_____/_/   \_\ |_|   |_| \_\\___/_/\_|___|_|  |_/_/   \_(_)

)";

    }
else{
    z=0;
    }

break;
    }

} while (z != 4);
cout<<endl;

    system("pause");
}

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
int configuracion()
{
int opc;
cout << endl;
cout << "//configuracion //" << endl;
cout << endl;
cout << "1.cambiar nivel de dificultad " << endl;
cout << "2.personalizar tablero " << endl;
cout << "3.administrar jugadores " << endl;
cout << "4.devolverse " << endl;
cout << "opcion (numero):";
cin >> opc;
cout << endl;

    system("pause");
system("cls");
while (opc != 1 && opc != 2 && opc != 3 && opc != 4)
{
cout << "error opcion invalida " << endl;
cout << endl;
cout << "//menu //" << endl;
cout << endl;
cout << "1.jugar " << endl;
cout << "2.configuracion " << endl;
cout << "3.estadistica" << endl;
cout << "4.salir  " << endl;
cout << "opcion (numero):";
cin >> opc;
cout<<endl;
       system("pause");
   system("cls");
}
cout << endl;

return opc;
}
//------------------------------------------------------------------------------------------------
void crearUsuario(jugador j[], int tam)
{

cout << "//crear usuario //" << endl;
//cout<<"enter para crear usuario.. "; cin.ignore(MAX_STRING_CHARACTERS, '\n');
int error = 1, d = 0;
string x;
bool rep = true; /*la primera vez muestre todo lo que le pide en los datos*/
char rep2[3]; /*arreglo creado en la funcion que guarda en cada casilla el que se repite*/
while (error == 1)
{

if (rep == true || rep2[0] == 'N')
{


 // cin.ignore(MAX_STRING_CHARACTERS, '\n');
cout<<"enter  para continuar.. "<<endl; cin.ignore(MAX_STRING_CHARACTERS, '\n');
cout << "Ingrese su nombre: ";
getline(cin, j[tam].nombre, '\n');


rep2[0] = 0; /*aqui limpia el arreglo*/
}

if (rep == true)
{
            cout<<"enter para continuar.. "<<endl; cin.ignore(MAX_STRING_CHARACTERS, '\n');
cout << "ingrese su apellido: ";
getline(cin, j[tam].apellido, '\n');

}
if (rep == true || rep2[1] == 'L')
{

cout << "Ingrese su alias: ";
cin >> j[tam].alias;
system("pause");
rep2[1] = 0;
/*aqui limpia el arreglo*/


}
if (rep == true || rep2[2] == 'C')
{

cout << "Ingrese su correo: " ;
cin >> j[tam].correo;
system("pause");
rep2[2] = 0; /*aqui limpia el arreglo*/

}
cout << endl;
rep = false;
error = 0; /*error=1 si preguntando*/ /*si no se repite esta en cero y se sale de while*/
for (int i = 0; i < tam; i++)
{
if (j[i].nombre == j[tam].nombre)
{
cout << "error se repite el nombre "<<endl;
if(x=="2vez"){
cout<<" enter para ingresar de nuevo el nombre.. ";
}
x="2vez";
rep2[0] = 'N'; /*aqui llena el arreglo*/
error = 1;
i = tam + 1; /*para que se salga de una vez del for*/
}
if (j[i].alias == j[tam].alias)
{
cout << "error se repite el alias " << endl;
system("pause");

error = 1;
rep2[1] = 'L'; /*aqui llena el arreglo*/
i = tam + 1;   /*para que se salga de una vez del for*/
}
if (j[i].correo == j[tam].correo)
{
cout << "error se repite correo " ;system("pause");
cout<<endl;


error = 1;
rep2[2] = 'C'; /*aqui llena el arreglo*/
i = tam + 1;   /*para que se salga de una vez del for*/
}
}
}
j[tam].partidas[j[tam].tamp].tiempo=0;
j[tam].partidas[j[tam].tamp].puntaje=0;
j[tam].partidas[j[tam].tamp].win=0;
cout << " registro completado :) " << endl;
cout<<endl;

}
//------------------------------------------------------------------------------------------------
void mostrarUsuarios(jugador j[], int tam)
{
cout << endl;
cout << "//registrados//" << endl;

for (int m = 0; m < tam; m++)
{
cout << "* usuario codigo: " << m << endl;
cout << "* nombre: " << j[m].nombre << endl;
cout << "* apellido: " << j[m].apellido << endl;
cout << "* alias: " << j[m].alias << endl;
cout << "* correo: " << j[m].correo << endl;
cout << "----------------------------" << endl;
}
cout<<endl;
system("pause");
system("cls");
}
//------------------------------------------------------------------------------------------------
void nivelesDeJuego(int t[][60], int tamf, int tamc,jugador j[],int tam)
{
string nom;
int pod=-1;
char re='x';

string nivel;
cout << endl;
cout << "//niveles del juego!//" << endl;
cout << "1.facil" << endl;
cout << "2.intermedio" << endl;
cout << "3.avanzado" << endl;
cout << "opcion (numero): ";
cin >> nivel;
cout<<endl;
system("pause");
system("cls");




while(pod==-1&&( re!='s' || re!= 'S')){

cout<<"Ingrese el Nombre del jugador: "<<endl;
cin>> nom;
for (int i = 0; i < tam; i++)
{

if (nom == j[i].nombre)
{

pod = i;
i = tam + 1;
re='s';
}
}
if (pod == -1)
{
cout << "error el usuario no existe " << endl;
cout << "desea registrarse? Si: ingrese 's'. No: cualquier tecla" << endl;
cin >> re;
cout<<endl;
  system("pause");
  system("cls");
 if(re=='s'||re=='S'){
  crearUsuario( j,  tam);
  tam++;
  pod=tam;

 }

  }

  }
system("pause");
system("cls");


while (nivel != "1" && nivel != "2" && nivel != "3")
{
cout << "error opcion invalida " << endl;
cout << "//niveles del juego!//" << endl;
cout << "1.facil" << endl;
cout << "2.intermedio" << endl;
cout << "3.avanzado" << endl;
cout << "opcion (numero): ";
cin >> nivel;
cout<<endl;
system("pause");
system("cls");
}
cout << endl;
if (nivel == "1")
{
tamf = 9;
tamc = 9;
for (int i = 0; i < tamf; i++)
{
for (int j = 0; j < tamf; j++)
{
t[i][j] = 1 + rand() % 5;
}
}
j[pod].partidas[j[pod].tamp].nivel=1;


}
if (nivel == "2")
{
tamf = 16;
tamc = 16;
for (int i = 0; i < tamf; i++)
{
for (int j = 0; j < tamc; j++)
{
t[i][j] = 1 + rand() % 5;
}
}
for (int i = 0; i < tamf; i++)
{
for (int j = 0; j < tamc; j++)
{
t[i][j] = 1 + rand() % 5;
}
}
j[pod].partidas[j[tam].tamp].nivel=2;



}
if (nivel == "3")
{
tamf = 16;
tamc = 30;
for (int i = 0; i < tamf; i++)
{
for (int j = 0; j < tamc; j++)
{
t[i][j] = 1 + rand() % 5;
}
}
j[pod].partidas[j[pod].tamp].nivel=3;
}
j[pod].tamp=j[pod].tamp+1;
j[pod].partidas[j[pod].tamp].tiempo=0;
j[pod].partidas[j[pod].tamp].puntaje=0;

system("pause");
     system("cls");

jugar( t, tamf, tamc,j,tam ,pod );
}
//------------------------------------------------------------------------------------------------
void personalizarTablero(int t[][60], int tamf, int tamc,jugador j[],int tam)
{
string nom;
int pod=-1;
char re='x';
cout << endl;
cout << "//personalizar tablero//" << endl;





while(pod==-1&&( re!='s' || re!= 'S')){

cout<<"Ingrese el Nombre del jugador: "<<endl;
cin>> nom;
for (int i = 0; i < tam; i++)
{

if (nom == j[i].nombre)
{

pod = i;
i = tam + 1;
re='s';
}
}
if (pod == -1)
{
cout << "error el usuario no existe " << endl;
cout << "desea registrarse ?si es si 's'si no cualquier tecla" << endl;
cin >> re;
cout<<endl;
  system("pause");
  system("cls");
 if(re=='s'||re=='S'){
  crearUsuario( j,  tam);
  tam++;
  pod=tam;

 }

  }

  }
system("pause");
system("cls");

cout << "ingrese el tamanio de filas del tablero(max 20):";
cin >> tamf;

cout<<endl;

while (tamf < 0 || tamf > 20)
{
cout << "ingresaste incorrectamente las filas (max20)" << endl;
cout << "ingrese el tamanio de filas del tablero(max 20):";
cin >> tamf;
cout<<endl;
system("pause");
system("cls");
}
cout << endl;
cout << "ingrese el tamanio de columnas del tablero(max 60):";
cin >> tamc;
cout << endl;
while (tamc < 0 || tamc > 60)
{
cout << "ingresaste incorrectamente las filas (max60)" << endl;
cout << "ingrese el tamanio de filas del tablero(max 20):";
cin >> tamc;
cout<<endl;
system("pause");
system("cls");
}
for (int i = 0; i < tamf; i++)
{
for (int j = 0; j < tamc; j++)
{
t[i][j] = 1 + rand() % 5;
}
}

j[pod].partidas[j[pod].tamp].nivel=4;
cout<<"acumulado nivelanterior "<< j[pod].partidas[j[pod].tamp].puntaje;
j[pod].tamp=j[pod].tamp+1;
j[pod].partidas[j[pod].tamp].tiempo=0;
j[pod].partidas[j[pod].tamp].puntaje=0;
cout<<"acumulado nivel siguiente "<< j[pod].partidas[j[pod].tamp].puntaje;

jugar( t, tamf, tamc ,j,tam ,pod);
}
//------------------------------------------------------------------------------------------------
void jugar(int t[][60],int tamf,int tamc ,jugador j[],int tam ,int p){
int aux,posc=0, posf=0,pod=-1;
string nom;
double dif;
bool verificar=false;
char re='n', miraar;
time_t start,end;//declara las variables del tiempo
cout<<endl;

cout<<"//JUEGO//"<<endl;

time (&start); //hora inicial

//----------------WHILE DEL JUEGO-----------------
while (posc!=-1 || posf!=-1)  //juegoooooooooo
{
for (int i=0; i<tamf; i++)
 {
  for (int j=0; j<tamc; j++)
  {
    cout<<" "<<t[i][j]<<" ";//muestra la matriz
  }
  cout<<endl;
 }
//-----------------POSICION---------------------

cout<<"ingrese la posicion de la fila: ";
cin>>posf;
if (posf==-1)
{

}
while(posf<1||posf>tamf+1||posf==-1)//esto verifica si la persona colo -1 o otra posicion
{
if(posf==-1){

time (&end);
double  dif = difftime (end,start);

j[p].partidas[j[p].tamp-1].tiempo+=dif;
menuprincipal( t, tamf, tamc, j,tam,p);//enviarlo al menu
}
  cout<<endl;
  cout<<"vuelva a ingresar la fila (max"<<tamf<< " y min1)"<<endl;
  cin>>posf;
}
posf=posf-1;//pocision del indice porque la persona no identifica el indice

cout<<endl;
cout<<"ingrese la posicion de la columna: ";
cin>>posc;


while((posc<1||posc>tamc+1)||posc==-1)
{if(posc==-1){


time (&end);
 double dif = difftime (end,start);
j[p].partidas[j[p].tamp-1].tiempo+=dif;
menuprincipal( t, tamf, tamc, j,tam,p);

}
  cout<<endl;
  cout<<"vuelva a ingresar la columna (max"<<tamc<< " y min1)"<<endl;
  cin>>posc;
}
   //si ponen una posicion incorrecta

posc=posc-1;
aux= t[posf][posc]; //auxiliar de esa posicion
//la posicion sera 0

//----------------MIRAR SI SE ELIMINAN PARTES-----------------
    miraar='n';
 for (int i=posf+1; i<tamf && aux!=0; i++)
 {
  if (t[i][posc]==aux)//mira hacia abajo si las posiciones son igualal auxiliar para convertirlo en 0
   {
     t[i][posc]=0;
     t[posf][posc]=0;
     miraar='i';
     j[p].partidas[j[p].tamp-1].puntaje  +=10;//acumula 10 en 10

   }
  else
    i=tamf;//si no es igual va al else i=tamf y se sale del for
 }

 for (int i=posf-1; i>=0 && aux!=0; i--)//revisa hacia arriba
 {
  if (t[i][posc]==aux)
   {
     t[i][posc]=0;
     j[p].partidas[j[p].tamp-1].puntaje +=10;
     miraar='i';
     t[posf][posc]=0;

   }
  else
    i=-1;
 }
  for (int i=posc+1; i<tamc && aux!=0; i++)//revisa hacia la derecha
 {
  if (t[posf][i]==aux)
   {
     t[posf][i]=0;
     t[posf][posc]=0;
     miraar='i';
     j[p].partidas[j[p].tamp-1].puntaje+=10;

   }
  else
    i=tamf;
 }

 for (int i=posc-1; i>=0 && aux!=0; i--)//revisa hacia la izquierda
 {
  if (t[posf][i]==aux)
   {
     t[posf][i]=0;
     t[posf][posc]=0;
     miraar='i';
     j[p].partidas[j[p].tamp-1].puntaje+=10;

   }
  else
    i=-1;
 }
 if (miraar=='i')
 {
     j[p].partidas[j[p].tamp-1].puntaje+=10;
 }
//------------------ACTUALIZAR MATRIZ (BAJAR NUMEROS)------------------

   for (int i=1; i<tamf; i++)  //revisa filas y columnas si tienen un cero
 {
  for (int j=0; j<tamc; j++)
  {
    if(t[i][j]==0) //revisa filas y columnas si tienen un cero
     {
       for (int q=i; q>0; q--)
       {
         t[q][j]=t[q-1][j];//la fila de abajo obtendra la fila de arriba
       }
        t[0][j]=0;//la fila 0 sera 0 siempre y cuando haya columnas con 0
     }
  }

 }
//----------------MOSTRAR MATRIZ------------------
for (int i=0; i<tamf; i++)
 {
  for (int j=0; j<tamc; j++)
  {
    cout<<" "<<t[i][j]<<" ";
  }
  cout<<endl;
 }
cout<<endl;
verificar= seguir(t,tamf,tamc);

if (verificar==true)
{
  break;
}
system("pause");
system("cls");
cout<<endl;
 //---------------------------------------

}
system("pause");
system("cls");

cout<<endl;
time (&end);//hora final




if(verificar==true){
j[p].partidas[j[p].tamp].win+=1;
cout<<R"(
??+    ??+??+???+   ??+???+   ??+???????+??????+ ??+
???    ??????????+  ???????+  ?????+----+??+--??+???
??? ?+ ????????+??+ ?????+??+ ????????+  ??????++???
??????+?????????+??+??????+??+?????+--+  ??+--??++-+
+???+???++?????? +???????? +????????????+???  ?????+
 +--++--+ +-++-+  +---++-+  +---++------++-+  +-++-+

           )";

}

dif = difftime (end,start);//se resta la hora final con la inicial y ese es el tiempo
j[p].partidas[j[p].tamp-1].tiempo+=dif;
cout<<"tiempo final "<<j[p].partidas[j[p].tamp-1].tiempo<<endl;

cout<<"El puntaje es: "<<j[p].partidas[j[p].tamp-1].puntaje<<endl;

}
//return j[p].partidas;

int seguir(int t[][60],int tamf,int tamc ){
bool verificar=true;
for (int i=0; i<tamf; i++)
 {
  for (int j=0; j<tamc; j++)
  {

  if (t[i][j]!=0 && t[i][j]==t[i+1][j])
     {
     verificar = false;
     }
    if (t[i][j]!=0 && t[i][j]==t[i-1][j])
     {
     verificar = false;
     }
    if (t[i][j]!=0 && t[i][j]==t[i][j-1])
     {
     verificar = false;
     }
    if (t[i][j]!=0 && t[i][j]==t[i][j+1])
     {
     verificar = false;
     }
  if (verificar==false)
  break;
  }
  if (verificar==false)
  break;
  cout<<endl;
 }
 return verificar;
}

void Estadisticas(jugador j[],int tam, int op1, int op2)
{
int sep, sep2;
string nombresest[200], auxn, escoger, aliasest;
string apellidossest[200], auxa;
int puntajeest[200], auxp, tot1=0,gan1=0;
double tiempoest[200], auxt;

        cout <<"Los mejores puntajes y tiempos son: "<<endl;
    sep=0;
    for ( int i =0;i<tam;i++){
        for(int m=0; m<j[i].tamp ; j++){
            if(j[i].partidas[m].nivel>=1)
                {
                nombresest[sep]=j[i].nombre;
                puntajeest[sep]=j[i].partidas[m].puntaje;
                tiempoest[sep]=j[i].partidas[m].tiempo;
                sep+=1;

                }
            }
        }

//-------------------ORDEN POR PUNTAJE-----------------
cout<<endl;
if (op1==1)
{

    {
    for ( int i =0;i<sep;i++){
        for(int x=i;x<sep;x++)
        {
            if(puntajeest[i]>puntajeest[x]){
                auxp=puntajeest[i];
                auxn=nombresest[i];
                auxt=tiempoest[i];
                puntajeest[i]=puntajeest[x];
                nombresest[i]=nombresest[x];
                tiempoest[i]=tiempoest[x];
                puntajeest[x]=auxp;
                tiempoest[x]=auxt;
                nombresest[x]=auxn;

            }
        }
    }

}
for (int q=0; q<sep&& q<5; q++)
{
cout<<"PUNTAJE: "<<puntajeest[q]<<"        "<<"NOMBRE: "<<nombresest[q]<<"         "<<"TIEMPO: "<<tiempoest[q]<<endl;

}
}
//----------------ORDEN POR TIEMPO---------------
if (op1==2)
{

    {
    for ( int i =0;i<sep;i++){
        for(int x=i;x<sep;x++)
        {
            if(tiempoest[i]>tiempoest[x]){
                auxp=puntajeest[i];
                auxn=nombresest[i];
                auxt=tiempoest[i];
                puntajeest[i]=puntajeest[x];
                nombresest[i]=nombresest[x];
                tiempoest[i]=tiempoest[x];
                puntajeest[x]=auxp;
                tiempoest[x]=auxt;
                nombresest[x]=auxn;
            }
        }
    }

}
for (int q=0; q<sep&& q<5; q++)
{
cout<<"PUNTAJE: "<<puntajeest[q]<<"        "<<"NOMBRE: "<<nombresest[q]<<"         "<<"TIEMPO: "<<tiempoest[q]<<endl;

}
}
//--------------
       cout <<"Estadisticas por jugador "<<endl;
int verificaaar;
string r;
cout<<"Desea ver un jugador en particular? Presione 's' para si y cualquier otra tecla para no. "<<endl;
cin>>escoger;

if (escoger=="s"|| escoger=="S")
{
    verificaaar = -1;
    r = "s";
    while ((verificaaar == -1) && (r == "s" || r == "S"))
    {
    cout<<"Ingrese el alias del jugador: ";
    cin>> aliasest;

    for (int i = 0; i < tam; i++)
    {
        cout<<"1";
        if (aliasest == j[i].alias)
        cout<<"2";
        {
            verificaaar = 1;
            i = tam + 1;//para salirse del for
            for (int m=0; m<4; m++)//m  son los niveles
            {
             tot1=0;
             gan1=0;
            for (int u=0; u<j[i].tamp; u++)
            {
                if (j[i].partidas[u].nivel==m+1)
                {
                    tot1+=1;//cantidad de nivel faci en el arreglo partidas
                    gan1+=j[i].partidas[u].win;//acumular las veces que gao en el nivel facil


                }
            }
            if (tot1!=0)
            cout <<"nivel "<< m <<":   "<< aliasest <<"   "<<tot1<<"    "<<gan1<<"    "<<(gan1/tot1)*100<<"%"<<endl;
            else
                cout<<"no se ha jugado en el nivel "<<m+1<<endl;
            }
        }
        if (verificaaar==1)
            break;
    }

    if (verificaaar == -1)
    {
        cout << "error el alias no existe " << endl;
        cout << "desea escoger el alias de otro usuario ?(s/n) " << endl;
        cin >> r;
        cout<<endl;
        system("pause");
        system("cls");
    }

    }


}
 else
 {
//----------------------Por apellidos-----------------
if(op2==1)
{


    sep=0;
    for ( int i =0;i<tam;i++){
        for(int m=0; m<j[i].tamp ; j++){
            if(j[i].partidas[m].nivel>=1)
                {
                apellidossest[sep]=j[i].apellido;
                sep+=1;
                m=j[i].tamp+2;
                }
            }
        }

    for ( int i =0;i<sep;i++){
        for(int x=i;x<sep;x++)
        {
            if(apellidossest[i]>apellidossest[x]){
                auxa=apellidossest[i];
                apellidossest[i]=apellidossest[x];
                apellidossest[x]=auxa;
            }
        }
    }
for (int f=0; f<sep; f++)
{
        for (int i = 0; i < tam; i++)
    {
        if (apellidossest[f] == j[i].alias)
        {
            verificaaar = i;//guarda el indice de la persona que se va a ver
            i = tam + 1;//para salirse del for
            for (int m=0; m<4; m++)//m  son los niveles
            {
             tot1=0;
             gan1=0;
            for (int u=0; u<j[i].tamp; u++)
                {
                if (j[i].partidas[u].nivel==m+1)
                    {
                    tot1+=1;//cantidad de nivel faci en el arreglo partidas
                    gan1+=j[i].partidas[u].win;//acumular las veces que gao en el nivel facil

                    }
                }

            }
        }
    }
}

//Por total de juego
if (op2==2)
{

}

 //------------------------------

}
 }
}


