/*
 ============================================================================
 Name        : Estructuras.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declaracion Estructuras
struct datosPersonales
{
	char nombre[20];
	char apellido[20];
	char calle[20];
	int numero;

};

// Otra forma

typedef struct
{
	char nombre[20];
	char apellido[20];
	char calle[20];
	int numero;
}datosPersonales2;

// anidar

struct notas
{
	int nota;
	struct datosPersonales;
};

int main(void) {

	// para struct
	struct datosPersonales agenda;
	struct datosPersonales agendas[3], contactos[3], amigos[3];

	// para typedef struct
	datosPersonales2 agenda2;

	// Array de struct
	struct datosPersonales lista[3];
	// Para ver lista[1].apellido


	// Ingresar datos con operador . (punto)
	agenda.numero = 750;
	strcpy(agenda.nombre, "Jonatan");
	strcpy(agenda.apellido, "Barbuto");
	strcpy(agenda.calle, "Caxaraville");

	// Anidar estructuras declaro dos
	// Inicializamos isEmpty en 1



	return 0;
}
