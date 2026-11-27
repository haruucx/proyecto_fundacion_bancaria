PROYECTO FUNDACION COLOMBIA SOLIDARIA
Version funcional inicial: personas y empresas.

ARCHIVOS:
- main.c: inicio del programa.
- estructuras.h: estructuras de datos.
- funciones.h / funciones.c: menus, captura y validaciones.
- archivos.h / archivos.c: busqueda, lectura y escritura.
- municipios.txt: catalogo inicial para validar municipios.

COMPILAR CON GCC:
gcc -Wall -Wextra -std=c11 main.c funciones.c archivos.c -o ProyectoFinal

EJECUTAR EN WINDOWS:
ProyectoFinal.exe

EJECUTAR EN LINUX:
./ProyectoFinal

IMPORTANTE:
Ejecuta el programa desde esta misma carpeta para que encuentre los .txt.
Los registros se guardan en personas.txt y empresas.txt automaticamente.
Puedes editar municipios.txt. Su formato es:
codigo|nombre|codigo_departamento

ESTA VERSION INCLUYE:
- Registro de personas y empresas.
- Validacion de cedulas y NIT numericos y no repetidos.
- Validacion de campos obligatorios.
- Validacion de municipio existente.
- Listado de personas y empresas.
- Persistencia en archivos de texto.

TODAVIA NO INCLUYE:
- Modificacion o eliminacion de personas/empresas.
- Login y perfiles.
- Departamentos/municipios administrables desde menu.
- Donaciones, entregas e informes financieros.
