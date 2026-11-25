#include <stdio.h>
#include <string.h>
#include "archivos.h"

int buscarPersona(char cedula[]){
    struct Persona p;
    FILE *arch;
    arch = fopen("personas.txt", "r");

    if ( arch == NULL) {
        return 0;
    }

    while(fscanf(arch, "%19[^|]|%59[^|]|%d|%19[^\n]\n",
                p.cedula, p.nombre, 
                &p.municipio, p.telefono) == 4) {
                
                    if(strcmp(p.cedula, cedula)==0){
                        fclose(arch);
                        return 1;
                    }
                }
    fclose(arch);
    return 0;
}

void guardarPersona(struct Persona p) {
    FILE *arch;

    arch = fopen("personas.txt", "a");
    if (arch == NULL){
        printf("\n-- Error al abrir el archivo --\n");
        return;
    }

    fprintf(arch, "%s\t|\t%s\t|\t%d\t|\t%s\n",
            p.cedula, p.nombre,
            p.municipio, p.telefono);

    fclose(arch);

    printf("\n\t-- Persona registrada correctamente --\n");
}