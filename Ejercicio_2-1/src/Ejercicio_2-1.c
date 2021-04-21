/*
 ============================================================================
 Name        : Ejercicio_2-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANT 5

int pedirNumero(int num[], int size);
int get_Promedio(int num[], float* promedio, int size);
int mostrarResultado(float promedio);

int main(void) {

	setbuf(stdout, NULL);

	int num[CANT];
	float promedio;

	pedirNumero(num, CANT);
	get_Promedio(num, &promedio, CANT);
	mostrarResultado(promedio);


	return 0;
}
int pedirNumero(int num[], int size)
{
	int i = 0;
	for(i=0; i < size;i++)
	{
		printf("\nIngrese un numero -->");
		scanf("%d", &num[i]);
	}
	return 0;
}
int get_Promedio(int num[], float* promedio, int size)
{
	int i = 0;
	int sum = 0;

	for(i=0; i < size; i++)
	{
		sum = sum + num[i];
	}

	*promedio = (float)sum / size;

	return 0;
}
int mostrarResultado(float promedio)
{
	printf("El promedio de los numeros ingresados es %.2f\n", promedio);
	printf("\tAdios");
	return 0;
}
