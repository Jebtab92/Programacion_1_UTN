/*
 ============================================================================
 Name        : Ejercicio_10.c
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

typedef struct
{
	char calle[50];
	int numero;
	int isEmpty;
}eDireccion;

typedef struct
{
	int idProducto;
	char descripcion[50];
	float precio;
	int isEmpty;
}Producto;

typedef struct
{
	int idProveedor;
	char razonSocial[50];
	eDireccion direccion;
	int isEmpty;
}Proveedor;

int main(void) {
	setbuf(stdout, NULL);


	return 0;
}
