#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>
#include"verifiacionU.h"
using namespace std;



class catalogo
{
   private:
    string nombre, contrasena;;
    public:
        void menuC();
        void insertar();
        void modificar();
        void desplegar();
        void borrar();
};



void catalogo::menuC()
{
    int opcion;
	char continuar;
	do
    {
		system("cls");

		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|  BIENVENIDO AL SISTEMA DE GESTION DE ALUMNOS  |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|            1. Dar de alta                     |"<<endl;
		cout<<"|            2. Mostrar                         |"<<endl;
		cout<<"|            3. Modificar                       |"<<endl;
		cout<<"|            4. Dar de baja                     |"<<endl;
		cout<<"|            5. Salir del programa              |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|         Ingrese su opcion [1/2/3/4/5/6]       |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cin>>opcion;

		switch(opcion)
		{
			case 1:
				do
				{
                desplegar();
				break;
			case 2:
				modificar();
				break;
			case 3:
				exit(0);
			default:
				cout<<"ERROR, OPCION NO VALIDA, INTENTELO DE NUEVO PORFAVOR";
		}
		getch();
    }while(opcion != 3);
}

void catalogo::desplegar()
{
	system("cls");
	fstream archivo;
	int total=0;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                            Tabla de Detalles del Estudiante                     +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	archivo.open("Usuarios.txt",ios::in);
	if(!archivo)
	{
		cout<<"Error, no se encuentra informacion...";
		archivo.close();
	}
	else
	{
		archivo >> nombre;
		while(!archivo.eof())
		{
			total++;

    cout<<"                        Mostrando -> Nombre del estudiante: "  << nombre << endl;


			archivo >> nombre;
		}
		if(total==0)
		{
			cout<<"Error, no se encuentra informacion...";
		}
	}
	archivo.close();
}

void catalogo::modificar()
{
	system("cls");
	fstream archivo, archivoTemporal;
	string modificarpersona;
	int encontrado=0;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                       Modificar Detalles del la persona                         +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;

	archivo.open("Usuarios.txt",ios::in);
	if(!archivo)
	{
		cout<<"Error, no se encuentra informacion...";
		archivo.close();
	}
	else
	{
		cout<<"la persona que desea modificar: ";
		cin>>nombre;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
		archivoTemporal.open("Temporal.txt",ios::app | ios::out);
		archivo >> nombre ;
		while(!archivo.eof())
		{
			if(modificarpersona != nombre)
			{
				archivoTemporal<<left<<setw(15)<<nombre<<"\n";
			}
			else
			{

				cout<<" -> Ingrese el nuevo nombre del estudiante: ";
				cin>>nombre;

    cout<<"+---------------------------------------------------------------------------------+"<<endl;

				archivoTemporal<<left<<setw(15)<<nombre<<"\n";
				encontrado++;
			}
			archivo >> nombre;

		}
		archivoTemporal.close();
		archivo.close();
		remove("Usuarios.txt");
		rename("Temporal.txt","Usuarios.txt");
	}
}
