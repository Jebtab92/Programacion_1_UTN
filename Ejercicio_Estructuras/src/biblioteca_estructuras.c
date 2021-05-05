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
int mostrarMenu(int* opcion)
{
	printf("\n--Menu Principal--");
	printf("\nIngrese la opcion deseada");
	printf("\n1-Alta de nuevo alumno");
	printf("\n2-Baja de un alumno");
	printf("\n3-Modificacion de alumno");
	printf("\n4-Listar alumnos");
	printf("\n5-Ordenar alumnos");
	printf("\n6-Salir\n");
	scanf("%d", &*opcion);
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
	int retorno = -1;
	int i = 0;

	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			if(array[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}

/*
 *\brief
 *\param
 *\return
 */
int ingresarAlumno(alumno array[], int size)
 {
	int posicion;
	posicion = buscarLibre(array, size);
	if (array != NULL && size > 0 && posicion != -1)
	{

		// Legajo
		printf("\nIngrese legajo --> ");
		scanf("%d", &array[posicion].legajo);

		// Edad

		printf("\nIngrese edad --> ");
		scanf("%d", &array[posicion].edad);

		// Sexo
		do
		{
			printf("\nIngrese sexo (f-femenino,m-masculino) --> ");
			fflush(stdin);
			scanf("%c", &array[posicion].sexo);
		}while(array[posicion].sexo != 'f' || array[posicion].sexo !='m');

		// Nota1
		printf("\nIngrese la nota #1 --> ");
		scanf("%f", &array[posicion].nota1);

		// Nota2
		printf("\nIngrese la nota #2 --> ");
		fflush(stdin);
		scanf("%f", &array[posicion].nota2);

		// Promedio
		float aux = 0;
		aux = array[posicion].nota1 + array[posicion].nota2;
		array[posicion].promedio = (float) aux / 2;

		// Apellido
		printf("\nIngrese su apellido --> ");
		fflush(stdin);
		gets(array[posicion].apellido);

		// isEmpty
		array[posicion].isEmpty = 0;

	}




	return 0;
}


/*
 *\brief
 *\param
 *\return
 */
int listarAlumno(int legajo, char sexo, int edad, float nota1, float nota2, char* apellido)
{
	printf("\n%d\t%c\t%d\t%.2f\t%.2f\t%.2f\t%s\n",
							legajo,
							sexo,
							edad,
							nota1,
							nota2,
							apellido
							);
	return 0;
}

/*
 *
 *
 */
int listarAlumnos(alumno array[], int size)
{
	int i = 0;
	if(array != NULL && size > 0)
	{
		printf("\nLegajo\tSexo\tEdad\tNota1\tNota2\tPromedio\tApellido\n");
		for(i = 0; i < size; i++)
		{
			if(array[i].isEmpty == 0)
			{
				listarAlumno(array[i].legajo,
							array[i].sexo,
							array[i].edad,
							array[i].nota1,
							array[i].nota2,
							array[i].apellido);
			}

		}
	}
	return 0;
}

/*
 *\brief
 *\param
 *\return
 */
int bajaAlumno(alumno array[], int size)
{
	int auxEliminar;
	int i;
	int retorno = -1;

	if(array != NULL && size > 0)
	{
		printf("\nIngrese legajo a eliminar");
		scanf("%d", &auxEliminar);
		for(i = 0; i < size; i++)
		{
			if(auxEliminar == array[i].legajo)
			{
				// Falta mostrar el alumno a eliminar
				array[i].isEmpty = 1;
				retorno = 0;
			}
		}
	}

	return retorno;
}

/*
 *\brief
 *\param
 *\return
 */
int modificarAlumno(alumno array[], int size)
{
	if(array != NULL && size > 0)
	{

	}

	return 0;
}

/*
 *\brief
 *\param
 *\return
 */
int ordenarAlumno(alumno array[], int size)
{
	if(array != NULL && size > 0)
	{

	}
	return 0;
}
int buscarLegajo(alumno array[], int size)
{

	int retorno = -1;
	if(array != NULL && size > 0)
	{
		printf("\nIngrese Legajo\n");
		scanf("%d", &*auxLegajo);
		retorno = 0;
	}

	return retorno;
}

























