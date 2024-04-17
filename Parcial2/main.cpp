#include <iostream>
#include <cstdlib>
#include "verifiacionU.h"


//usuario: simon
//contraseña: manita



using namespace std;

int main()
{

    int opcion;
    verifiacionU verificacion;
    do{
        system("cls");


        cout << "+-----------------------------------------------+" << endl;
        cout << "|               Sistemas de usuarios            |" << endl;
        cout << "|            Entro como administador            |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "|            1. ingreso al sistema              |" << endl;
        cout << "|            2. salida                          |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "|         Ingrese su opcion [1/2]               |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cin >> opcion;

        switch(opcion){
            case 1:
                system("cls");
                verificacion.ingreso();
                break;
            case 2:
                 exit(0);
                break;
            default:
                cout << "opcion invalida. "<< endl;
                break;
        }
    }while (opcion != 2);


    return 0;
}

