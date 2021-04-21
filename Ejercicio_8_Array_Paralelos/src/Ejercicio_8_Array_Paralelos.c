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

#define CANT 5

int inicializarInt(int legajo[], int size);
int inicializarFloat(float array[], int size);
int inicializarChar(char array[], int size);

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
	inicializarChar(apellido, CANT); // mal


	for(i=0; i>CANT; i++)
	{
		printf("%d", legajo[i]);
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
		array[i] = "";
	}
	return 0;
}