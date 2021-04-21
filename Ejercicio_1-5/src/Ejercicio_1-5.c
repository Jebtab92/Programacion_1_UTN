/*
 ============================================================================
 Name        : Ejercicio_1-5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pedirNumero(int* numA, int* numB);
int sumar(int numA, int numB, int* sum);
int imprimir(int sum);

int main(void) {
	setbuf(stdout, NULL);
	int numA, numB, sum;

	pedirNumero(&numA, &numB);
	sumar(numA, numB, &sum);
	imprimir(sum);

	return 0;
}
int pedirNumero(int* numA, int* numB)
{
	printf("Ingrese un numero --> ");
	scanf("%d", &*numA);

	printf("\nIngrese un numero --> ");
	scanf("%d", &*numB);

	return 0;
}

int sumar(int numA, int numB, int* sum)
{
	*sum = numA + numB;
	return 0;
}

int imprimir(int sum)
{
	printf("La suma de los numeros es: %d", sum);
	return 0;
}
