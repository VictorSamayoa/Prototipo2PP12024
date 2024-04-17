#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>
#include"menuP.h"
#include"catalogo.h"

using namespace std;

class verifiacionU
{
    public:
        bool ingreso ();

    private:
        string nombre, contrasena;
};

bool verifiacionU::ingreso()
{


    system("cls");
    int contador = 0;
    string nombre, contrasena;
    bool encontrado= false;
    while (contador < 3 && ! encontrado)
    {




     cout<<"+-----------------------------------------------+"<<endl;
     cout<<"|               Entrando al sistema             |"<<endl;
     cout<<"+-----------------------------------------------+"<<endl;
     cout<<"|        Solo tienes permitido 3 intentos       |"<<endl;
     cout<<"+-----------------------------------------------+"<<endl;
     cout<<" Ingrese el nombre del usuario: ";
     cin >> nombre;
     cout<<" Ingrese el contraseña del usuario: ";
     char cifrado;
     cifrado = getch();

     contrasena="";
     while (cifrado !=13)
     {
        if (cifrado !=8)
            {

            contrasena.push_back(cifrado);
            cout<<".";

     }
    else
    {
        if (contrasena.length ()>0)
        {
            cout<<"\b \b";
            contrasena=contrasena.substr(0,contrasena.length ()-1);
        }
    }
    cifrado=getch();
}
    ifstream archivo;
    archivo.open("Usuarios.txt", ios::in);

    if (!archivo)
        {
    cout<<"No es posible abrir el archivo." << endl;
    archivo.close();
    return false;
    }
    string persona, contra;
    while (archivo>>persona>>contra)
    {
        if(persona == nombre && contra == contrasena)
        {
        encontrado = true;
        break;
        }
    }
    archivo.close();

    if (!encontrado)
    {
        cout << "\n\tEl Usuario o la contraseña son incorectos" << endl;
        cout << "\n\tIntente de nuevo" << endl;
        contador++;
        system("pause");
    }

}
    if (encontrado)
    {
        int opcion;
        menuP menuprincipal;

        do{
            system("cls");

            cout << "+-----------------------------------------------+" << endl;
            cout << "|                  Menu Principal               |" << endl;
            cout << "|                                               |" << endl;
            cout << "| Nombre:Victor Josue Samayoa Ortiz             |" << endl;
            cout << "| Carnet:9959-23-3424                           |" << endl;
            cout << "|                                               |" << endl;
            cout << "+-----------------------------------------------+" << endl;
            cout << "| 1. Menu de usuarios                           |" << endl;
            cout << "| 2. Menu del catalogo                          |" << endl;
            cout << "| 3. Menu del informes                          |" << endl;
            cout << "| 4. Salir                                      |" << endl;
            cout << "+-----------------------------------------------+" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                system("cls");
                menuprincipal.menuUsuarios();
                break;
            case 2:

                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                system("pause");
                break;
            }
        } while (opcion != 3);

        return true;
    }

    else
    {
     cout << "\n\tPERDIO LOS 3 INTENTOS" << endl;
    cout << "\n\tNO PODRA INGRESAR MAS INTENTOS" << endl;
    return false;
    }

}




