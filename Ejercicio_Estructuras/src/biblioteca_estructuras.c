/*
 * biblioteca_estructuras.c
 *
 *  Created on: Apr 28, 2021
 *      Author: jonat
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca_estructuras.h"
/*
 *\brief
 *\param
 *\return
 */
int mostrarMenu()
{
	printf("\n--Menu Principal--");
	printf("\nIngrese la opcion deseada");
	printf("\n1-Alta de nuevo alumno");
	printf("\n2-Baja de un alumno");
	printf("\n3-Modificacion de alumno");
	printf("\n4-Listar alumnos");
	printf("\n5-Ordenar alumnos");
	printf("\n6-Salir");
	return 0;
}

/*
 *\brief
 *\param
 *\return
 */
int inicializarIsEmpty(alumno alumnos[], int size)
{
	int i = 0;
	int retorno = -1;
	if(alumnos != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			alumnos[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

/*
 *\brief
 *\param
 *\return
 */
int buscarLibre(alumno array[], int size)
{
	int aux = 0;

	if(array != NULL && size > 0)
	{

	}
	do
	{

	}while(aux == 1);
	return 0;
}

/*
 *\brief
 *\param
 *\return
 */
int listarAlumno(alumno array[])
{
	//printf("%d",array[].isEmpty);
	return 0;
}

/*
 *
 *
 */
int listarAlumnos(alumno array[], int size)
{
	int i = 0;
	for(i = 0; i < size; i++)
	{
		printf("%d", array[i].isEmpty);
	}
	return 0;
}

/*
 *\brief
 *\param
 *\return
 */
int bajaAlumno()
{

	return 0;
}

/*
 *\brief
 *\param
 *\return
 */
int modificarAlumno()
{

	return 0;
}

/*
 *\brief
 *\param
 *\return
 */
int ordenarAlumno()
{

	return 0;
}

























