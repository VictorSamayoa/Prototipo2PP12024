#ifndef MENUP_H
#define MENUP_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


using namespace std;

class menuP
{
    public:
    void menuUsuarios();
    void insertar();


    private:
    string nombre, contrasena;
};

#endif // MENUP_H
