/*
 ============================================================================
 Name        : Ejercicio_2-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANT 4

int pedirNumero(int num[], int size);
int get_ParImpar(int num[], int size, int* countPar, int* countImpar);
int get_Menor(int num[], int size, int* menor);
int get_MayorPar(int num[], int size, int* mayorPar);
int get_Sum(int num[], int size, int* sumaPos);
int get_Prod(int num[], int size, int* prodNeg);
int mostrarResultado(int countPar, int countImpar, int menor, int mayorPar, int sumaPos, int prodNeg);

int main(void) {
	setbuf(stdout, NULL);

	int num[CANT];
	int countPar = 0;
	int countImpar = 0;
	int menor, mayorPar, sumaPos, prodNeg;

	pedirNumero(num, CANT);
	get_ParImpar(num, CANT, &countPar, &countImpar);
	get_Menor(num, CANT, &menor);
	get_MayorPar(num, CANT, &mayorPar);
	get_Sum(num, CANT, &sumaPos);
	get_Prod(num, CANT, &prodNeg);
	mostrarResultado(countPar, countImpar, menor, mayorPar, sumaPos, prodNeg);
	return 0;
}
int pedirNumero(int num[], int size)
{
	int i = 0;
	for(i=0; i<size; i++)
	{
		printf("\nIngrese un numero --> ");
		scanf("%d", &num[i]);
	}
	return 0;
}
int get_ParImpar(int num[], int size, int* countPar, int* countImpar)
{
	int i = 0;
	for(i=0; i<size;i++)
	{
		if(num[i] %2 == 0)
		{
			*countPar += 1;
		}
		else
		{
			*countImpar += 1;
		}
	}
	return 0;
}
int get_Menor(int num[], int size, int* menor)
{
	int aux = num[0];
	int i = 0;
	for(i=0;i < size; i++)
	{
		if(num[i] < aux)
		{
			aux = num[i];
		}
	}
	*menor = aux;
	return 0;
}
int get_MayorPar(int num[], int size, int* mayorPar)
{
	int i = 0;
	int flag = 0;
	int aux;
	for(i=0; i < size; i++)
	{
		if(num[i] %2 == 0 && flag == 0)
		{
			aux = num[i];
			flag = 1;
		}
		if(num[i] %2 == 0 && flag == 1)
		{
			if(num[i] > aux)
			{
				aux = num[i];
			}
		}
	}
	*mayorPar = aux;
	return 0;
}
int get_Sum(int num[], int size, int* sumaPos)
{
	int i = 0;
	int aux = 0;
	for(i=0; i < size; i++)
	{
		if(num[i] > 0)
		{
			aux += num[i];
		}
	}
	*sumaPos = aux;
	return 0;
}
int get_Prod(int num[], int size, int* prodNeg)
{
	int i = 0;
	int aux = 1;
	for(i=0; i < size; i++)
	{
		if(num[i] < 0)
		{
			aux *= num[i];
		}
	}
	*prodNeg = aux;
	return 0;
}
int mostrarResultado(int countPar, int countImpar, int menor, int mayorPar, int sumaPos, int prodNeg)
{
	printf("a. La cantidad de numeros pares es --> %d e impares es --> %d\n", countPar, countImpar);
	printf("b. El menor numero ingresado es --> %d\n", menor);
	printf("c. El mayor numero par es --> %d\n", mayorPar);
	printf("d. La suma de los numeros positivos es --> %d\n", sumaPos);
	printf("e. El producto de los negativos es --> %d", prodNeg);
	printf("\t --Chau--");
	return 0;
}
