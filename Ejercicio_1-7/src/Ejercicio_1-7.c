/*
 ============================================================================
 Name        : Ejercicio_1-7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pedirNumeros(int* numA, int* numB, int* numC);
int buscarMedio(int numA, int numB, int numC, int* medio, int* flagMedio);
int mostrarResultado(int result, int flag);

int main(void) {
	setbuf(stdout, NULL);

	int numA, numB, numC, medio;
	int flagMedio = 0;
	pedirNumeros(&numA, &numB, &numC);
	buscarMedio(numA, numB, numC, &medio, &flagMedio);
	mostrarResultado(medio, flagMedio);

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
int buscarMedio(int numA, int numB, int numC, int* medio, int* flagMedio)
{
    if ((numA>numB && numA<numC)||(numA<numB && numA>numC))
    {
        *medio = numA;
    }
    else if ((numB>numA && numB<numC)||(numB<numA && numB>numC))
    {
        *medio = numB;
    }
    else if ((numC>numA && numC<numB)||(numC<numA && numC>numB))
    {
        *medio = numC;
    }
    else
    {
        *flagMedio = 1;
    }
	return 0;
}
int mostrarResultado(int result, int flag)
{
	if(flag == 1)
	{
		printf("No hay numero del medio");
	}
	else
	{
		printf("El numero del medio es %d", result);
	}
	return 0;
}
