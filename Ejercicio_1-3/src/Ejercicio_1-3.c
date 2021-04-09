/*
 ============================================================================
 Name        : Ejercicio_1-3.c
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

	int edad;
	char estado;

	printf("Ingrese su edad --> ");
	scanf("%d", &edad);

	printf("Ingrese estado civil\n"
			"c-casado\n"
			"s-soltero\n"
			"v-viudo\n"
			"d-divorciado\n");
	fflush(stdin);
	scanf("%c", &estado);

	if(edad < 18 && estado != 's')
	{
		printf("Es muy pequeño para no ser soltero");
	}
	else
	{
		printf("Excelente");
	}


	return 0;
}
