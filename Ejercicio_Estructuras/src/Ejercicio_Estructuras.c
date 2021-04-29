/*
 ============================================================================
 Name        : Ejercicio_Estructuras.c
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
#include "biblioteca_estructuras.h"

#define CANT 5



int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	alumno arrayAlumnos[CANT];


	inicializarIsEmpty(arrayAlumnos, CANT);
	//mostrarMenu();
	listarAlumnos(arrayAlumnos, CANT);



	return 0;
}
