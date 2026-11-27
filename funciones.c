#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "personas.h"
#include "entidades.h"

void leer(char mensaje[], char destino[], int tam) {
    char texto[200];
    int valido = 0;
    int i, largo, c;

    do {
        printf("%s", mensaje);
        if (scanf(" %199[^\n]", texto) != 1) {
            exit(0);
        }

        largo = strlen(texto);
        c = getchar();

        if (c != '\n' && c != EOF) {
            largo = 200;
            while (c != '\n' && c != EOF) {
                c = getchar();
            }
        }

        if (largo >= tam) {
            printf("El texto es demasiado largo.\n");
        } else {
            for (i = 0; i <= largo; i++) {
                destino[i] = texto[i];
            }
            valido = 1;
        }
    } while (valido == 0);
}

int iguales(char a[], char b[]) {
    int i = 0;

    while (a[i] != '\0' && a[i] == b[i]) {
        i++;
    }

    if (a[i] == b[i]) {
        return 1;
    }

    return 0;
}

int soloNumeros(char texto[]) {
    int i;

    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] < '0' || texto[i] > '9') {
            return 0;
        }
    }

    if (i == 0) {
        return 0;
    }

    return 1;
}

int soloLetras(char texto[]) {
    int i;
    int letras = 0;

    for (i = 0; texto[i] != '\0'; i++) {
        if ((texto[i] >= 'a' && texto[i] <= 'z') ||
            (texto[i] >= 'A' && texto[i] <= 'Z')) {
            letras++;
        } else if (texto[i] != ' ') {
            return 0;
        }
    }

    if (letras == 0) {
        return 0;
    }

    return 1;
}

int leerOpcion() {
    char texto[200];

    leer("Ingrese una opcion: ", texto, 200);

    if (soloNumeros(texto) && strlen(texto) == 1) {
        return texto[0] - '0';
    }

    return -1;
}

void leerNumero(char mensaje[], char destino[], int tam) {
    int valido;

    do {
        leer(mensaje, destino, tam);
        valido = soloNumeros(destino);
        if (valido == 0) {
            printf("Ingrese solamente numeros.\n");
        }
    } while (valido == 0);
}

void leerNombre(char mensaje[], char destino[], int tam) {
    int valido;

    do {
        leer(mensaje, destino, tam);
        valido = soloLetras(destino);
        if (valido == 0) {
            printf("Ingrese solamente letras y espacios.\n");
        }
    } while (valido == 0);
}

void menuPrincipal() {
    int op;

    do {
        system("cls");

        printf("\n");
        printf("============================================\n");
        printf("       FUNDACION COLOMBIA SOLIDARIA\n");
        printf("============================================\n");
        printf("\n");
        printf("              MENU PRINCIPAL\n");
        printf("--------------------------------------------\n");
        printf("  1. Gestion de personas\n");
        printf("  2. Gestion de entidades beneficiarias\n");
        printf("  0. Salir del programa\n");
        printf("--------------------------------------------\n");

        op = leerOpcion();

        switch (op) {
            case 1:
                menuPersonas();
                break;

            case 2:
                menuEntidades();
                break;

            case 0:
                printf("\n");
                printf("============================================\n");
                printf("       Gracias por utilizar el sistema\n");
                printf("============================================\n");
                break;

            default:
                printf("\nOpcion no valida.\n");
                system("pause");
        }

    } while (op != 0);
}
