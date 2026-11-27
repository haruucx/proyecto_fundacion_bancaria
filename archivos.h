#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "estructuras.h"

int buscarPersona(char cedula[]);
int buscarEmpresa(char nit[]);
int existeMunicipio(int codigo);

void guardarPersona(struct Persona p);
void listarPersonas(void);

void guardarEmpresa(struct Empresa e);
void listarEmpresas(void);

#endif
