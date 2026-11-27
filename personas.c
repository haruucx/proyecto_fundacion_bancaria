#include <stdio.h>
#include <stdlib.h>
#include "personas.h"
#include "funciones.h"
#include "archivos.h"

int posicionPersona(struct Persona v[], int n, char cedula[]) {
    int i;

    for (i = 0; i < n; i++) {
        if (iguales(v[i].cedula, cedula)) {
            return i;
        }
    }

    return -1;
}

void mostrarPersona(struct Persona p) {
    printf("\nCedula: %s\n", p.cedula);
    printf("Nombre: %s\n", p.nombre);
    printf("Municipio: %s\n", p.municipio);
    printf("Telefono: %s\n", p.telefono);
}

void registrarPersona(struct Persona v[], int n) {
    struct Persona p;

    if (n == MAX) {
        printf("No hay espacio para mas personas.\n");
        return;
    }

    leerNumero("Ingrese la cedula: ", p.cedula, 20);

    if (posicionPersona(v, n, p.cedula) != -1) {
        printf("La cedula ya esta registrada.\n");
        return;
    }

    leerNombre("Ingrese el nombre completo: ", p.nombre, 60);

    if (leerMunicipio(p.municipio) == 0) {
        return;
    }

    leerNumero("Ingrese el telefono: ", p.telefono, 20);
    agregarPersona(p);
}

void consultarPersona(struct Persona v[], int n) {
    char cedula[20];
    int pos;

    leerNumero("Ingrese la cedula: ", cedula, 20);
    pos = posicionPersona(v, n, cedula);

    if (pos == -1) {
        printf("Persona no encontrada.\n");
    } else {
        mostrarPersona(v[pos]);
    }
}

void modificarPersona(struct Persona v[], int n) {
    char cedula[20];
    int pos, op;

    leerNumero("Ingrese la cedula: ", cedula, 20);
    pos = posicionPersona(v, n, cedula);

    if (pos == -1) {
        printf("Persona no encontrada.\n");
        return;
    }

    mostrarPersona(v[pos]);
    printf("\n1. Nombre\n2. Municipio\n3. Telefono\n0. Cancelar\n");
    op = leerOpcion();

    switch (op) {
        case 1:
            leerNombre("Ingrese el nombre completo: ", v[pos].nombre, 60);
            guardarPersonas(v, n);
            break;
        case 2:
            if (leerMunicipio(v[pos].municipio)) {
                guardarPersonas(v, n);
            }
            break;
        case 3:
            leerNumero("Ingrese el telefono: ", v[pos].telefono, 20);
            guardarPersonas(v, n);
            break;
        case 0:
            break;
        default:
            printf("Opcion no valida.\n");
    }
}

void listarPersonas(struct Persona v[], int n) {
    int i;

    if (n == 0) {
        printf("No hay personas registradas.\n");
    }

    for (i = 0; i < n; i++) {
        mostrarPersona(v[i]);
    }
}

void menuPersonas() {
    struct Persona v[MAX];
    int op, n;

    do {
        system("cls");
        printf("1. Registrar\n2. Consultar\n3. Modificar\n4. Listar\n0. Regresar\n");
        op = leerOpcion();

        if (op != 0) {
            n = cargarPersonas(v);

            if (n == -1) {
                printf("Error en personas.txt\n");
            } else {
                switch (op) {
                    case 1:
                        registrarPersona(v, n);
                        break;
                    case 2:
                        consultarPersona(v, n);
                        break;
                    case 3:
                        modificarPersona(v, n);
                        break;
                    case 4:
                        listarPersonas(v, n);
                        break;
                    default:
                        printf("Opcion no valida.\n");
                }
            }

            system("pause");
        }
    } while (op != 0);
}
