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

#define CANT 5

int inicializarInt(int legajo[], int size);
int inicializarFloat(float array[], int size);
int inicializarChar(char array[], int size);
int inicializarMatriz(char array[][20], int size);
int cargarLegajo(int legajo[], int size);
int cargarEdad(int edad[], int size);
int cargarSexo(char array[], int size);
int cargarNotaUno(float nota[],int size);
int cargarNotaDos(float nota[],int size);
int cargarApellido(char array[][20], int size);

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

	inicializarInt(legajo, CANT);
	inicializarInt(edad, CANT);
	inicializarFloat(nota1, CANT);
	inicializarFloat(nota2, CANT);
	inicializarFloat(promedio, CANT);
	inicializarChar(sexo, CANT);
	inicializarMatriz(apellido, CANT);


	for(i=0; i<CANT; i++)
	{
		printf("%s", apellido[i]);
	}

	return 0;
}
int inicializarInt(int array[], int size)
{
	int i = 0;

	for(i = 0; i < CANT; i++)
	{
		array[i] = 0;
	}
	return 0;
}

int inicializarFloat(float array[], int size)
{
	int i = 0;

	for(i = 0; i < CANT; i++)
	{
		array[i] = 0;
	}
	return 0;
}

int inicializarChar(char array[], int size)
{
	int i = 0;

	for(i = 0; i < CANT; i++)
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

int cargarApellido(char array[][20], int size)
{
	printf("\nIngrese su apellido");
	fflush(stdin);
	scanf("%s", array);
	return 0;
}





