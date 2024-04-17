#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;

class menuP
{
    public:
    void menuUsuarios();
    void insertar();


    private:
    string nombre, contrasena;
};
void menuP::menuUsuarios()

{

int opcion = 0;
char continuar;

do {
    system("cls");


    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|  BIENVENIDO AL SISTEMA DE GESTION DE ALUMNOS  |"<<endl;
    cout<<"+-----------------------------------------------+"<<endl;
    cout<<"|              1. Agregar Usuario               |"<<endl;
    cout<<"|              2. salida                        |" << endl;
    cout<<"+-----------------------------------------------+" << endl;
    cout<<"|         Ingrese su opcion [1/2]               |" << endl;
    cout<<"+-----------------------------------------------+" << endl;
    cin >> opcion;
    switch(opcion)
    {
    case 1:
        do
        {
            insertar();
           cout<<" -> ¿Deseas ingresar a otro estudiante? (S/N): ";
            cin>>continuar;
            cout << endl;
        }while(continuar=='S' || continuar=='s');
        break;
    case 2:
        break;
    default:
        cout <<"ERROR, OPCION NO VALIDA, INTENTELO DE NUEVO PORFAVOR";
    }
    getch();
}while (opcion != 2);
}
void menuP::insertar()
{
    system("cls");
    fstream archivo;

    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|                Datos de ingreso de nuevo usuario        |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;


    cout << " Ingrese el nombre del usuario:  ";
    cin >> nombre;


    cout << " Ingrese la contrasena:  ";
    cin >> contrasena;



    archivo.open("Usuarios.txt", ios::app | ios::out);
    archivo<<left<<setw(15)<<nombre<<left<<setw(15)<<contrasena<<"\n";
    archivo.close();

}


