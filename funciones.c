#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "funciones.h"
#include "archivos.h"

void limpiar(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void pausa(void) {
    printf("\nPresione ENTER para continuar...");
    getchar();
}

int soloNumeros(char texto[]) {
    int i;

    if (texto[0] == '\0') return 0;

    for (i = 0; texto[i] != '\0'; i++) {
        if (!isdigit((unsigned char)texto[i])) return 0;
    }

    return 1;
}

static void leerTexto(char mensaje[], char destino[], int tam) {
    size_t n;

    printf("%s", mensaje);
    if (fgets(destino, tam, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }

    n = strlen(destino);
    if (n > 0 && destino[n - 1] == '\n') {
        destino[n - 1] = '\0';
    } else {
        limpiar();
    }
}

static int leerCodigo(char mensaje[]) {
    char texto[30];

    leerTexto(mensaje, texto, sizeof(texto));
    if (!soloNumeros(texto)) return -1;
    return atoi(texto);
}

void registrarPersona(void) {
    struct Persona p;

    printf("\n--- REGISTRO DE PERSONA ---\n");
    leerTexto("Cedula: ", p.cedula, sizeof(p.cedula));

    if (!soloNumeros(p.cedula)) {
        printf("Error: la cedula debe contener solamente numeros.\n");
        return;
    }

    if (buscarPersona(p.cedula)) {
        printf("Error: esa cedula ya esta registrada.\n");
        return;
    }

    leerTexto("Nombre completo: ", p.nombre, sizeof(p.nombre));
    if (p.nombre[0] == '\0' || strchr(p.nombre, '|') != NULL) {
        printf("Error: el nombre no puede estar vacio ni contener |.\n");
        return;
    }

    p.municipio = leerCodigo("Codigo del municipio: ");
    if (p.municipio <= 0 || !existeMunicipio(p.municipio)) {
        printf("Error: el municipio no existe. Revise municipios.txt.\n");
        return;
    }

    leerTexto("Telefono: ", p.telefono, sizeof(p.telefono));
    if (!soloNumeros(p.telefono)) {
        printf("Error: el telefono debe contener solamente numeros.\n");
        return;
    }

    guardarPersona(p);
}

void registrarEmpresa(void) {
    struct Empresa e;

    printf("\n--- REGISTRO DE EMPRESA ---\n");
    leerTexto("NIT: ", e.nit, sizeof(e.nit));

    if (!soloNumeros(e.nit)) {
        printf("Error: el NIT debe contener solamente numeros.\n");
        return;
    }

    if (buscarEmpresa(e.nit)) {
        printf("Error: ese NIT ya esta registrado.\n");
        return;
    }

    leerTexto("Razon social: ", e.nombre, sizeof(e.nombre));
    if (e.nombre[0] == '\0' || strchr(e.nombre, '|') != NULL) {
        printf("Error: la razon social no puede estar vacia ni contener |.\n");
        return;
    }

    leerTexto("Sector economico: ", e.sector, sizeof(e.sector));
    if (e.sector[0] == '\0' || strchr(e.sector, '|') != NULL) {
        printf("Error: el sector no puede estar vacio ni contener |.\n");
        return;
    }

    e.municipio = leerCodigo("Codigo del municipio: ");
    if (e.municipio <= 0 || !existeMunicipio(e.municipio)) {
        printf("Error: el municipio no existe. Revise municipios.txt.\n");
        return;
    }

    guardarEmpresa(e);
}

void menuAdministrador(void) {
    int op = -1;

    while (op != 0) {
        printf("\n========== ADMINISTRADOR ==========\n");
        printf("1. Registrar persona\n");
        printf("2. Listar personas\n");
        printf("3. Registrar empresa\n");
        printf("4. Listar empresas\n");
        printf("0. Regresar\n");
        printf("Seleccione: ");

        if (scanf("%d", &op) != 1) {
            limpiar();
            op = -1;
            printf("Opcion invalida.\n");
            continue;
        }
        limpiar();

        switch (op) {
            case 1:
                registrarPersona();
                pausa();
                break;
            case 2:
                listarPersonas();
                pausa();
                break;
            case 3:
                registrarEmpresa();
                pausa();
                break;
            case 4:
                listarEmpresas();
                pausa();
                break;
            case 0:
                break;
            default:
                printf("Opcion incorrecta.\n");
                pausa();
        }
    }
}

void menuPrincipal(void) {
    int op = -1;

    while (op != 0) {
        printf("\n====================================\n");
        printf("     FUNDACION COLOMBIA SOLIDARIA\n");
        printf("====================================\n");
        printf("1. Administrador\n");
        printf("0. Salir\n");
        printf("Seleccione: ");

        if (scanf("%d", &op) != 1) {
            limpiar();
            op = -1;
            printf("Opcion invalida.\n");
            continue;
        }
        limpiar();

        switch (op) {
            case 1:
                menuAdministrador();
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion incorrecta.\n");
                pausa();
        }
    }
}
