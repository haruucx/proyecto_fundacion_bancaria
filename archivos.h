#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <stdio.h>
#include "estructuras.h"

int leerCampo(FILE *archivo, char destino[], int tam);
int existeMunicipio(char codigo[]);
void mostrarMunicipios();
int leerMunicipio(char destino[]);

int cargarPersonas(struct Persona v[]);
void agregarPersona(struct Persona p);
void guardarPersonas(struct Persona v[], int n);

int cargarEntidades(struct Entidad v[]);
void agregarEntidad(struct Entidad e);
void guardarEntidades(struct Entidad v[], int n);

#endif
