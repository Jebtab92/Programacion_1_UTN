/*
 ============================================================================
 Name        : prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	char nombre[20]={"PEDRO"};

	nombre = tolower(nombre[0]);

	printf("%s", nombre);

	return 0;
}
