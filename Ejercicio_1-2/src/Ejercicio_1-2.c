/*
 ============================================================================
 Name        : Ejercicio_1-2.c
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

	// Declaro mi variable
	int num;

	// Pido por consola mi numero
	printf("Ingrese un numero -->  ");
	scanf("%d", &num);

	// Imprimo numero con 10% de descuento
	printf("Su nuevo sueldo es --> %.2f", (float)num*1.1);

	return 0;
}
