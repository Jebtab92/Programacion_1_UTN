/*
 ============================================================================
 Name        : Clase_5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Array

int main(void) {
	setbuf(stdout, NULL);
	int nota[5];
	int i = 0;

	for(i = 0; i < 5; i++)
	{
		printf("Ingrese un numero");
		scanf("%d", &nota[i]);
	}

	for(i = 0; i < 5; i++)
	{
		printf("Nota %d: %d", i + 1, nota[i]);
	}

	return 0;
}
