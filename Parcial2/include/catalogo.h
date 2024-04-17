#ifndef CATALOGO_H
#define CATALOGO_H


class catalogo
{
   private:
    string nombre, contrasena;
    public:
        void menuC();
        void insertar();
        void modificar();
        void buscar();
        void borrar();
};

#endif // CATALOGO_H
