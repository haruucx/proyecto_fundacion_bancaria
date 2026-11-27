#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#define MAX 100

struct Persona {
    char cedula[20];
    char nombre[60];
    char municipio[10];
    char telefono[20];
};

struct Entidad {
    char nit[20];
    char nombre[60];
    char municipio[10];
    char tipoAyuda[50];
    char representante[60];
};

#endif
