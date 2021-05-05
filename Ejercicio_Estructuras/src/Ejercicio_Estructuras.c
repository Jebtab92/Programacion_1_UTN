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
	do
	{
		mostrarMenu(&opcion);
		switch(opcion)
		{
			case 1:
			{
				ingresarAlumno(arrayAlumnos, CANT);
				break;
			}
			case 2:
			{
				if(bajaAlumno(arrayAlumnos, CANT) == 0)
				{
					printf("\nAlumno eliminado");
				}
				else
				{
					printf("\nNo se encontro el legajo");
				}
				break;
			}
			case 3:
			{
				break;
			}
			case 4:
			{
				listarAlumnos(arrayAlumnos, CANT);
				break;
			}
			case 5:
			{
				break;
			}
			case 6:
			{
				printf("--Nos vemos--");
				break;
			}
		}

	}while(opcion != 6);

	return 0;
}
