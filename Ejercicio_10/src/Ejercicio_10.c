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

// Producto Proveedor
typedef struct
{
	char calle[50];
	int numero;
	char localidad[20];
	int isEmpty;
}eDireccion;

typedef struct
{
	int idProducto;
	int idProveedor; // Foreign Key
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






// Dueño Mascota
typedef struct
{
	int idRaza;
	char nombreRaza[20];
	int isEmpty;
}eRaza;

typedef struct
{
	int idOwner;
	char nombre[20];
	int edad;
	char sexo;
	int isEmpty;
}Owner;

typedef struct
{
	int idMascota;
	int idOwner; // Foreign Key
	char nombre[20];
	eRaza raza;
	char sexo;
	int isEmpty;
}Mascota;









// Alumno Localidad
typedef struct
{
	int idAlumno;
	char nombre[20];
	int idLocalidad; // Foreign Key
	int isEmpty;
}Alumno;

typedef struct
{
	int idLocalidad;
	char descripcion[20];
	int codigoPostal;
	int isEmpty;
}Localidad;


int main(void) {
	setbuf(stdout, NULL);


	return 0;
}
