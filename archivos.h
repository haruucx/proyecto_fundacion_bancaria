#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "estructuras.h"

int buscarPersona(char cedula[]);
void guardarPersona(struct Persona p);

void guardarPersona(struct Persona p);
void listarPersonas();

void guardarEmpresa(struct Empresa e);
void listarEmpresas();

void guardarDepartamento(struct Departamento d);
void listarDepartamentos();

void guardarMunicipio(struct Municipio m);
void listarMunicipios();

void guardarEntidad(struct Entidad e);
void listarEntidades();

void guardarDonacion(struct Donacion d);
void listarDonaciones();

void guardarEntrega(struct Entrega e);
void listarEntregas();

void guardarUsuario(struct Usuario u);
void listarUsuarios();

#endif
