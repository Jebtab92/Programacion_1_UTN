/*
 * Ejercicio_8.c
 *
 *  Created on: Apr 22, 2021
 *      Author: jonat
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int inicializarInt(int array[], int size)
{
	int i = 0;

	for(i = 0; i < size; i++)
	{
		array[i] = 0;
	}
	return 0;
}

int inicializarFloat(float array[], int size)
{
	int i = 0;

	for(i = 0; i < size; i++)
	{
		array[i] = 0;
	}
	return 0;
}

int inicializarChar(char array[], int size)
{
	int i = 0;

	for(i = 0; i < size; i++)
	{
		array[i] = ' ';
	}
	return 0;
}

int inicializarMatriz(char array[][20], int size)
{
	int i = 0;

	for(i = 0; i < size; i++)
	{
		strcpy(array[i], " ");
	}
	return 0;
}

int cargarLegajo(int legajo[], int size)
{
		printf("\nIngrese legajo --> ");
		scanf("%d", legajo);
	return 0;
}

int cargarEdad(int edad[], int size)
{
	printf("\nIngrese edad --> ");
	scanf("%d", edad);
	return 0;
}

int cargarSexo(char array[], int size)
{
	printf("\nIngrese sexo (f-femenino,m-masculino) --> ");
	fflush(stdin);
	scanf("%c", array);
	return 0;
}

int cargarNotaUno(float nota[], int size)
{
	printf("\nIngrese la nota #1 --> ");
	scanf("%f", nota);
	return 0;
}

int cargarNotaDos(float nota[], int size)
{
	printf("\nIngrese la nota #2 --> ");
	fflush(stdin);
	scanf("%f", nota);
	return 0;
}

int cargarPromedio(float promedio[], float nota1, float nota2, int size)
{
	float aux = 0;
	aux = nota1 + nota2;
	*promedio = (float)aux / 2;

	return 0;
}

int cargarApellido(char array[], int size)
{
	printf("\nIngrese su apellido --> ");
	fflush(stdin);
	gets(array);
	return 0;
}


int ordenarLegajo(int legajo[],char sexo[], float nota1[], float nota2[], float promedio[], char apellido[][20], int size)
{
	int i = 0;
	int j, legajoAux;
	float nota1Aux, nota2Aux, promAux;
	char sexoAux;
	char apellidoAux[20];

	for(i = 0; i < size - 1; i++)
	{
		for(j = i + 1; j < size; j++)
		{
			if(legajo[i] < legajo[j])
			{
				// Intercambio legajo
				legajoAux = legajo[i];
				legajo[i] = legajo[j];
				legajo[j] = legajoAux;

				// Intercambio sexo
				sexoAux = sexo[i];
				sexo[i] = sexo[j];
				sexo[j] = sexoAux;

				// Intercambio nota1
				nota1Aux = nota1[i];
				nota1[i] = nota1[j];
				nota1[j] = nota1Aux;

				// Intercambio nota2
				nota2Aux = nota2[i];
				nota2[i] = nota2[j];
				nota2[j] = nota2Aux;

				// Intercambio promedio
				promAux = promedio[i];
				promedio[i] = promedio[j];
				promedio[j] = promAux;

				// Intercambio apellido
				strcpy(apellidoAux,apellido[i]);
				strcpy(apellido[i],apellido[j]);
				strcpy(apellido[j], apellidoAux);
			}
		}
	}
	return 0;
}

int ordenarApellido()
{
	return 0;
}

int mostrarEstudiante(int legajo, char sexo, int edad, float nota1, float nota2, float promedio, char apellido[][20])
{
	printf("\n %d\t%c\t%d\t%.2f\t%.2f\t%.2f\t%s", legajo, sexo, edad, nota1, nota2, promedio, apellido[20]);
	return 0;
}

/*int mostrarEstudiantes(int legajo[], char sexo[], int edad[], float nota1[], float nota2[], float promedio[],
		char apellido[][20], int size)
{
	int i = 0;

	for(i = 0; i < size; i++)
	{
		mostrarEstudiante(int legajo[i], char sexo[i], int edad[i], float nota1[i], float nota2[i], float promedio[i], char apellido[i][20]);
	}
	return 0;
}
*/

