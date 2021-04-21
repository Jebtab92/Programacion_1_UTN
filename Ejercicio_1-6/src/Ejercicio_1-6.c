/*
 ============================================================================
 Name        : Ejercicio_1-6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pedirNumeros(int* numA, int* numB, int* numC);
int mayorNum(int numA, int numB, int numC, int* mayor);
int imprimir(int mayor);

int main(void) {
	setbuf(stdout, NULL);

	int numA, numB, numC, mayor;
	pedirNumeros(&numA, &numB, &numC);
	mayorNum(numA, numB, numC, &mayor);
	imprimir(mayor);

	return 0;
}
int pedirNumeros(int* numA, int* numB, int* numC)
{
	printf("Ingrese un numero --> ");
	scanf("%d", &*numA);

	printf("\nIngrese un numero --> ");
	scanf("%d", &*numB);

	printf("\nIngrese un numero --> ");
	scanf("%d", &*numC);

	return 0;
}
int mayorNum(int numA, int numB, int numC, int* mayor)
{
	if(numA > numB && numA > numC)
	{
		*mayor = numA;
	}
	else if(numB > numA && numB > numC)
	{
		*mayor = numB;
	}
	else
	{
		*mayor = numC;
	}
	return 0;
}
int imprimir(int mayor)
{
	printf("El mayor numero ingresado es: %d", mayor);
	return 0;
}
