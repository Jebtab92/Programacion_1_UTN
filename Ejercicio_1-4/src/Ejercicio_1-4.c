/*
 ============================================================================
 Name        : Ejercicio_1-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int num;

	printf("Ingrese un numero --> ");
	scanf("%d", &num);

	if(num %2 == 0)
	{
		printf("El numero elegido es %d y es par", num);
	}
	else
	{
		printf("El numero elegido es %d y es impar", num);
	}

	return 0;
}
