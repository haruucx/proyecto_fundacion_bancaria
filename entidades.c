#include <stdio.h>
#include <stdlib.h>
#include "entidades.h"
#include "funciones.h"
#include "archivos.h"

int posicionEntidad(struct Entidad v[], int n, char nit[]) {
    int i;

    for (i = 0; i < n; i++) {
        if (iguales(v[i].nit, nit)) {
            return i;
        }
    }

    return -1;
}

void mostrarEntidad(struct Entidad e) {
    printf("\nNIT: %s\n", e.nit);
    printf("Nombre: %s\n", e.nombre);
    printf("Municipio: %s\n", e.municipio);
    printf("Tipo de ayuda: %s\n", e.tipoAyuda);
    printf("Representante: %s\n", e.representante);
}

void registrarEntidad(struct Entidad v[], int n) {
    struct Entidad e;

    if (n == MAX) {
        printf("No hay espacio para mas entidades.\n");
        return;
    }

    leerNumero("Ingrese el NIT: ", e.nit, 20);

    if (posicionEntidad(v, n, e.nit) != -1) {
        printf("El NIT ya esta registrado.\n");
        return;
    }

    leer("Ingrese el nombre de la entidad: ", e.nombre, 60);

    if (leerMunicipio(e.municipio) == 0) {
        return;
    }

    leer("Ingrese el tipo de ayuda: ", e.tipoAyuda, 50);
    leerNombre("Ingrese el representante: ", e.representante, 60);
    agregarEntidad(e);
}

void consultarEntidad(struct Entidad v[], int n) {
    char nit[20];
    int pos;

    leerNumero("Ingrese el NIT: ", nit, 20);
    pos = posicionEntidad(v, n, nit);

    if (pos == -1) {
        printf("Entidad no encontrada.\n");
    } else {
        mostrarEntidad(v[pos]);
    }
}

void modificarEntidad(struct Entidad v[], int n) {
    char nit[20];
    int pos, op;

    leerNumero("Ingrese el NIT: ", nit, 20);
    pos = posicionEntidad(v, n, nit);

    if (pos == -1) {
        printf("Entidad no encontrada.\n");
        return;
    }

    mostrarEntidad(v[pos]);
    printf("\n1. Nombre\n2. Municipio\n3. Tipo de ayuda\n4. Representante\n0. Cancelar\n");
    op = leerOpcion();

    switch (op) {
        case 1:
            leer("Ingrese el nombre de la entidad: ", v[pos].nombre, 60);
            guardarEntidades(v, n);
            break;
        case 2:
            if (leerMunicipio(v[pos].municipio)) {
                guardarEntidades(v, n);
            }
            break;
        case 3:
            leer("Ingrese el tipo de ayuda: ", v[pos].tipoAyuda, 50);
            guardarEntidades(v, n);
            break;
        case 4:
            leerNombre("Ingrese el representante: ", v[pos].representante, 60);
            guardarEntidades(v, n);
            break;
        case 0:
            break;
        default:
            printf("Opcion no valida.\n");
    }
}

void listarEntidades(struct Entidad v[], int n) {
    int i;

    if (n == 0) {
        printf("No hay entidades registradas.\n");
    }

    for (i = 0; i < n; i++) {
        mostrarEntidad(v[i]);
    }
}

void menuEntidades() {
    struct Entidad v[MAX];
    int op, n;

    do {
        system("cls");
        printf("1. Registrar\n2. Consultar\n3. Modificar\n4. Listar\n0. Regresar\n");
        op = leerOpcion();

        if (op != 0) {
            n = cargarEntidades(v);

            if (n == -1) {
                printf("Error en entidades.txt\n");
            } else {
                switch (op) {
                    case 1:
                        registrarEntidad(v, n);
                        break;
                    case 2:
                        consultarEntidad(v, n);
                        break;
                    case 3:
                        modificarEntidad(v, n);
                        break;
                    case 4:
                        listarEntidades(v, n);
                        break;
                    default:
                        printf("Opcion no valida.\n");
                }
            }

            system("pause");
        }
    } while (op != 0);
}
