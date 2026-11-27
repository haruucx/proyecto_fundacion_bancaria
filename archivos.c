#include <stdio.h>
#include <string.h>
#include "archivos.h"
#include "funciones.h"

int leerCampo(FILE *archivo, char destino[], int tam) {
    char linea[200];
    int i, largo;

    if (fgets(linea, 200, archivo) == NULL) {
        return 0;
    }

    largo = strlen(linea);

    while (largo > 0 && (linea[largo - 1] == '\n' || linea[largo - 1] == '\r')) {
        largo--;
        linea[largo] = '\0';
    }

    if (largo == 0 || largo >= tam) {
        return -1;
    }

    for (i = 0; i <= largo; i++) {
        destino[i] = linea[i];
    }

    return 1;
}

int existeMunicipio(char codigo[]) {
    char cod[10], nombre[40], departamento[10];
    int encontrado = 0;
    FILE *archivo = fopen("municipios.txt", "r");

    if (archivo == NULL) {
        return -1;
    }

    while (leerCampo(archivo, cod, 10) == 1 &&
           leerCampo(archivo, nombre, 40) == 1 &&
           leerCampo(archivo, departamento, 10) == 1) {
        if (iguales(cod, codigo)) {
            encontrado = 1;
        }
    }

    fclose(archivo);
    return encontrado;
}

void mostrarMunicipios() {
    char cod[10], nombre[40], departamento[10];
    FILE *archivo = fopen("municipios.txt", "r");

    if (archivo == NULL) {
        return;
    }

    while (leerCampo(archivo, cod, 10) == 1 &&
           leerCampo(archivo, nombre, 40) == 1 &&
           leerCampo(archivo, departamento, 10) == 1) {
        printf("%s. %s\n", cod, nombre);
    }

    fclose(archivo);
}

int leerMunicipio(char destino[]) {
    int existe;

    mostrarMunicipios();

    do {
        leerNumero("Ingrese el codigo del municipio: ", destino, 10);
        existe = existeMunicipio(destino);
        if (existe == 0) {
            printf("El municipio no existe.\n");
        }
    } while (existe == 0);

    if (existe == -1) {
        printf("No se pudo abrir municipios.txt\n");
        return 0;
    }

    return 1;
}

int cargarPersonas(struct Persona v[]) {
    struct Persona p;
    int n = 0;
    int estado;
    FILE *archivo = fopen("personas.txt", "r");

    if (archivo == NULL) {
        return 0;
    }

    estado = leerCampo(archivo, p.cedula, 20);

    while (estado == 1) {
        if (n == MAX ||
            leerCampo(archivo, p.nombre, 60) != 1 ||
            leerCampo(archivo, p.municipio, 10) != 1 ||
            leerCampo(archivo, p.telefono, 20) != 1) {
            estado = -1;
        } else {
            v[n] = p;
            n++;
            estado = leerCampo(archivo, p.cedula, 20);
        }
    }

    fclose(archivo);

    if (estado == -1) {
        return -1;
    }

    return n;
}

void agregarPersona(struct Persona p) {
    FILE *archivo = fopen("personas.txt", "a");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "%s\n%s\n%s\n%s\n",
            p.cedula, p.nombre, p.municipio, p.telefono);
    fclose(archivo);
    printf("Persona registrada.\n");
}

void guardarPersonas(struct Persona v[], int n) {
    int i;
    FILE *archivo = fopen("personas.txt", "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        fprintf(archivo, "%s\n%s\n%s\n%s\n",
                v[i].cedula, v[i].nombre, v[i].municipio, v[i].telefono);
    }

    fclose(archivo);
    printf("Persona modificada.\n");
}

int cargarEntidades(struct Entidad v[]) {
    struct Entidad e;
    int n = 0;
    int estado;
    FILE *archivo = fopen("entidades.txt", "r");

    if (archivo == NULL) {
        return 0;
    }

    estado = leerCampo(archivo, e.nit, 20);

    while (estado == 1) {
        if (n == MAX ||
            leerCampo(archivo, e.nombre, 60) != 1 ||
            leerCampo(archivo, e.municipio, 10) != 1 ||
            leerCampo(archivo, e.tipoAyuda, 50) != 1 ||
            leerCampo(archivo, e.representante, 60) != 1) {
            estado = -1;
        } else {
            v[n] = e;
            n++;
            estado = leerCampo(archivo, e.nit, 20);
        }
    }

    fclose(archivo);

    if (estado == -1) {
        return -1;
    }

    return n;
}

void agregarEntidad(struct Entidad e) {
    FILE *archivo = fopen("entidades.txt", "a");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "%s\n%s\n%s\n%s\n%s\n",
            e.nit, e.nombre, e.municipio, e.tipoAyuda, e.representante);
    fclose(archivo);
    printf("Entidad registrada.\n");
}

void guardarEntidades(struct Entidad v[], int n) {
    int i;
    FILE *archivo = fopen("entidades.txt", "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        fprintf(archivo, "%s\n%s\n%s\n%s\n%s\n",
                v[i].nit, v[i].nombre, v[i].municipio,
                v[i].tipoAyuda, v[i].representante);
    }

    fclose(archivo);
    printf("Entidad modificada.\n");
}
