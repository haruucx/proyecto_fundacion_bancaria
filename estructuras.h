#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct Persona {
    char cedula[20];
    char nombre[60];
    int municipio;
    char telefono[20];
};

struct Empresa {
    char nit[20];
    char nombre[60];
    char sector[40];
    int municipio;
};

struct Departamento {
    int codigo;
    char nombre[40];
};

struct Municipio {
    int codigo;
    char nombre[40];
    int departamento;
};

struct Entidad {
    char nit[20];
    char nombre[60];
    int municipio;
    char tipoAyuda[50];
    char representante[60];
};

struct Donacion {
    char codigo[15];
    char fecha[11];
    char tipo;
    char idDonante[20];
    long long valor;
    char concepto[100];
};

struct Entrega {
    char codigo[15];
    char fecha[11];
    char nitEntidad[20];
    long long valor;
    char concepto[100];
};

struct Usuario {
    char usuario[30];
    char clave[30];
    int tipo;
};

#endif