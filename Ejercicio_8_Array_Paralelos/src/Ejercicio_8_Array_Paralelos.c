/*
 ============================================================================
 Name        : Ejercicio_8_Array_Paralelos.c
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
#include "Ejercicio_8.h"

#define CANT 5

int main(void) {
	setbuf(stdout, NULL);

	int legajo[CANT];
	char sexo[CANT];
	int edad[CANT];
	float nota1[CANT];
	float nota2[CANT];
	float promedio[CANT];
	char apellido[CANT][20];
	int i = 0;
	int indice = 0;

	// Inicializo los array
	inicializarInt(legajo, CANT);
	inicializarInt(edad, CANT);
	inicializarFloat(nota1, CANT);
	inicializarFloat(nota2, CANT);
	inicializarFloat(promedio, CANT);
	inicializarChar(sexo, CANT);
	inicializarMatriz(apellido, CANT);


	do
	{
		// Solicito indice a completar
		printf("\nIngrese numero de orden de alumno para completar --> ");
		scanf("%d", &indice);

		// Llamo a la funcion para que los carge
		cargarLegajo(&legajo[indice], CANT);
		cargarSexo(&sexo[indice], CANT);
		cargarEdad(&edad[indice], CANT);
		cargarNotaUno(&nota1[indice], CANT);
		cargarNotaDos(&nota2[indice], CANT);
		cargarPromedio(&promedio[indice], nota1[indice], nota2[indice], CANT);
		cargarApellido(&apellido[indice], CANT);

		i = 5;

	}while(i<5);



	return 0;
}


