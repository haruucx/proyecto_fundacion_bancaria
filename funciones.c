
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "archivos.h"

int soloNumeros(char texto[]) {

    int i;

    if (texto[0] == '\0') {
        return 0;
    }

    for (i = 0; texto[i] != '\0'; i++) {
        if (!isdigit((unsigned char)texto[i])) {
            return 0;
        }
    }

    return 1;
}

void registrarPersona() {

    struct Persona p;

    printf("\nREGISTRO DE PERSONA\n");

    printf("Cedula: ");
    scanf("%19s", p.cedula);

    if (!soloNumeros(p.cedula)) {
        printf("\nCedula invalida\n");
        pausa();
        return;
    }

    if (buscarPersona(p.cedula)) {
        printf("\nERROR: La cedula ya existe\n");
        pausa();
        return;
    }

    printf("Nombre completo: ");
    scanf(" %59[^\n]", p.nombre);

    printf("Codigo del municipio: ");

    if (scanf("%d", &p.municipio) != 1 || p.municipio <= 0) {
        limpiar();
        printf("\nMunicipio invalido\n");
        pausa();
        return;
    }

    printf("Telefono: ");
    scanf("%19s", p.telefono);

    if (!soloNumeros(p.telefono)) {
        limpiar();
        printf("\nTelefono invalido\n");
        pausa();
        return;
    }

    limpiar();

    guardarPersona(p);

    pausa();
}
