#include <stdio.h>
#include <string.h>
#include "archivos.h"

int buscarPersona(char cedula[]) {
    struct Persona p;
    FILE *arch = fopen("personas.txt", "r");

    if (arch == NULL) return 0;

    while (fscanf(arch, "%19[^|]|%59[^|]|%d|%19[^\n]\n",
                  p.cedula, p.nombre, &p.municipio, p.telefono) == 4) {
        if (strcmp(p.cedula, cedula) == 0) {
            fclose(arch);
            return 1;
        }
    }

    fclose(arch);
    return 0;
}

int buscarEmpresa(char nit[]) {
    struct Empresa e;
    FILE *arch = fopen("empresas.txt", "r");

    if (arch == NULL) return 0;

    while (fscanf(arch, "%19[^|]|%59[^|]|%39[^|]|%d\n",
                  e.nit, e.nombre, e.sector, &e.municipio) == 4) {
        if (strcmp(e.nit, nit) == 0) {
            fclose(arch);
            return 1;
        }
    }

    fclose(arch);
    return 0;
}

int existeMunicipio(int codigo) {
    struct Municipio m;
    FILE *arch = fopen("municipios.txt", "r");

    if (arch == NULL) return 0;

    while (fscanf(arch, "%d|%39[^|]|%d\n",
                  &m.codigo, m.nombre, &m.departamento) == 3) {
        if (m.codigo == codigo) {
            fclose(arch);
            return 1;
        }
    }

    fclose(arch);
    return 0;
}

void guardarPersona(struct Persona p) {
    FILE *arch = fopen("personas.txt", "a");

    if (arch == NULL) {
        printf("\nError al abrir personas.txt\n");
        return;
    }

    fprintf(arch, "%s|%s|%d|%s\n",
            p.cedula, p.nombre, p.municipio, p.telefono);
    fclose(arch);
    printf("\nPersona registrada correctamente.\n");
}

void listarPersonas(void) {
    struct Persona p;
    FILE *arch = fopen("personas.txt", "r");

    if (arch == NULL) {
        printf("\nTodavia no hay personas registradas.\n");
        return;
    }

    printf("\nCEDULA             NOMBRE                         MUNICIPIO  TELEFONO\n");
    printf("--------------------------------------------------------------------------\n");

    while (fscanf(arch, "%19[^|]|%59[^|]|%d|%19[^\n]\n",
                  p.cedula, p.nombre, &p.municipio, p.telefono) == 4) {
        printf("%-18s %-30s %-10d %s\n",
               p.cedula, p.nombre, p.municipio, p.telefono);
    }

    fclose(arch);
}

void guardarEmpresa(struct Empresa e) {
    FILE *arch = fopen("empresas.txt", "a");

    if (arch == NULL) {
        printf("\nError al abrir empresas.txt\n");
        return;
    }

    fprintf(arch, "%s|%s|%s|%d\n",
            e.nit, e.nombre, e.sector, e.municipio);
    fclose(arch);
    printf("\nEmpresa registrada correctamente.\n");
}

void listarEmpresas(void) {
    struct Empresa e;
    FILE *arch = fopen("empresas.txt", "r");

    if (arch == NULL) {
        printf("\nTodavia no hay empresas registradas.\n");
        return;
    }

    printf("\nNIT                RAZON SOCIAL                   SECTOR                   MUNICIPIO\n");
    printf("--------------------------------------------------------------------------------------\n");

    while (fscanf(arch, "%19[^|]|%59[^|]|%39[^|]|%d\n",
                  e.nit, e.nombre, e.sector, &e.municipio) == 4) {
        printf("%-18s %-30s %-24s %d\n",
               e.nit, e.nombre, e.sector, e.municipio);
    }

    fclose(arch);
}
